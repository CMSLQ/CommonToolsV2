#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLatex.h"
#include "TSpline.h"

using namespace std;

void myStyle();
void setTDRStyle();
void fill_arrays(const Double_t fMass_min, const Double_t fMass_max, const Int_t fNPts, const TSpline3& fGS_xsUp_vs_m, const TSpline3& fGS_xsTh_vs_m, Double_t* x, Double_t* y);


void makePlots()
{
 // **********************************************
 // *            Input parameters                *
 // **********************************************

 // turn on/off batch mode
 gROOT->SetBatch(kTRUE);
 
 // turn on/off debugging mode
 Bool_t debug = kFALSE;

 // array of LQ masses for calculation of upXS
 Double_t mData[10] = {200, 250, 280, 300, 320, 340, 370, 400, 450, 500};
 // arrays of upper limits on the cross section
 Double_t xsUp_observed[10] = {1.0918, 0.56543, 0.536133, 0.420898, 0.411621, 0.394043, 0.287354, 0.27124, 0.180835, 0.168945};
 Double_t xsUp_expected[10] = {1.3625, 0.728578, 0.560355, 0.478632, 0.411471, 0.36518, 0.318113, 0.284102, 0.248004, 0.226132};
 // Zero systematics case
//  Double_t xsUp_observed[10] = {0.975586, 0.526367, 0.510254, 0.404297, 0.39917, 0.383789, 0.280762, 0.265625, 0.178125, 0.166406};
//  Double_t xsUp_expected[10] = {1.24111, 0.685307, 0.537118, 0.462398, 0.400498, 0.356725, 0.31154, 0.278739, 0.243565, 0.222276};
 // Doubled systematics case
//  Double_t xsUp_observed[10] = {1.21094, 0.615234, 0.577881, 0.450195, 0.438965, 0.419434, 0.304199, 0.286865, 0.189697, 0.1771};
//  Double_t xsUp_expected[10] = {1.50694, 0.792841, 0.602788, 0.512162, 0.437966, 0.387823, 0.336865, 0.300479, 0.261752, 0.238493};

 // arrays of LQ masses for theoretical cross section
 Double_t mTh[10] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550};
 // arrays of theoretical cross-sections for different leptoquark masses
 Double_t xsTh[10] = {386, 53.3, 11.9, 3.47, 1.21, 0.477, 0.205, 0.0949, 0.0463, 0.0236};
 // arays of upper and lower bounds with PDF and scale uncertainties included
 Double_t xsTh_upper[10] = {445.5, 61.4, 13.7, 4.1, 1.43, 0.572, 0.249, 0.1167, 0.0581, 0.0300}; // upper bounds with PDF and scale uncertainties included
 Double_t xsTh_lower[10] = {330.3, 45.2, 10.0, 2.9, 0.98, 0.379, 0.160, 0.0719, 0.0340, 0.0169}; // lower bounds with PDF and scale uncertainties included

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_enujj.eps";
 // Zero systematics case
//  string fileName = "beta_vs_m_excl_enujj_zeroSyst.eps";
 // Doubled systematics case
//  string fileName = "beta_vs_m_excl_enujj_doubledSyst.eps";

 // axes labels for the final plot
 string title = ";M_{LQ} [GeV];#beta";

 // integrated luminosity
 string sqrts = "#sqrt{s} = 7 TeV";

 // number of points used for beta vs m line
 Int_t nPts = 50;
 // range of LQ masses in which beta vs m line is derived
 Double_t mass_range[2] = {200, 360};

 // region excluded by Tevatron limits (1 fb-1)
 Double_t x_excl[13] = {200,214.39,235.13,254.08,268.12,275.92,283.95,289.08,293.09,295.99,297.10,298.89,200};
 Double_t y_excl[13] = {0,0,0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,1,1};

 // set ROOT style
//  myStyle();
 setTDRStyle();
//  gStyle->SetPadLeftMargin(0.14);
//  gStyle->SetPadRightMargin(0.6);
 gROOT->ForceStyle();

 TH2F *bg = new TH2F("bg",title.c_str(), 20, 200., 360., 100, 0., 1.);
 bg->SetStats(kFALSE);
 bg->SetTitleOffset(1.,"X");
 bg->SetTitleOffset(1.,"Y");
//  bg->GetXaxis()->SetNdivisions(505);

 TCanvas *c = new TCanvas("c","",800,800);
 c->cd();

 Int_t size_th = sizeof(xsTh)/sizeof(*xsTh);

 Double_t xsTh_log[size_th];
 Double_t xsTh_upper_log[size_th];
 Double_t xsTh_lower_log[size_th];

 for(Int_t i=0; i<size_th; i++) {
   xsTh_log[i] = log(xsTh[i]);
   xsTh_upper_log[i] = log(xsTh_upper[i]);
   xsTh_lower_log[i] = log(xsTh_lower[i]);
 }

 TGraph *xsTh_vs_m_log = new TGraph(size_th, mTh, xsTh_log);
 TGraph *xsTh_upper_vs_m_log = new TGraph(size_th, mTh, xsTh_upper_log);
 TGraph *xsTh_lower_vs_m_log = new TGraph(size_th, mTh, xsTh_lower_log);

 TSpline3 gs_xsTh_vs_m("gs_xsTh_vs_m", xsTh_vs_m_log);
 TSpline3 gs_xsTh_upper_vs_m("gs_xsTh_vs_m", xsTh_upper_vs_m_log);
 TSpline3 gs_xsTh_lower_vs_m("gs_xsTh_vs_m", xsTh_lower_vs_m_log);

 Int_t size_Data = sizeof(xsUp_expected)/sizeof(*xsUp_expected);

 Double_t xsUp_expected_log[size_Data];
 Double_t xsUp_observed_log[size_Data];

 for(Int_t i=0; i<size_Data; i++) {
   xsUp_expected_log[i] = log(xsUp_expected[i]);
   xsUp_observed_log[i] = log(xsUp_observed[i]);
 }

 TGraph *xsUp_expected_vs_m_log = new TGraph(size_Data, mData, xsUp_expected_log);
 TGraph *xsUp_observed_vs_m_log = new TGraph(size_Data, mData, xsUp_observed_log);

 TSpline3 gs_xsUp_expected_vs_m("gs_xsTh_vs_m", xsUp_expected_vs_m_log);
 TSpline3 gs_xsUp_observed_vs_m("gs_xsTh_vs_m", xsUp_observed_vs_m_log);

 /*******************************************
 ****         Debugging section          ****
 *******************************************/
 if(debug) {
   Double_t mTh_int[20];
   Double_t xsTh_int[20];
   Double_t xsTh_upper_int[20];
   Double_t xsTh_lower_int[20];

   Double_t step_th = (mTh[size_th-1]-mTh[0])/19;

   for(Int_t i=0; i<20; i++) {
     mTh_int[i] = mTh[0]+step_th*i;
     xsTh_int[i] = exp(gs_xsTh_vs_m.Eval(mTh_int[i]));
     xsTh_upper_int[i] = exp(gs_xsTh_upper_vs_m.Eval(mTh_int[i]));
     xsTh_lower_int[i] = exp(gs_xsTh_lower_vs_m.Eval(mTh_int[i]));
   }

   TGraph *xsTh_vs_m = new TGraph(size_th, mTh, xsTh);
   xsTh_vs_m->SetLineWidth(2);
   xsTh_vs_m->SetLineColor(kRed);
   xsTh_vs_m->Draw("ACP");

   TGraph *xsTh_vs_m_int = new TGraph(20, mTh_int, xsTh_int);
   xsTh_vs_m_int->SetMarkerSize(1.);
   xsTh_vs_m_int->SetMarkerStyle(24);
   xsTh_vs_m_int->SetMarkerColor(kBlue);
   xsTh_vs_m_int->Draw("P");

   c->SetGridx();
   c->SetGridy();
   c->SetLogy();
   c->SaveAs("xsTh_vs_m.png");

   TGraph *xsTh_upper_vs_m = new TGraph(size_th, mTh, xsTh_upper);
   xsTh_upper_vs_m->SetLineWidth(2);
   xsTh_upper_vs_m->SetLineColor(kRed);
   xsTh_upper_vs_m->Draw("ACP");

   TGraph *xsTh_upper_vs_m_int = new TGraph(20, mTh_int, xsTh_upper_int);
   xsTh_upper_vs_m_int->SetMarkerSize(1.);
   xsTh_upper_vs_m_int->SetMarkerStyle(24);
   xsTh_upper_vs_m_int->SetMarkerColor(kBlue);
   xsTh_upper_vs_m_int->Draw("P");

   c->SetGridx();
   c->SetGridy();
   c->SetLogy();
   c->SaveAs("xsTh_upper_vs_m.png");

   TGraph *xsTh_lower_vs_m = new TGraph(size_th, mTh, xsTh_lower);
   xsTh_lower_vs_m->SetLineWidth(2);
   xsTh_lower_vs_m->SetLineColor(kRed);
   xsTh_lower_vs_m->Draw("ACP");

   TGraph *xsTh_lower_vs_m_int = new TGraph(20, mTh_int, xsTh_lower_int);
   xsTh_lower_vs_m_int->SetMarkerSize(1.);
   xsTh_lower_vs_m_int->SetMarkerStyle(24);
   xsTh_lower_vs_m_int->SetMarkerColor(kBlue);
   xsTh_lower_vs_m_int->Draw("P");

   c->SetGridx();
   c->SetGridy();
   c->SetLogy();
   c->SaveAs("xsTh_lower_vs_m.png");

   Double_t mData_int[20];
   Double_t xsUp_expected_int[20];
   Double_t xsUp_observed_int[20];

   Double_t step_Data = (mData[size_Data-1]-mData[0])/19;

   for(Int_t i=0; i<20; i++) {
     mData_int[i] = mData[0]+step_Data*i;
     xsUp_expected_int[i] = exp(gs_xsUp_expected_vs_m.Eval(mData_int[i]));
     xsUp_observed_int[i] = exp(gs_xsUp_observed_vs_m.Eval(mData_int[i]));
   }

   TGraph *xsUp_expected_vs_m = new TGraph(size_Data, mData, xsUp_expected);
   xsUp_expected_vs_m->SetLineWidth(2);
   xsUp_expected_vs_m->SetLineColor(kRed);
   xsUp_expected_vs_m->Draw("ACP");

   TGraph *xsUp_expected_vs_m_int = new TGraph(20, mData_int, xsUp_expected_int);
   xsUp_expected_vs_m_int->SetMarkerSize(1.);
   xsUp_expected_vs_m_int->SetMarkerStyle(24);
   xsUp_expected_vs_m_int->SetMarkerColor(kBlue);
   xsUp_expected_vs_m_int->Draw("P");

   c->SetGridx();
   c->SetGridy();
   c->SetLogy();
   c->SaveAs("xsUp_expected_vs_m.png");

   TGraph *xsUp_observed_vs_m = new TGraph(size_Data, mData, xsUp_observed);
   xsUp_observed_vs_m->SetLineWidth(2);
   xsUp_observed_vs_m->SetLineColor(kRed);
   xsUp_observed_vs_m->Draw("ACP");

   TGraph *xsUp_observed_vs_m_int = new TGraph(20, mData_int, xsUp_observed_int);
   xsUp_observed_vs_m_int->SetMarkerSize(1.);
   xsUp_observed_vs_m_int->SetMarkerStyle(24);
   xsUp_observed_vs_m_int->SetMarkerColor(kBlue);
   xsUp_observed_vs_m_int->Draw("P");

   c->SetGridx();
   c->SetGridy();
   c->SetLogy();
   c->SaveAs("xsUp_observed_vs_m.png");

   delete xsTh_vs_m;
   delete xsTh_vs_m_int;
   delete xsTh_upper_vs_m;
   delete xsTh_upper_vs_m_int;
   delete xsTh_lower_vs_m;
   delete xsTh_lower_vs_m_int;
   delete xsUp_expected_vs_m_int;
   delete xsUp_observed_vs_m_int;
 }
 /*******************************************
 ****       End of debugging section     ****
 *******************************************/

 bg->Draw();

 TGraph *gr_excl = new TGraph(13,x_excl,y_excl);
 gr_excl->SetLineColor(0);
 gr_excl->SetFillColor(kGray);
//  gr_excl->Draw("f");

 Double_t m_expected[2*nPts], beta_expected[2*nPts], m_observed[2*nPts], beta_observed[2*nPts], m_observed_upper[2*nPts], beta_observed_upper[2*nPts], m_observed_lower[2*nPts], beta_observed_lower[2*nPts];

 fill_arrays(mass_range[0], mass_range[1], nPts, gs_xsUp_expected_vs_m, gs_xsTh_vs_m, m_expected, beta_expected);
 fill_arrays(mass_range[0], mass_range[1], nPts, gs_xsUp_observed_vs_m, gs_xsTh_vs_m, m_observed, beta_observed);
 fill_arrays(mass_range[0], mass_range[1], nPts, gs_xsUp_observed_vs_m, gs_xsTh_upper_vs_m, m_observed_lower, beta_observed_lower);
 fill_arrays(mass_range[0], mass_range[1], nPts, gs_xsUp_observed_vs_m, gs_xsTh_lower_vs_m, m_observed_upper, beta_observed_upper);

 cout<<endl<<Form("Double_t m_enujj_observed[%i] = {", 2*nPts);
 for(Int_t i = 0; i<2*nPts; i++) {
   cout<<m_observed[i];
   if(i<(2*nPts-1)) cout<<", ";
 }
 cout<<"};"<<endl;
 cout<<Form("Double_t beta_enujj_observed[%i] = {", 2*nPts);
 for(Int_t i = 0; i<2*nPts; i++) {
   cout<<beta_observed[i];
   if(i<(2*nPts-1)) cout<<", ";
 }
 cout<<"};"<<endl;
 cout<<Form("Double_t m_enujj_expected[%i] = {", 2*nPts);
 for(Int_t i = 0; i<2*nPts; i++) {
   cout<<m_expected[i];
   if(i<(2*nPts-1)) cout<<", ";
 }
 cout<<"};"<<endl;
 cout<<Form("Double_t beta_enujj_expected[%i] = {", 2*nPts);
 for(Int_t i = 0; i<2*nPts; i++) {
   cout<<beta_expected[i];
   if(i<(2*nPts-1)) cout<<", ";
 }
 cout<<"};"<<endl<<endl;

 TGraph *beta_observed_vs_m_band = new TGraph(4*nPts);
 for(Int_t i=0;i<(2*nPts);i++) {
   beta_observed_vs_m_band->SetPoint(i,m_observed_lower[i],beta_observed_lower[i]);
   beta_observed_vs_m_band->SetPoint(2*nPts+i,m_observed_upper[2*nPts-i-1],beta_observed_upper[2*nPts-i-1]);
 }
 beta_observed_vs_m_band->SetLineColor(0);
 beta_observed_vs_m_band->SetFillColor(kYellow);
 beta_observed_vs_m_band->Draw("f");

 TGraph *beta_expected_vs_m = new TGraph(2*nPts, m_expected, beta_expected);
 beta_expected_vs_m->SetLineWidth(3);
 beta_expected_vs_m->SetLineStyle(2);
 beta_expected_vs_m->SetLineColor(kBlue);
 beta_expected_vs_m->Draw();

 TGraph *beta_observed_vs_m = new TGraph(2*nPts, m_observed, beta_observed);
 beta_observed_vs_m->SetLineWidth(3);
 beta_observed_vs_m->SetLineColor(kBlack);
 beta_observed_vs_m->SetFillColor(kYellow);
 beta_observed_vs_m->Draw();

 gPad->RedrawAxis();

 TLegend *legend = new TLegend(.17,.6,.43,.75);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetTextFont(132);
 legend->SetMargin(0.15);
 legend->SetHeader("LQ#bar{LQ} #rightarrow e#nujj");
//  legend->AddEntry(gr_excl,"D#oslash exclusion (1 fb^{-1})","f");
 legend->AddEntry(beta_expected_vs_m,"Expected limit","l");
 legend->AddEntry(beta_observed_vs_m,"Observed limit  ","lf");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextFont(132);
 l1.SetNDC();
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.18,0.50,"CMS");
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.18,0.43,sqrts.c_str());
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.18,0.31,"#intLdt = 36 pb^{-1}");

 c->SetGridx();
 c->SetGridy();
 c->SetLogy(0);
 c->SaveAs(fileName.c_str());

 delete legend;
 delete beta_observed_vs_m;
 delete beta_expected_vs_m;
 delete beta_observed_vs_m_band;
 delete gr_excl;
 delete xsTh_vs_m_log;
 delete xsTh_upper_vs_m_log;
 delete xsTh_lower_vs_m_log;
 delete xsUp_expected_vs_m_log;
 delete xsUp_observed_vs_m_log;
 delete bg;
 delete c;
}

void fill_arrays(const Double_t fMass_min, const Double_t fMass_max, const Int_t fNPts, const TSpline3& fGS_xsUp_vs_m, const TSpline3& fGS_xsTh_vs_m, Double_t* x, Double_t* y)
{
 Double_t mass_max = fMass_min;

 if( (exp(fGS_xsUp_vs_m.Eval(fMass_min))/exp(fGS_xsTh_vs_m.Eval(fMass_min)))<0.5 ) {
   Int_t iteration = 0;
   for(Int_t i=0; i<100; i++) {
     Double_t delta_1 = (fMass_max-fMass_min)/(100-1);
     Double_t mass = fMass_min+delta_1*i;
     if( (exp(fGS_xsUp_vs_m.Eval(mass))/exp(fGS_xsTh_vs_m.Eval(mass)))>0.5 ) {
       iteration = i;
//        cout<<"iteration: "<<iteration<<endl;
       Double_t delta_2 = ((fMass_min+delta_1*i)-(fMass_min+delta_1*(i-1)))/(100-1);
       for(Int_t j=0; j<100; j++) {
         mass = (fMass_min+delta_1*(i-1))+delta_2*j;
         if( (exp(fGS_xsUp_vs_m.Eval(mass))/exp(fGS_xsTh_vs_m.Eval(mass)))>0.5 ) {
           mass_max = (fMass_min+delta_1*(i-1))+delta_2*j;
//            cout<<"mass_max: "<<mass_max<<endl;
           break;
         }
       }
       break;
     }
   }
   if( iteration==0 ) {
     mass_max = fMass_max;
//      cout<<"iteration: "<<99<<endl;
//      cout<<"mass_max: "<<mass_max<<endl;
   }
 }

 Double_t step = (mass_max-fMass_min)/(fNPts-1);

 Double_t A = (mass_max-fMass_min)/(1-1/fNPts)+fMass_min;
 Double_t B = (mass_max-fMass_min)/(1-1/fNPts);

 for(Int_t i=0; i<fNPts; i++) {
   x[i] = fMass_min+step*i;
   x[2*fNPts-i-1] = x[i];
   Double_t r = exp(fGS_xsUp_vs_m.Eval(x[i]))/exp(fGS_xsTh_vs_m.Eval(x[i]));
   if(r<0.5) {
     y[i] = 0.5*(1-sqrt(1-2*r));
     y[2*fNPts-i-1] = 0.5*(1+sqrt(1-2*r));
   } else {
     y[i] = 0.5;
     y[2*fNPts-i-1] = 0.5;
   }
 }
}

void myStyle()
{
 gStyle->Reset("Default");
 gStyle->SetCanvasColor(0);
 gStyle->SetPadColor(0);
 gStyle->SetTitleFillColor(10);
 gStyle->SetCanvasBorderMode(0);
 gStyle->SetStatColor(0);
 gStyle->SetPadBorderMode(0);
 gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
 gStyle->SetPadTickY(1);
 gStyle->SetFrameBorderMode(0);
 gStyle->SetPalette(1);

   //gStyle->SetOptStat(kFALSE);
 gStyle->SetOptStat(111110);
 gStyle->SetOptFit(0);
 gStyle->SetStatFont(42);
 gStyle->SetPadLeftMargin(0.13);
 gStyle->SetPadRightMargin(0.07);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
 gStyle->SetStatY(.9);
}

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo:
  tdrStyle->SetHistFillColor(63);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

//  tdrStyle->SetEndErrorSize(0);
//   tdrStyle->SetErrorX(0.);
//  tdrStyle->SetErrorMarker(20);

  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

  // For the Global title:

  //  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(132, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(132, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  // tdrStyle->SetPaperSize(15.,15.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();
}
