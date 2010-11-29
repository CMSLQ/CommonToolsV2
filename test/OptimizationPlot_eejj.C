
// root -l -q OptimizationPlot_eejj.C+\(100\)
// where the argument is the number of bins in the optimization histograms
// See also UserCode/Leptoquarks/CommonToolsV2/test/README

#include "cl95cms.C"
#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TFile.h"
#include "TLegend.h"
#include "TPolyLine.h"
#include "TPad.h"
#include "TLatex.h"
#include <iostream>
#include <sstream>


void OptimizationPlot_eejj(int nbins = 100)
{
  gROOT->SetBatch(kTRUE);
  //nbins=10000;
  cout << "nbins = " << nbins << endl;

  //////////////////////////////
  // User inputs here
  //////////////////////////////
  TString file1_str   = "$LQDATA/opt_eejj/35pb-1_Mee95to140_st500to680/output_cutTable_eejjSample_opt/analysisClass_eejjSample_plots.root";
  TString optfile_str = "$LQDATA/opt_eejj/35pb-1_Mee95to140_st500to680/output_cutTable_eejjSample_opt/optimizationCuts.txt";
  TString signalHisto_str  = "histo1D__LQeejj_M400__Optimizer";
  TString allbkgHisto_str  = "histo1D__ALLBKG__Optimizer";
  TString evtpassHisto_str = "histo1D__LQeejj_M400__EventsPassingCuts";

  TFile file1(file1_str);
  file1.cd();

  TH1D Signal;
  ((TH1D*)gDirectory->Get(signalHisto_str))->Copy(Signal); Signal.Sumw2();
  TH1D Backgnd;
  ((TH1D*)gDirectory->Get(allbkgHisto_str))->Copy(Backgnd); Backgnd.Sumw2();

  double Ns_noCut( ((TH1D*)gDirectory->Get(evtpassHisto_str))->GetBinContent(1) ); // needed for CLA() method only

  ////////////////////////////////////////////////
  // Parameters needed when using the CLA.C method
  ////////////////////////////////////////////////
  double eff; // signal efficiency
  double eff_err_rel = 0.07; // Relative error on signal efficiency
  double Nb_err_rel = 0.35; // Relative error on background, dominated by JES
  double ILum = 27; // pb-1
  double ILum_err_rel = 0.11; // Relative error on Integrated Luminosity
  double upperLimit;

  TCanvas * c1 = new TCanvas;
  TPad * pad1 = new TPad("pad1","This is pad1",0.01,0.51,0.95,0.99);
  TPad * pad2 = new TPad("pad2","This is pad2",0.01,0.01,0.95,0.49);
  //pad1->SetFillColor(11);
  //pad2->SetFillColor(11);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  Signal.Draw();
  pad2->cd();
  Backgnd.Draw();
  c1->SaveAs("SignBkg.png");

  TH1D Signif ("Significance","Significance",nbins,0.0,nbins);
  TH1D UpperLimit ("Upper Limit","Upper Limit",nbins,0.0,nbins);

  double maxSignif = -1;
  int bin_fromSignif = -1;
  double minUpperLimit = 999999999;
  int bin_fromUpperLimit = -1;
  double Ns;
  double Nb;
  double NbErr;
  double NbErrAtMinUpLim;
  double effAtMinUpLim;
  for (int i=1; i<=nbins; i++){ // Bin = 0 is the underflow
    //if ( (i-1)%100 != 0 ) continue;
    //if ( (i-1) != 1200 ) continue;
    //if ( (i-1) < 60 || (i-1) >= 70 ) continue;
    //cout<<"i = "<<i<<endl;
    Ns = Signal.GetBinContent(i);
    Nb = Backgnd.GetBinContent(i);
    double signif = 0;

    // use significance method
    double delta_Nb = Nb*Nb_err_rel;
    if ( sqrt(Ns+Nb+delta_Nb*delta_Nb) >0 ) signif = Ns / sqrt(Ns+Nb+delta_Nb*delta_Nb);
    Signif.SetBinContent(i,signif);
    if (signif>maxSignif) {
      maxSignif = signif;
      bin_fromSignif = i;
    }

    // use upper limit method
    eff = Ns/Ns_noCut;
    cout<< "Calling CLA for bin i = " << i << endl;
    //cout << ILum <<" "<< ILum*ILum_err_rel <<" "<<  eff <<" "<<  eff*eff_err_rel <<" "<<  Nb <<" "<<  Nb*Nb_err_rel << endl;
    NbErr = Nb*Nb_err_rel;
    //upperLimit = CLA(ILum, ILum*ILum_err_rel, eff, eff*eff_err_rel, Nb, NbErr);
    upperLimit = CLA(ILum, ILum*ILum_err_rel, eff, eff*eff_err_rel, Nb, NbErr, kFALSE, 0);
    UpperLimit.SetBinContent(i,upperLimit);
    if (upperLimit<minUpperLimit) {
      minUpperLimit = upperLimit;
      effAtMinUpLim = eff;
      NbErrAtMinUpLim=NbErr;
      bin_fromUpperLimit = i;
    }
  }

  //char *ss = new char[1];
  //std::cout << "Press Enter to continue"<<std::endl;  gets(ss);

  // print file and histo names
  std::cout << "-------------------------------------------------------------------  " <<std::endl;
  std::cout << "-------------------------------------------------------------------  " <<std::endl;
  std::cout << "file1_str:   " << file1_str <<std::endl;
  std::cout << "optfile_str: " << optfile_str <<std::endl;
  std::cout << "signalHisto_str:  " << signalHisto_str <<std::endl;
  std::cout << "allbkgHisto_str:  " << allbkgHisto_str <<std::endl;
  std::cout << "evtpassHisto_str: " << evtpassHisto_str <<std::endl;
  std::cout << "eff_err_rel = " <<eff_err_rel << "; Nb_err_rel = " <<Nb_err_rel << "; ILum = " <<ILum << "; ILum_err_rel = " <<ILum_err_rel <<  std::endl;


  //  print output from significance method
  TCanvas * c2 = new TCanvas;
  Signif.Draw();
  std::cout << "----------- Optimization by Significance:" <<std::endl;
  std::cout << "maxSignif: " << maxSignif << "\t" << "Bin_FromSignif - 1 (as bin zero is overflow): " << bin_fromSignif - 1 << std::endl;
  //std::cout << "Significance: " << Signif.GetBinContent(bin_fromSignif) << std::endl;
  std::cout << "ILum = " << ILum << "\t Ns = " << Signal.GetBinContent(bin_fromSignif) << "\t Nb = " << Backgnd.GetBinContent(bin_fromSignif) << std::endl;
  std::stringstream ss1; ss1<<"grep 'Bin = "<<(bin_fromSignif - 1)<<"\t' "<<optfile_str <<std::endl; //std::cout<<ss1.str()<<std::endl;
  system(ss1.str().c_str());
  c2->SaveAs("Signif.png");

  // print output from upper limit method
  TCanvas * c3 = new TCanvas;
  UpperLimit.Draw();
  double delta_Nb = Backgnd.GetBinContent(bin_fromUpperLimit)*Nb_err_rel;
  std::cout << "----------- Optimization by Upper Limit:" <<std::endl;
  std::cout << "UpperLimit: " << minUpperLimit << "\t" << "Bin_FromUpperLimit - 1 (as bin zero is overflow): " << bin_fromUpperLimit - 1 << std::endl;
  std::cout << "ILum = " << ILum << "\t Ns = " << Signal.GetBinContent(bin_fromUpperLimit) << "\t Nb = " << Backgnd.GetBinContent(bin_fromUpperLimit) << "\t Ns/[sqrt(Ns+Nb+DeltaNb^2)] = " << Signal.GetBinContent(bin_fromUpperLimit)/sqrt(Signal.GetBinContent(bin_fromUpperLimit)+Backgnd.GetBinContent(bin_fromUpperLimit)+delta_Nb*delta_Nb)  << std::endl;
  std::cout << "effAtMinUpLim = " << effAtMinUpLim << "\t" << "NbErrAtMinUpLim = "<< NbErrAtMinUpLim <<std::endl;
  std::stringstream ss2; ss2<<"grep 'Bin = "<<(bin_fromUpperLimit - 1)<<"\t' "<<optfile_str <<std::endl; //std::cout<<ss2.str()<<std::endl;
  system(ss2.str().c_str());
  c3->SaveAs("UpperLimit.png");


  //printCuts(cuts);

  //std::cout << "Press Enter to continue"<<std::endl;  gets(ss);

  TFile outfile("OptimizationPlot_eejj.root","recreate");
  Signif.Write();
  UpperLimit.Write();
  outfile.Close();

}





