#include "cl95cms.C"
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
 gStyle->SetOptFit(1);
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
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
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

void makePlots()
{
 // **********************************************
 // *            Input parameters                *
 // **********************************************
 // switch to include/exclude sytematics uncertainties
 bool systematics = true; // does nothing at the moment

 // total integrated luminosity (in pb-1)
 Double_t L_int = 33.2;
 // relative uncertainty on the integrated luminosity (0.1 = 10% uncertainty)
 Double_t Sigma_L_int = 0.11;

 // array of signal efficiencies
 Double_t S_eff[10] = {0.297, 0.380, 0.403, 0.430, 0.451, 0.469, 0.496, 0.522, 0.539, 0.565};
 // array of relative uncertainties on the signal efficiencies (0.1 = 10%)
 Double_t Sigma_S_eff[10] = {0.105, 0.105, 0.105, 0.105, 0.105, 0.105, 0.105, 0.105, 0.105, 0.105};

 // array of N_background for L_int
 Double_t N_bkg[10] = {4.5, 2.5, 1.5, 1.3, 1.1, 0.89, 0.75, 0.62, 0.41, 0.32};
 // array of relative uncertainties on N_background (0.1 = 10%)
 Double_t Sigma_N_bkg[10] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25};

 // array of N_observed for L_int
 Double_t N_obs[10] = {2, 1, 1, 1, 1, 1, 1, 1, 0, 0};

 // array of LQ masses for calculation of upXS
 Double_t mData[10] = {200, 250, 280, 300, 320, 340, 370, 400, 450, 500};

 // arrays of LQ masses for theoretical cross section
 Double_t mTh[10] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550};
 // array of theoretical cross-sections for different leptoquark masses
 Double_t xsTh[10] = {386, 53.3, 11.9, 3.47, 1.21, 0.477, 0.205, 0.0949, 0.0463, 0.0236};

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "xs95CL_vs_m.eps";

 // axes labels for the final plot
 string title = ";m [GeV];#beta^{2}#times#sigma [pb]";

 // integrated luminosity
 string lint = "#intLdt=33.2 pb^{-1}";

 // region excluded by Tevatron limits
 Double_t x_shaded[5] = {200,299,299,200,200};
 Double_t y_shaded[5] = {0.01,0.01,100,100,0.01};

 // PDF uncertainty band
 Double_t x_pdf[20] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 550, 500, 450, 400, 350, 300, 250, 200, 150, 100};
 Double_t y_pdf[20] = {445.5, 61.4, 13.7, 4.1, 1.43, 0.572, 0.249, 0.1167, 0.0581, 0.0300, 0.0169, 0.0340, 0.0719, 0.160, 0.379, 0.98, 2.9, 10.0, 45.2, 330.3};

  // turn on/off batch mode
 gROOT->SetBatch(kTRUE);

 Int_t size = sizeof(S_eff)/sizeof(*S_eff);

 // Upper limits can be entered manually when the calls to CL95(...) and CLA(...) are commented below.
 // However, CL95(...) and CLA(...) have to be called at least once to get the upper limits

//  Double_t xsUp_observed[10];
//  for(Int_t i = 0; i < size; i++){
//
//    xsUp_observed[i] = CL95(L_int, L_int*Sigma_L_int, S_eff[i], S_eff[i]*Sigma_S_eff[i], N_bkg[i], N_bkg[i]*Sigma_N_bkg[i], N_obs[i], kFALSE, 1);
//  }
//  cout<<endl<<"Double_t xsUp_observed[10] = {";
//  for(Int_t i = 0; i < size; i++) {
//    cout<<xsUp_observed[i];
//    if(i<(size-1)) cout<<", ";
//  }
//  cout<<"};"<<endl<<endl;
 // Array of the observed 95% CL upper limits on the cross section
 Double_t xsUp_observed[10] = {0.444824, 0.310547, 0.309082, 0.293945, 0.284668, 0.279297, 0.268066, 0.258789, 0.174243, 0.166113};

//  Double_t xsUp_expected[10];
//  for(Int_t i = 0; i < size; i++){
//
//    xsUp_expected[i] = CLA(L_int, L_int*Sigma_L_int, S_eff[i], S_eff[i]*Sigma_S_eff[i], N_bkg[i], N_bkg[i]*Sigma_N_bkg[i], kFALSE, 1);
//  }
//  cout<<endl<<"Double_t xsUp_expected[10] = {";
//  for(Int_t i = 0; i < size; i++) {
//    cout<<xsUp_expected[i];
//    if(i<(size-1)) cout<<", ";
//  }
//  cout<<"};"<<endl<<endl;
 // Array of the expected 95% CL upper limits on the cross section
 Double_t xsUp_expected[10] = {0.692479, 0.442443, 0.360792, 0.326146, 0.298866, 0.274453, 0.250794, 0.230144, 0.208843, 0.192884};

 // set ROOT style
//  myStyle();
 setTDRStyle();
 gStyle->SetPadLeftMargin(0.14);
 gROOT->ForceStyle();

 TCanvas *c = new TCanvas("c","",800,800);
 c->cd();

 TH2F *bg = new TH2F("bg",title.c_str(), 100, 200., 500., 100, 0.01, 100.);
 bg->SetStats(kFALSE);
 bg->SetTitleOffset(1.,"X");
 bg->SetTitleOffset(1.13,"Y");
//  bg->GetXaxis()->SetNdivisions(505);

 bg->Draw();

 TPolyLine *pl = new TPolyLine(5,x_shaded,y_shaded,"F");
//  pl->SetFillStyle(3001);
 pl->SetLineColor(0);
 pl->SetFillColor(kGray);
 pl->Draw();

 TGraph *grshade = new TGraph(20,x_pdf,y_pdf);
 grshade->SetFillColor(kYellow);
 grshade->Draw("f");

 gPad->RedrawAxis();

 // set ROOT style
//  myStyle();
 setTDRStyle();
 gStyle->SetPadLeftMargin(0.14);
 gROOT->ForceStyle();

 TGraph *xsTh_vs_m = new TGraph(10, mTh, xsTh);
 xsTh_vs_m->SetLineWidth(2);
 xsTh_vs_m->SetLineColor(kRed);
 xsTh_vs_m->SetFillColor(kYellow);
 xsTh_vs_m->SetMarkerSize(1.);
 xsTh_vs_m->SetMarkerStyle(22);
 xsTh_vs_m->SetMarkerColor(kRed);
 xsTh_vs_m->Draw("C");

 TGraph *xsData_vs_m_expected = new TGraph(size, mData, xsUp_expected);
 xsData_vs_m_expected->SetMarkerStyle(23);
 xsData_vs_m_expected->SetMarkerColor(kBlue);
 xsData_vs_m_expected->SetLineColor(kBlue);
 xsData_vs_m_expected->SetLineWidth(2);
 xsData_vs_m_expected->SetLineStyle(2);
 xsData_vs_m_expected->SetMarkerSize(1.5);
 xsData_vs_m_expected->Draw("CP");

 TGraph *xsData_vs_m_observed = new TGraph(size, mData, xsUp_observed);
 xsData_vs_m_observed->SetMarkerStyle(22);
 xsData_vs_m_observed->SetMarkerColor(kBlack);
 xsData_vs_m_observed->SetLineColor(kBlack);
 xsData_vs_m_observed->SetLineWidth(2);
 xsData_vs_m_observed->SetLineStyle(1);
 xsData_vs_m_observed->SetMarkerSize(1.5);
 xsData_vs_m_observed->Draw("CP");

 TLegend *legend = new TLegend(.36,.65,.91,.92);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetMargin(0.15);
 legend->SetHeader("LQ #rightarrow eq");
 legend->AddEntry(pl,"D#oslash exclusion (1 fb^{-1}, #beta=1)","f");
 legend->AddEntry(xsTh_vs_m,"#beta^{2}#times#sigma_{theory} with theory uncertainty, #beta=1","lf");
 legend->AddEntry(xsData_vs_m_expected, "Expected 95% C.L. upper limit","lp");
 legend->AddEntry(xsData_vs_m_observed, "Observed 95% C.L. upper limit","lp");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextSize(0.05);
 l1.SetTextFont(42);
 l1.SetNDC();
 l1.DrawLatex(0.59,0.61,"CMS 2010");
 l1.DrawLatex(0.59,0.51,lint.c_str());

//  TLatex l2;
//  l2.SetTextAlign(12);
//  l2.SetTextSize(0.037);
//  l2.SetTextFont(42);
//  l2.SetNDC();
//  l2.DrawLatex(0.4,0.485,"EXO-10-005 scaled to #sqrt{s} = 7 TeV");

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
