#include "CLA.C"
#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TLegend.h"
#include "TPolyLine.h"
#include "TPad.h"
#include "TLatex.h"

using namespace std;

void style()
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
 gStyle->SetOptFit(1);
 gStyle->SetStatFont(42);
 gStyle->SetPadLeftMargin(0.13);
 gStyle->SetPadRightMargin(0.07);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
 gStyle->SetStatY(.9);
}

void makePlots()
{
 // **********************************************
 // *            Input parameters                *
 // **********************************************
 // switch to include/exclude sytematics uncertainties 

 // array of signal efficiencies
  Double_t S_eff[3] = {0.13, 0.43, 0.58};
 
 // array of N_background for 50 nb^-1
 Double_t N_bkg_20[3] = {0.0325, 0.0215, 0.0177};
 
 // array of LQ masses for calculation of upXS
 Double_t m_Data[3] = {100,200,300};

 // arrays of leptoquark masses for th. cross section
 Double_t m[12] = {100, 150, 200, 250, 300};

 // array of theoretical cross-sections for different leptoquark masses
 Double_t xsTh[12] = {386, 53.3, 11.9, 3.47, 1.21};
  
 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "xs95CL_vs_m.eps";
  
 // axes labels for the final plot  
 string title = ";m (GeV/c^{2});#beta^{2}#times#sigma (pb)";

 TH2F *bg = new TH2F("bg",title.c_str(), 100, 80., 320., 100, 0.01, 2000.);
 bg->SetStats(kFALSE);
 bg->SetTitleOffset(1.,"X");
 bg->SetTitleOffset(1.5,"Y");

 // region excluded by Tevatron limits
 Double_t x_shaded[5] = {80,299,299,80,80};
 Double_t y_shaded[5] = {0.01,0.01,2000,2000,0.01};

 // PDF uncertainty band
 Double_t x_pdf[10] = {100,150,200,250,300,300,250,200,150,100};
 Double_t y_pdf[10] = {444,60.8,13.5,3.93,1.37,1.04,2.99,10.2,45.9,333};

 // **********************************************
 // *  Don't change anything below this point!   *
 // **********************************************

  // turn on/off batch mode
 gROOT->SetBatch(kTRUE);
 // set ROOT style
 style();
 
 TCanvas *c = new TCanvas("c","",800,800);
 c->cd();
 
 bg->Draw();

 TPolyLine *pl = new TPolyLine(5,x_shaded,y_shaded,"F");
//  pl->SetFillStyle(3001);   
 pl->SetFillColor(kGray+1);   
 pl->Draw();

 TGraph *grshade = new TGraph(10,x_pdf,y_pdf);
 grshade->SetFillColor(kYellow);
 grshade->Draw("f");

 gPad->RedrawAxis();
 
 Int_t size = sizeof(S_eff)/sizeof(*S_eff);

 // Upper Limits can be entered manually here when the call to CLA.C is commented below
 // Array of 95% CL upper limits on the cross section
//  Double_t xsUp[3] = {0.23722, 0.166074, 0.10131};
//  Double_t m_Data[3] = {100,200,300};

 Double_t xsUp[3];
 for(Int_t i = 0; i < size; i++){
  
  xsUp[i] = CLA(1, 0, S_eff[i], 0, N_bkg_20[i], 0);
 }

 TGraph *xsTh_vs_m = new TGraph(5, m, xsTh);
 xsTh_vs_m->SetLineWidth(2);
 xsTh_vs_m->SetLineColor(kRed);
 xsTh_vs_m->SetFillColor(kYellow);
 xsTh_vs_m->SetMarkerSize(1.);
 xsTh_vs_m->SetMarkerStyle(22);
 xsTh_vs_m->SetMarkerColor(kRed);
 xsTh_vs_m->Draw("C");

 TGraph *xsData_vs_m = new TGraph(size, m_Data, xsUp);
 xsData_vs_m->SetMarkerStyle(20);
 xsData_vs_m->SetMarkerColor(6);
 xsData_vs_m->SetLineColor(kYellow);
 xsData_vs_m->SetLineWidth(2);
 xsData_vs_m->SetLineStyle(9);
 xsData_vs_m->SetMarkerSize(1.5);
 xsData_vs_m->Draw("P");


 TLegend *legend = new TLegend(.40,.69,.93,.90);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetMargin(0.15);
 legend->SetHeader("LQ #rightarrow eq");
 legend->AddEntry(pl,"Tevatron exclusion (250 pb^{-1})","f");
 legend->AddEntry(xsTh_vs_m,"#beta^{2}#times #sigma_{theory} with PDF unc. band, #beta=1","lf");
 legend->AddEntry(xsData_vs_m, "MC @ 7TeV - 95% C.L. upper limit, L=20 nb-1","p");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextSize(0.04);
 l1.SetTextFont(62);
 l1.SetNDC();
 l1.DrawLatex(0.6,0.64,"CMS Preliminary");

 TLatex l2;
 l2.SetTextAlign(12);
 l2.SetTextSize(0.04);
 l2.SetTextFont(62);
 l2.SetNDC();
 l2.DrawLatex(0.6,0.55,"#intLdt=20 pb^{-1}");

 TLatex l3;
 l3.SetTextAlign(12);
 l3.SetTextSize(0.037);
 l3.SetTextFont(62);
 l3.SetNDC();
 l3.DrawLatex(0.4,0.485,"EXO-10-005 scaled to #sqrt{s} = 7 TeV");

 c->SetGridx();
 c->SetGridy();

 string name, extension;
 size_t pos = fileName.find(".");

 name = fileName.substr(0,pos);
 extension = fileName.substr(pos);

 c->SetLogy();
 c->SaveAs((name + "_log" + extension).c_str());

 delete pl;
 delete xsTh_vs_m;
 delete bg;
 delete c;
}
