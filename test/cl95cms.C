/* --------------------------------------------------------------------------------
 Bayesian 95% CL limit and expected (average) 95% CL limit calculator for cross-section with Poisson statistics

 The code should be run from root in the compiled mode:

.L cl95cms.c++

 Usage to get actual and expected limit respectively:
        sigma95 = CL95(ilum, slum, eff, seff, bck, sbck, n, gauss = false, nuisanceModel = 0)
        sigma95A = CLA(ilum, slum, eff, seff, bck, sbck, nuisanceModel = 0)

 Inputs:        ilum - Nominal integrated luminosity (pb^-1)
                slum - Absolute error on the integrated luminosity
                eff  - Nominal value of the efficiency times acceptance (in range 0 to 1)
                seff - Absolute error on the efficiency times acceptance
                bck  - Nominal value of the background estimate
                sbck - Absolute error on the background
                n    - Number of observed events (not used for the expected limit)
                gauss - if true, use Gaussian statistics for signal instead of Poisson; automatically false for n = 0. Always false for expected limit calculations
                nuisanceModel - distribution function used in integration over nuisance parameters:
                                0 - Gaussian, 1 - lognormal, 2 - gamma; (automatically 0 when gauss == true)

 Limits should be obtained & compared for each allowed value of the nuisanceModel parameter. The justification for doing this is given in
 http://www.physics.ucla.edu/~cousins/stats/cousins_lognormal_prior.pdf

 A flat prior is assumed for the cross-section.

 Written  by Greg Landsberg; v1.0 February 27, 2003
 Modified by Greg Landsberg; v1.1 March 18, 2003 - some bugs fixed;
 automatic graph scaling
 Modified by Greg Landsberg; v1.2 May 15, 2003   - clean-up of the code
 Modified by Greg Landsberg; v1.3 June 2, 2005   - further clean-up;
                                                                                                   protection against numeric instability;
                                                                                                   increased table for Poisson distribution;
 Modified by Greg Landsberg; v1.3 June 2, 2010   - lognormal and Gamma nuisance
                                                                                                   parameter integration
-------------------------------------------------------------------------------- */
#include <iostream>
#include <stdlib.h>
#include "TMath.h"
#include "TF1.h"
#include "TH1.h"
#include "TArrow.h"
#include "TCanvas.h"
using namespace std;

static Double_t A0, sA, B0, sB, epsilon, MaxSig = 100.;
static Double_t MinLike = 1.e-6, Precision = 1.e-5;
static Int_t N;
static bool lGauss = kFALSE, plot = kTRUE;
static Int_t I = 0;
static Double_t sigma_a = 0., sigma_b = 0., tau_a = 0., tau_b = 0.;

Double_t Likelihood(Double_t *x, Double_t *p);
Double_t Inner(Double_t *x, Double_t *par);
Double_t Outer(Double_t *x, Double_t *p);
Double_t Poisson(Double_t Mu, Int_t n);
Double_t CL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss = kFALSE, Int_t nuisanceModel = 0);
Double_t CLA(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Bool_t gauss = kFALSE, Int_t bckint = 0);

Double_t CL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss, Int_t nuisanceModel)
{
        Double_t xmax = MaxSig;
        Double_t x[1], p[1];

        // Get the nominal values of input (nuisance) parameters and their uncertainties.
        A0 = ilum*eff;
        sA = sqrt(ilum*seff*ilum*seff + eff*slum*eff*slum);
        B0 = bck;
        sB = sbck;
        epsilon = TMath::Max(Precision/ilum,1.e-4);
        //
        lGauss = gauss;
        if (n == 0) lGauss = kFALSE;

        // If using logNormal or gamma functions for nuisance parameters, must express these parameters in the way expected
        // by the ROOT implementations of these functions. (See web page given above for details).
        if (!gauss)
        {
                if (nuisanceModel < 0 || nuisanceModel > 2)
                {
                        cout << "Incorrect nuissance parameter integration model. Gaussian will be used." << endl;
                        nuisanceModel = 0;
                }
                if (plot) cout << "Poisson 95% CL limit with ";
                I = nuisanceModel;
                if (nuisanceModel == 0)
                {
                        if (plot) cout << "Gaussian ";
                }
                else if (nuisanceModel == 1) // Lognormal distribution is used
                {
                        if (B0 > 0) sigma_b = TMath::Log(1. + sB/B0);
                        sigma_a = TMath::Log(1. + sA/A0);
                        if (plot) cout << "Lognormal ";
                }
                else if (nuisanceModel == 2) // Gamma distribution is used
                {
                        if (plot) cout << "Gamma ";
                        if (sA > 0)
                        {
                                sigma_a = 1. + A0*A0/sA/sA;
                                tau_a = A0/sA/sA;
                        }
                        if (sB > 0)
                        {
                                sigma_b = 1. + B0*B0/sB/sB;
                                tau_b = B0/sB/sB;
                        }
                }
        } else if (plot) cout << "Gaussian 95% CL limit with Gaussian ";
        if (plot) cout << "nuisance parameter integration will be used" << endl;


        // Do some iteration to determine in which cross-section range 0 to xmax the likelihood function is sufficiently
        // large to be of interest.
        N = n;
        x[0] = xmax;
        p[0] = 0.;
        //
        Double_t delta = (Likelihood(x,p) - MinLike)/MinLike;
        while (delta > 0)
        {
                if (plot) cout << "delta = " << delta << endl;

                xmax = 2.*xmax;
                x[0] = xmax;
                delta = (Likelihood(x,p) - MinLike)/MinLike;
        }
        //
        Double_t x1 = 0, x2 = xmax;
        while (fabs(delta) > epsilon)
        {
                if (delta > 0) x1 = x[0];
                else x2 = x[0];
                x[0] = (x1 + x2)/2.;
                delta = (Likelihood(x,p) - MinLike)/MinLike;
        }
        xmax = x[0];
        //
        Int_t i = 0;
        if (xmax > 1)
        {
                while (xmax > 10.)
                {
                        xmax /= 10.;
                        i++;
                }
                xmax = (Int_t)(xmax + 1)*pow(10,i);
        }
        else
        {
                while (xmax < 1.)
                {
                        xmax *= 10.;
                        i++;
                }
                xmax = (Int_t)(xmax + 1)*pow(10,-i);
        }

        // Calculate the likelood function as a function of the cross-section
        TF1 like("Likelihood",Likelihood,0.,xmax,0);
        if (plot) cout << "Likelihood function is evaluated over [0," << xmax << "] " << endl;

        // Integrate the likelihood function, and by iteration determine the cross-section value xmax below which
        // 95% of the integral is contained.
        Double_t Norm = like.Integral(0.,xmax,p,epsilon);
        if (plot) cout << "likelihood normalization: " << Norm << endl;
        //
        //      Double_t x1, x2, delta;
        x1 = 0;
        x2 = xmax;
        xmax = (x1 + x2)/2.;
        delta = like.Integral(0,xmax,p,epsilon)/Norm - 0.95;
        //
        while (fabs(delta) > epsilon)
        {
                if (delta < 0) x1 = xmax;
                else x2 = xmax;
                xmax = (x1 + x2)/2.;
                delta = like.Integral(0,xmax,p,epsilon)/Norm - 0.95;
        }

        // Plot the likelihood function and show the upper limit.
        x[0] = like.GetMaximumX(0.,MaxSig);
        if (plot)
        {
                TCanvas c("Likelihood");
                like.Draw();
                TArrow arrow(xmax,Likelihood(x,p)/7.,xmax,0,0.04);
                arrow.SetLineWidth(3.);
                arrow.Draw();
                c.Print("Likelihood.eps");
        }
        if (plot) cout << "Upper 95% C.L. limit on signal = " << xmax << " pb" << endl;
        //
        return xmax;
}

Double_t Likelihood(Double_t *x, Double_t *p)
// Calculate the likelihood to see N events as a function of the cross-section x[0].
// This corresponds to the probability that the cross-section x[0] is correct, given a flat prior.
// (N is a global parameter. The parameter p is dummy).
{
        Double_t retval = 0.;
        if (sB == 0.)
        {
                if (sA == 0.)
                {
                        // In this case, there is zero uncertainty on the nuisance parameters,
                        // so the likelihood is simply a Poission (or Gaussian).
                        if (lGauss) retval = TMath::Gaus(N-B0-x[0]*A0,0.,TMath::Sqrt(N),kTRUE);
                        else retval = Poisson(B0+x[0]*A0,N);
                }
                else
                {
                        // In this case, the parameter A0 (lumi*effi) is uncertain, so integrate
                        // the simple Poission over all possible values of A0, weighted by apriori
                        // prob. that that parameter is correct.
                        Double_t par[2];
                        //                TF1 *in = new TF1("Inner",Inner,0.,TMath::Max(A0 + 5.*sA,2);
                        TF1 *in = new TF1("Inner",Inner,0.,A0 + 5.*sA,2);
                        par[0]=B0;  // background value
                        par[1]=x[0];  // signal cross section value
                        if (I == 0)
                        {
                                Double_t low = A0 > 5.*sA ? A0 - 5.*sA : 0.;
                                retval = in->Integral(low,A0+5.*sA,par,epsilon);
                        } else {
                                Double_t low = 0., high = A0 + 5.*sA, tmp = 1.;
                                while (tmp > epsilon)
                                {
                                        tmp = in->Integral(low,high,par,epsilon);
                                        retval += tmp;
                                        low = high;
                                        high *= 2;
                                }
                        }
                        delete in;
                }
        }
        else
        {
                // In this case, both the parameters A0 (lumi*effi) and B0 (background) are uncertain,
                // so integrate over both of them.
                //        TF1 *out = new TF1("Outer",Outer,0.,TMath::Max(B0 + 5.*sB,1000.),1);
                TF1 *out = new TF1("Outer",Outer,0.,B0 + 5.*sB,1);
                if (I == 0)
                {
                        Double_t low = B0 > 5.*sB ? B0 - 5.*sB : 0.;
                        retval = out->Integral(low,B0+5.*sB,x,epsilon);
                } else {
                        Double_t low = 0., high = B0 + 5.*sB, tmp = 1.;
                        while (tmp > epsilon)
                        {
                                tmp = out->Integral(low,high,x,epsilon);
                                retval += tmp;
                                low = high;
                                high *= 2;
                        }
                }
                delete out;
        }
        return retval;
}

Double_t Outer(Double_t *x, Double_t *p)
// When calculating Poisson probabilities, allow for uncertainty in B0 (background) by summing over all possible
// values of this parameter, weighted by the apriori probability that it is correct.
// This function can make use of function Inner, which also takes into account uncertainty in lumi*effi.
{
        Double_t retval;
        if (sA == 0.)
        {
                //         cout << "x, sigma_b, B0 = " << x[0] << ", " << sigma_b << ", " << B0 << endl;
                if (lGauss) retval = TMath::Gaus(x[0],B0,sB,kTRUE)*TMath::Gaus(N-x[0]-p[0]*A0,0.,TMath::Sqrt(N),kTRUE);
                else if (I == 0) retval = TMath::Gaus(x[0],B0,sB,kTRUE)*Poisson(x[0]+p[0]*A0,N);
                else if (I == 1) retval = TMath::LogNormal(x[0], sigma_b, 0., B0)*Poisson(x[0]+p[0]*A0,N);
                else if (I == 2) retval = TMath::GammaDist(x[0], sigma_b, 0., 1./tau_b)*Poisson(x[0]+p[0]*A0,N);
                else return 0;
        }
        else
        {
                Double_t par[2];
                //         TF1 *in = new TF1("Inner",Inner,0.,TMath::Max(A0 + 5.*sA,1000.),2);
                TF1 *in = new TF1("Inner",Inner,0.,A0 + 5.*sA,2);
                par[0]=x[0];  // background value
                par[1]=p[0];  // signal cross section value
                Double_t low = A0 > 5.*sA ? A0 - 5.*sA : 0.;
                if (I == 0) retval = TMath::Gaus(x[0],B0,sB,kTRUE)*in->Integral(low,A0+5.*sA,par,epsilon);
                else if (I == 1) retval = TMath::LogNormal(x[0], sigma_b, 0., B0)*in->Integral(0.,A0+5.*sA,par,epsilon);
                else if (I == 2) retval = TMath::GammaDist(x[0], sigma_b, 0., 1./tau_b)*in->Integral(0.,A0+5.*sA,par,epsilon);
                else return 0;
                delete in;
        }
        return retval;
}

Double_t Inner(Double_t *x, Double_t *par)
// When calculating Poisson probabilities, allow for uncertainty in A0 (lumi*effi) by summing over all possible
// values of this parameter, weighted by the apriori probability that it is correct.
{
    Double_t sigma, B;
        //
    B = par[0];
    sigma = par[1];
    if (lGauss) return TMath::Gaus(x[0],A0,sA,kTRUE)*TMath::Gaus(N-B-sigma*x[0],0.,TMath::Sqrt(N),kTRUE);
    else if (I == 0) return TMath::Gaus(x[0],A0,sA,kTRUE)*Poisson(B+sigma*x[0],N);
        else if (I == 1) return TMath::LogNormal(x[0], sigma_a, 0., A0)*Poisson(B+sigma*x[0],N);
        else if (I == 2) return TMath::GammaDist(x[0], sigma_a, 0., 1./tau_a)*Poisson(B+sigma*x[0],N);
        else return 0;
}

Double_t Poisson(Double_t Mu, Int_t n)
// Calculate the Poission prob. of seeing n events given an expectation of Mu.
{
        if (Mu <= 0) return n > 0 ? 0. : 1.;

        Double_t logP;
        //
        // Tabulate values of -\sum log(i+2) up to n=1000 for faster calculation
        //

        //   Double_t sum = 0.;
        //   for (Int_t j = 0; j < 999; j++)
        //   {
        //              sum -= log(j+2.);
        //              printf("%10f, ",sum);
        //              if (((j+1)/10)*10 == j + 1) printf("\n");
        //   }

        Double_t logTable[999] = {-0.693147,  -1.791759,  -3.178054,  -4.787492,  -6.579251,  -8.525161, -10.604603, -12.801827, -15.104413, -17.502308,
                -19.987214, -22.552164, -25.191221, -27.899271, -30.671860, -33.505073, -36.395445, -39.339884, -42.335616, -45.380139,
                -48.471181, -51.606676, -54.784729, -58.003605, -61.261702, -64.557539, -67.889743, -71.257039, -74.658236, -78.092224,
                -81.557959, -85.054467, -88.580828, -92.136176, -95.719695, -99.330612, -102.968199, -106.631760, -110.320640, -114.034212,
                -117.771881, -121.533082, -125.317271, -129.123934, -132.952575, -136.802723, -140.673924, -144.565744, -148.477767, -152.409593,
                -156.360836, -160.331128, -164.320112, -168.327445, -172.352797, -176.395848, -180.456291, -184.533829, -188.628173, -192.739047,
                -196.866182, -201.009316, -205.168199, -209.342587, -213.532241, -217.736934, -221.956442, -226.190548, -230.439044, -234.701723,
                -238.978390, -243.268849, -247.572914, -251.890402, -256.221136, -260.564941, -264.921650, -269.291098, -273.673124, -278.067573,
                -282.474293, -286.893133, -291.323950, -295.766601, -300.220949, -304.686857, -309.164194, -313.652830, -318.152640, -322.663499,
                -327.185288, -331.717887, -336.261182, -340.815059, -345.379407, -349.954118, -354.539086, -359.134205, -363.739376, -368.354496,
                -372.979469, -377.614198, -382.258589, -386.912549, -391.575988, -396.248817, -400.930948, -405.622296, -410.322777, -415.032307,
                -419.750806, -424.478193, -429.214392, -433.959324, -438.712914, -443.475088, -448.245773, -453.024896, -457.812388, -462.608179,
                -467.412200, -472.224384, -477.044665, -481.872979, -486.709261, -491.553448, -496.405478, -501.265291, -506.132825, -511.008023,
                -515.890825, -520.781174, -525.679014, -530.584288, -535.496943, -540.416924, -545.344178, -550.278652, -555.220294, -560.169054,
                -565.124881, -570.087726, -575.057539, -580.034273, -585.017879, -590.008312, -595.005524, -600.009471, -605.020106, -610.037386,
                -615.061266, -620.091704, -625.128657, -630.172082, -635.221938, -640.278184, -645.340779, -650.409683, -655.484857, -660.566261,
                -665.653857, -670.747608, -675.847474, -680.953420, -686.065407, -691.183401, -696.307365, -701.437264, -706.573062, -711.714726,
                -716.862220, -722.015512, -727.174567, -732.339353, -737.509837, -742.685987, -747.867770, -753.055156, -758.248113, -763.446610,
                -768.650617, -773.860103, -779.075039, -784.295395, -789.521141, -794.752250, -799.988692, -805.230439, -810.477463, -815.729736,
                -820.987232, -826.249922, -831.517780, -836.790780, -842.068894, -847.352098, -852.640365, -857.933670, -863.231987, -868.535292,
                -873.843560, -879.156766, -884.474886, -889.797896, -895.125772, -900.458491, -905.796029, -911.138363, -916.485471, -921.837329,
                -927.193915, -932.555207, -937.921183, -943.291821, -948.667100, -954.046997, -959.431492, -964.820564, -970.214191, -975.612354,
                -981.015031, -986.422203, -991.833849, -997.249950, -1002.670485, -1008.095435, -1013.524780, -1018.958502, -1024.396582, -1029.838999,
                -1035.285737, -1040.736775, -1046.192096, -1051.651682, -1057.115514, -1062.583574, -1068.055844, -1073.532308, -1079.012947, -1084.497744,
                -1089.986681, -1095.479743, -1100.976911, -1106.478169, -1111.983501, -1117.492889, -1123.006318, -1128.523771, -1134.045232, -1139.570685,
                -1145.100114, -1150.633503, -1156.170838, -1161.712101, -1167.257279, -1172.806355, -1178.359314, -1183.916142, -1189.476824, -1195.041344,
                -1200.609689, -1206.181843, -1211.757792, -1217.337522, -1222.921018, -1228.508267, -1234.099254, -1239.693965, -1245.292387, -1250.894506,
                -1256.500308, -1262.109780, -1267.722908, -1273.339679, -1278.960080, -1284.584097, -1290.211718, -1295.842930, -1301.477720, -1307.116075,
                -1312.757982, -1318.403428, -1324.052403, -1329.704892, -1335.360884, -1341.020366, -1346.683326, -1352.349753, -1358.019634, -1363.692957,
                -1369.369711, -1375.049884, -1380.733463, -1386.420439, -1392.110798, -1397.804530, -1403.501624, -1409.202067, -1414.905850, -1420.612960,
                -1426.323387, -1432.037120, -1437.754148, -1443.474460, -1449.198045, -1454.924892, -1460.654992, -1466.388333, -1472.124906, -1477.864699,
                -1483.607702, -1489.353905, -1495.103298, -1500.855871, -1506.611613, -1512.370515, -1518.132566, -1523.897757, -1529.666078, -1535.437519,
                -1541.212071, -1546.989723, -1552.770467, -1558.554292, -1564.341189, -1570.131149, -1575.924163, -1581.720221, -1587.519313, -1593.321432,
                -1599.126567, -1604.934709, -1610.745850, -1616.559981, -1622.377092, -1628.197175, -1634.020221, -1639.846221, -1645.675166, -1651.507049,
                -1657.341860, -1663.179590, -1669.020232, -1674.863776, -1680.710215, -1686.559540, -1692.411742, -1698.266814, -1704.124747, -1709.985533,
                -1715.849165, -1721.715633, -1727.584930, -1733.457047, -1739.331978, -1745.209714, -1751.090247, -1756.973569, -1762.859673, -1768.748551,
                -1774.640196, -1780.534598, -1786.431752, -1792.331650, -1798.234283, -1804.139645, -1810.047728, -1815.958524, -1821.872027, -1827.788229,
                -1833.707123, -1839.628702, -1845.552957, -1851.479884, -1857.409473, -1863.341718, -1869.276612, -1875.214148, -1881.154319, -1887.097119,
                -1893.042539, -1898.990574, -1904.941217, -1910.894460, -1916.850298, -1922.808722, -1928.769728, -1934.733307, -1940.699454, -1946.668161,
                -1952.639423, -1958.613233, -1964.589584, -1970.568470, -1976.549884, -1982.533820, -1988.520272, -1994.509233, -2000.500698, -2006.494659,
                -2012.491111, -2018.490048, -2024.491463, -2030.495350, -2036.501703, -2042.510516, -2048.521784, -2054.535499, -2060.551656, -2066.570249,
                -2072.591272, -2078.614720, -2084.640586, -2090.668864, -2096.699550, -2102.732636, -2108.768117, -2114.805988, -2120.846243, -2126.888876,
                -2132.933881, -2138.981253, -2145.030987, -2151.083076, -2157.137515, -2163.194299, -2169.253423, -2175.314879, -2181.378665, -2187.444773,
                -2193.513198, -2199.583936, -2205.656981, -2211.732327, -2217.809969, -2223.889902, -2229.972121, -2236.056620, -2242.143395, -2248.232440,
                -2254.323750, -2260.417320, -2266.513144, -2272.611219, -2278.711537, -2284.814096, -2290.918889, -2297.025912, -2303.135160, -2309.246627,
                -2315.360309, -2321.476201, -2327.594299, -2333.714596, -2339.837089, -2345.961772, -2352.088641, -2358.217692, -2364.348918, -2370.482316,
                -2376.617881, -2382.755608, -2388.895493, -2395.037530, -2401.181716, -2407.328045, -2413.476513, -2419.627116, -2425.779849, -2431.934707,
                -2438.091686, -2444.250781, -2450.411988, -2456.575303, -2462.740721, -2468.908238, -2475.077848, -2481.249549, -2487.423335, -2493.599202,
                -2499.777146, -2505.957163, -2512.139248, -2518.323397, -2524.509606, -2530.697870, -2536.888185, -2543.080548, -2549.274953, -2555.471397,
                -2561.669876, -2567.870385, -2574.072920, -2580.277478, -2586.484054, -2592.692644, -2598.903244, -2605.115850, -2611.330458, -2617.547065,
                -2623.765665, -2629.986255, -2636.208831, -2642.433390, -2648.659926, -2654.888437, -2661.118919, -2667.351367, -2673.585777, -2679.822147,
                -2686.060472, -2692.300747, -2698.542971, -2704.787138, -2711.033244, -2717.281287, -2723.531263, -2729.783166, -2736.036995, -2742.292745,
                -2748.550413, -2754.809994, -2761.071486, -2767.334884, -2773.600185, -2779.867386, -2786.136482, -2792.407471, -2798.680348, -2804.955110,
                -2811.231753, -2817.510275, -2823.790671, -2830.072937, -2836.357071, -2842.643070, -2848.930928, -2855.220644, -2861.512213, -2867.805632,
                -2874.100898, -2880.398007, -2886.696957, -2892.997742, -2899.300361, -2905.604810, -2911.911085, -2918.219184, -2924.529102, -2930.840837,
                -2937.154385, -2943.469743, -2949.786908, -2956.105876, -2962.426644, -2968.749209, -2975.073568, -2981.399718, -2987.727655, -2994.057376,
                -3000.388877, -3006.722157, -3013.057211, -3019.394037, -3025.732631, -3032.072990, -3038.415112, -3044.758992, -3051.104629, -3057.452018,
                -3063.801157, -3070.152043, -3076.504672, -3082.859042, -3089.215150, -3095.572992, -3101.932566, -3108.293868, -3114.656896, -3121.021647,
                -3127.388118, -3133.756305, -3140.126206, -3146.497818, -3152.871137, -3159.246162, -3165.622889, -3172.001315, -3178.381438, -3184.763254,
                -3191.146760, -3197.531955, -3203.918834, -3210.307396, -3216.697636, -3223.089553, -3229.483144, -3235.878406, -3242.275335, -3248.673930,
                -3255.074188, -3261.476105, -3267.879679, -3274.284908, -3280.691788, -3287.100316, -3293.510491, -3299.922310, -3306.335768, -3312.750865,
                -3319.167598, -3325.585963, -3332.005958, -3338.427580, -3344.850827, -3351.275696, -3357.702184, -3364.130290, -3370.560009, -3376.991340,
                -3383.424280, -3389.858827, -3396.294977, -3402.732729, -3409.172079, -3415.613026, -3422.055566, -3428.499697, -3434.945417, -3441.392723,
                -3447.841612, -3454.292083, -3460.744132, -3467.197757, -3473.652955, -3480.109725, -3486.568063, -3493.027968, -3499.489436, -3505.952465,
                -3512.417053, -3518.883198, -3525.350897, -3531.820147, -3538.290947, -3544.763293, -3551.237184, -3557.712616, -3564.189589, -3570.668098,
                -3577.148143, -3583.629720, -3590.112827, -3596.597463, -3603.083624, -3609.571308, -3616.060512, -3622.551236, -3629.043476, -3635.537230,
                -3642.032495, -3648.529270, -3655.027552, -3661.527339, -3668.028629, -3674.531419, -3681.035707, -3687.541491, -3694.048769, -3700.557538,
                -3707.067797, -3713.579542, -3720.092772, -3726.607485, -3733.123678, -3739.641349, -3746.160496, -3752.681117, -3759.203210, -3765.726773,
                -3772.251802, -3778.778297, -3785.306255, -3791.835674, -3798.366551, -3804.898886, -3811.432675, -3817.967916, -3824.504607, -3831.042747,
                -3837.582333, -3844.123363, -3850.665835, -3857.209747, -3863.755097, -3870.301882, -3876.850101, -3883.399752, -3889.950832, -3896.503340,
                -3903.057274, -3909.612630, -3916.169409, -3922.727607, -3929.287222, -3935.848253, -3942.410697, -3948.974552, -3955.539817, -3962.106490,
                -3968.674567, -3975.244049, -3981.814932, -3988.387214, -3994.960895, -4001.535970, -4008.112440, -4014.690301, -4021.269553, -4027.850192,
                -4034.432217, -4041.015626, -4047.600417, -4054.186589, -4060.774139, -4067.363066, -4073.953367, -4080.545040, -4087.138085, -4093.732498,
                -4100.328279, -4106.925425, -4113.523934, -4120.123804, -4126.725034, -4133.327622, -4139.931566, -4146.536864, -4153.143514, -4159.751515,
                -4166.360864, -4172.971560, -4179.583601, -4186.196985, -4192.811711, -4199.427776, -4206.045179, -4212.663918, -4219.283991, -4225.905397,
                -4232.528133, -4239.152198, -4245.777591, -4252.404308, -4259.032350, -4265.661713, -4272.292396, -4278.924398, -4285.557717, -4292.192350,
                -4298.828297, -4305.465555, -4312.104122, -4318.743998, -4325.385180, -4332.027667, -4338.671457, -4345.316548, -4351.962938, -4358.610627,
                -4365.259611, -4371.909890, -4378.561462, -4385.214325, -4391.868478, -4398.523918, -4405.180645, -4411.838656, -4418.497950, -4425.158525,
                -4431.820380, -4438.483512, -4445.147921, -4451.813605, -4458.480562, -4465.148790, -4471.818288, -4478.489054, -4485.161087, -4491.834385,
                -4498.508947, -4505.184770, -4511.861853, -4518.540196, -4525.219795, -4531.900649, -4538.582758, -4545.266119, -4551.950731, -4558.636592,
                -4565.323700, -4572.012055, -4578.701654, -4585.392497, -4592.084580, -4598.777904, -4605.472466, -4612.168265, -4618.865299, -4625.563567,
                -4632.263068, -4638.963799, -4645.665759, -4652.368947, -4659.073361, -4665.779001, -4672.485863, -4679.193947, -4685.903251, -4692.613774,
                -4699.325515, -4706.038471, -4712.752642, -4719.468025, -4726.184620, -4732.902424, -4739.621438, -4746.341658, -4753.063083, -4759.785713,
                -4766.509546, -4773.234579, -4779.960813, -4786.688244, -4793.416873, -4800.146697, -4806.877715, -4813.609926, -4820.343328, -4827.077919,
                -4833.813700, -4840.550666, -4847.288819, -4854.028156, -4860.768675, -4867.510376, -4874.253256, -4880.997315, -4887.742552, -4894.488964,
                -4901.236550, -4907.985310, -4914.735241, -4921.486343, -4928.238613, -4934.992051, -4941.746655, -4948.502424, -4955.259356, -4962.017451,
                -4968.776706, -4975.537121, -4982.298694, -4989.061423, -4995.825308, -5002.590347, -5009.356539, -5016.123882, -5022.892375, -5029.662017,
                -5036.432806, -5043.204742, -5049.977822, -5056.752046, -5063.527412, -5070.303919, -5077.081566, -5083.860351, -5090.640273, -5097.421330,
                -5104.203522, -5110.986848, -5117.771305, -5124.556892, -5131.343609, -5138.131454, -5144.920426, -5151.710523, -5158.501745, -5165.294089,
                -5172.087555, -5178.882142, -5185.677848, -5192.474671, -5199.272612, -5206.071668, -5212.871838, -5219.673121, -5226.475515, -5233.279021,
                -5240.083635, -5246.889358, -5253.696187, -5260.504122, -5267.313161, -5274.123304, -5280.934548, -5287.746893, -5294.560338, -5301.374881,
                -5308.190521, -5315.007257, -5321.825087, -5328.644011, -5335.464028, -5342.285135, -5349.107333, -5355.930619, -5362.754992, -5369.580452,
                -5376.406998, -5383.234627, -5390.063339, -5396.893133, -5403.724007, -5410.555960, -5417.388992, -5424.223101, -5431.058286, -5437.894545,
                -5444.731878, -5451.570283, -5458.409759, -5465.250306, -5472.091921, -5478.934605, -5485.778355, -5492.623170, -5499.469050, -5506.315993,
                -5513.163998, -5520.013065, -5526.863191, -5533.714376, -5540.566618, -5547.419917, -5554.274272, -5561.129681, -5567.986143, -5574.843657,
                -5581.702222, -5588.561837, -5595.422500, -5602.284212, -5609.146970, -5616.010773, -5622.875621, -5629.741512, -5636.608445, -5643.476419,
                -5650.345434, -5657.215487, -5664.086579, -5670.958707, -5677.831871, -5684.706069, -5691.581301, -5698.457566, -5705.334862, -5712.213188,
                -5719.092544, -5725.972928, -5732.854339, -5739.736777, -5746.620240, -5753.504726, -5760.390236, -5767.276768, -5774.164320, -5781.052893,
                -5787.942484, -5794.833093, -5801.724719, -5808.617361, -5815.511017, -5822.405687, -5829.301370, -5836.198064, -5843.095769, -5849.994483,
                -5856.894207, -5863.794937, -5870.696674, -5877.599417, -5884.503164, -5891.407915, -5898.313668, -5905.220423, -5912.128178 };

        logP = -Mu + n*log(Mu);
        if (n >= 2) logP += logTable[TMath::Min(n,1000)-2];

        for (Int_t i = 1001; i <= n; i++) logP -= log((Double_t) i);

        return exp(logP);
}//

Double_t CLA(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Bool_t gauss, Int_t bckint)
{
        plot = kFALSE;
        Double_t CL95A = 0, precision = 1.e-4;
        Int_t i;
        for (i = bck; i >= 0; i--)
        {
                //
                Double_t s95 = CL95(ilum, slum, eff, seff, bck, sbck, i, gauss, bckint);
                Double_t s95w =s95*Poisson(bck,i);
                CL95A += s95w;
                cout << "n = " << i << "; 95% C.L. = " << s95 << " pb; weighted 95% C.L. = " << s95w << " pb; running <s95> = " << CL95A << " pb" << endl;
                //
                if (s95w < CL95A*precision) break;
        }
        cout << "Lower bound on n has been found at " << i+1 << endl;
        //
        for (i = bck+1; ; i++)
        {
                Double_t s95 = CL95(ilum, slum, eff, seff, bck, sbck, i, gauss, bckint);
                Double_t s95w =s95*Poisson(bck,i);
                CL95A += s95w;
                cout << "n = " << i << "; 95% C.L. = " << s95 << " pb; weighted 95% C.L. = " << s95w << " pb; running <s95> = " << CL95A << " pb" << endl;
                //
                if (s95w < CL95A*precision) break;
        }
        cout << "Upper bound on n has been found at " << i << endl;
        //
        cout << "Average upper 95% C.L. limit = " << CL95A << " pb" << endl;
        return CL95A;
}
