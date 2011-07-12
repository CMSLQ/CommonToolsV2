#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TPolyLine.h"
#include "TF1.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLatex.h"
#include "TSpline.h"
#include "TFile.h"

using namespace std;

void myStyle();
void setTDRStyle();

void makePlots()
{
 // **********************************************
 // *            Input parameters                *
 // **********************************************

 // eejj limits
 Double_t m_eejj[50] = {200, 204.082, 208.163, 212.245, 216.327, 220.408, 224.49, 228.571, 232.653, 236.735, 240.816, 244.898, 248.98, 253.061, 257.143, 261.224, 265.306, 269.388, 273.469, 277.551, 281.633, 285.714, 289.796, 293.878, 297.959, 302.041, 306.122, 310.204, 314.286, 318.367, 322.449, 326.531, 330.612, 334.694, 338.776, 342.857, 346.939, 351.02, 355.102, 359.184, 363.265, 367.347, 371.429, 375.51, 379.592, 383.673, 387.755, 391.837, 395.918, 400};
 Double_t beta_eejj_observed[50] = {0.192489, 0.19659, 0.201503, 0.207225, 0.213753, 0.22109, 0.229236, 0.238191, 0.247955, 0.258521, 0.269878, 0.282008, 0.294884, 0.308466, 0.322705, 0.337534, 0.352872, 0.36862, 0.384659, 0.400849, 0.417033, 0.433163, 0.449359, 0.465779, 0.482607, 0.50005, 0.518231, 0.537171, 0.556886, 0.577391, 0.598696, 0.620759, 0.643492, 0.666788, 0.690524, 0.714573, 0.738955, 0.763793, 0.78923, 0.815419, 0.842533, 0.870765, 0.900329, 0.931232, 0.963129, 0.99559, 1.02813, 1.06019, 1.09116, 1.12037};
 Double_t beta_eejj_expected[50] = {0.245939, 0.253519, 0.261428, 0.269668, 0.278244, 0.287156, 0.296408, 0.306, 0.315931, 0.326199, 0.336802, 0.347735, 0.35899, 0.370562, 0.382438, 0.394609, 0.40706, 0.419774, 0.432735, 0.445919, 0.459306, 0.472926, 0.486888, 0.501318, 0.516357, 0.532157, 0.548729, 0.565929, 0.583583, 0.601491, 0.619447, 0.637443, 0.655653, 0.674277, 0.693538, 0.713666, 0.734725, 0.75667, 0.779442, 0.802968, 0.827162, 0.851925, 0.877147, 0.902767, 0.928813, 0.955325, 0.98235, 1.00994, 1.03814, 1.06702};
 // enujj limits
 Double_t m_enujj_observed[100] = {200, 202.449, 204.897, 207.346, 209.795, 212.244, 214.692, 217.141, 219.59, 222.039, 224.487, 226.936, 229.385, 231.833, 234.282, 236.731, 239.18, 241.628, 244.077, 246.526, 248.975, 251.423, 253.872, 256.321, 258.77, 261.218, 263.667, 266.116, 268.564, 271.013, 273.462, 275.911, 278.359, 280.808, 283.257, 285.706, 288.154, 290.603, 293.052, 295.5, 297.949, 300.398, 302.847, 305.295, 307.744, 310.193, 312.642, 315.09, 317.539, 319.988, 319.988, 317.539, 315.09, 312.642, 310.193, 307.744, 305.295, 302.847, 300.398, 297.949, 295.5, 293.052, 290.603, 288.154, 285.706, 283.257, 280.808, 278.359, 275.911, 273.462, 271.013, 268.564, 266.116, 263.667, 261.218, 258.77, 256.321, 253.872, 251.423, 248.975, 246.526, 244.077, 241.628, 239.18, 236.731, 234.282, 231.833, 229.385, 226.936, 224.487, 222.039, 219.59, 217.141, 214.692, 212.244, 209.795, 207.346, 204.897, 202.449, 200};
 Double_t beta_enujj_observed[100] = {0.0483783, 0.0468404, 0.0457771, 0.0451348, 0.0448738, 0.0449659, 0.0453917, 0.0461392, 0.0472024, 0.0485804, 0.0502766, 0.0522982, 0.054655, 0.0573596, 0.0604263, 0.0638706, 0.0677085, 0.0719556, 0.0766263, 0.0817324, 0.0872818, 0.0932769, 0.0997127, 0.106575, 0.113836, 0.121454, 0.129369, 0.137501, 0.145742, 0.153961, 0.161993, 0.169647, 0.176701, 0.182915, 0.188207, 0.192794, 0.196974, 0.201093, 0.205543, 0.210766, 0.21728, 0.225715, 0.236682, 0.250469, 0.26744, 0.288182, 0.3137, 0.345972, 0.390135, 0.5, 0.5, 0.609865, 0.654028, 0.6863, 0.711818, 0.73256, 0.749531, 0.763318, 0.774285, 0.78272, 0.789234, 0.794457, 0.798907, 0.803026, 0.807206, 0.811793, 0.817085, 0.823299, 0.830353, 0.838007, 0.846039, 0.854258, 0.862499, 0.870631, 0.878546, 0.886164, 0.893425, 0.900287, 0.906723, 0.912718, 0.918268, 0.923374, 0.928044, 0.932292, 0.936129, 0.939574, 0.94264, 0.945345, 0.947702, 0.949723, 0.95142, 0.952798, 0.953861, 0.954608, 0.955034, 0.955126, 0.954865, 0.954223, 0.95316, 0.951622};
 Double_t m_enujj_expected[100] = {200, 202.45, 204.9, 207.35, 209.8, 212.25, 214.7, 217.15, 219.6, 222.051, 224.501, 226.951, 229.401, 231.851, 234.301, 236.751, 239.201, 241.651, 244.101, 246.551, 249.001, 251.451, 253.901, 256.351, 258.801, 261.252, 263.702, 266.152, 268.602, 271.052, 273.502, 275.952, 278.402, 280.852, 283.302, 285.752, 288.202, 290.652, 293.102, 295.552, 298.002, 300.453, 302.903, 305.353, 307.803, 310.253, 312.703, 315.153, 317.603, 320.053, 320.053, 317.603, 315.153, 312.703, 310.253, 307.803, 305.353, 302.903, 300.453, 298.002, 295.552, 293.102, 290.652, 288.202, 285.752, 283.302, 280.852, 278.402, 275.952, 273.502, 271.052, 268.602, 266.152, 263.702, 261.252, 258.801, 256.351, 253.901, 251.451, 249.001, 246.551, 244.101, 241.651, 239.201, 236.751, 234.301, 231.851, 229.401, 226.951, 224.501, 222.051, 219.6, 217.15, 214.7, 212.25, 209.8, 207.35, 204.9, 202.45, 200};
 Double_t beta_enujj_expected[100] = {0.0611536, 0.0629179, 0.0647676, 0.0667064, 0.068738, 0.0708661, 0.0730949, 0.0754286, 0.0778717, 0.0804288, 0.083105, 0.0859054, 0.0888353, 0.0919006, 0.0951071, 0.0984613, 0.10197, 0.105639, 0.109478, 0.113493, 0.117693, 0.122086, 0.126682, 0.131492, 0.136526, 0.141795, 0.147312, 0.153091, 0.159146, 0.165494, 0.172152, 0.17914, 0.18648, 0.194197, 0.202318, 0.210876, 0.219908, 0.229458, 0.239576, 0.250327, 0.261789, 0.27406, 0.287284, 0.301692, 0.317619, 0.335572, 0.356395, 0.381704, 0.415609, 0.5, 0.5, 0.584391, 0.618296, 0.643605, 0.664428, 0.682381, 0.698308, 0.712716, 0.72594, 0.738211, 0.749673, 0.760424, 0.770542, 0.780092, 0.789124, 0.797682, 0.805803, 0.81352, 0.82086, 0.827848, 0.834506, 0.840854, 0.846909, 0.852688, 0.858205, 0.863474, 0.868508, 0.873318, 0.877914, 0.882307, 0.886507, 0.890522, 0.894361, 0.89803, 0.901539, 0.904893, 0.908099, 0.911165, 0.914095, 0.916895, 0.919571, 0.922128, 0.924571, 0.926905, 0.929134, 0.931262, 0.933294, 0.935232, 0.937082, 0.938846};
 // combined limits
 Double_t beta_comb_observed[22] = {0.050781, 0.06, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[22] = {200.000, 232.14, 245.21, 254.209, 271.656, 295.439, 308.968, 316.743, 322.712, 328.038, 333.456, 338.996, 344.965, 352.801, 358.8, 363.545, 367.646, 371.074, 373.768, 376.309, 379.614, 384.083};
 Double_t beta_comb_expected[21] = {0.062179, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_expected[21] = {200.000, 220.08, 236.333, 263.851, 283.379, 298.929, 311.662, 321.916, 330.517, 337.772, 344.169, 349.617, 354.454, 358.8, 362.718, 366.636, 370.37, 374.533, 378.696, 383.93, 390.572};
 
 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_comb.eps";

 // axes labels for the final plot
 string title = ";M_{LQ} [GeV];#beta";

 // integrated luminosity
 string sqrts = "#sqrt{s} = 7 TeV";

 // region excluded by Tevatron limits (1 fb-1)
 Double_t x_excl[13] = {200,214.39,235.13,254.08,268.12,275.92,283.95,289.08,293.09,295.99,297.10,298.89,200};
 Double_t y_excl[13] = {0,0,0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,1,1};

 // turn on/off batch mode
 gROOT->SetBatch(kTRUE);
 // set ROOT style
//  myStyle();
 setTDRStyle();
//  gStyle->SetPadLeftMargin(0.14);
 gROOT->ForceStyle();

 TH2F *bg = new TH2F("bg",title.c_str(), 20, 200., 500., 100, 0., 1.);
 bg->SetStats(kFALSE);
 bg->SetTitleOffset(1.,"X");
 bg->SetTitleOffset(1.05,"Y");
//  bg->GetXaxis()->SetNdivisions(505);

 TCanvas *c = new TCanvas("c","",800,800);
 c->cd();

 bg->Draw();

 TGraph *gr_D0_excl = new TGraph(13,x_excl,y_excl);
 gr_D0_excl->SetLineColor(0);
 gr_D0_excl->SetFillColor(kGray);
 gr_D0_excl->Draw("f");

 TGraph *beta_vs_m_eejj_observed = new TGraph(50, m_eejj, beta_eejj_observed);
 beta_vs_m_eejj_observed->SetLineWidth(3);
 beta_vs_m_eejj_observed->SetLineColor(kGreen+2);
 beta_vs_m_eejj_observed->SetLineStyle(4);
 beta_vs_m_eejj_observed->Draw("C");

 TPolyLine *beta_vs_m_enujj_observed = new TPolyLine(100, m_enujj_observed, beta_enujj_observed);
 beta_vs_m_enujj_observed->SetLineWidth(3);
 beta_vs_m_enujj_observed->SetLineColor(kRed);
 beta_vs_m_enujj_observed->SetLineStyle(3);
 beta_vs_m_enujj_observed->Draw("C");

 TGraph *beta_vs_m_comb_observed = new TGraph(22, m_comb_observed, beta_comb_observed);
 beta_vs_m_comb_observed->SetLineWidth(3);
 beta_vs_m_comb_observed->SetLineColor(kBlack);
 beta_vs_m_comb_observed->Draw("C");

 TGraph *beta_vs_m_comb_expected = new TGraph(21, m_comb_expected, beta_comb_expected);
 beta_vs_m_comb_expected->SetLineWidth(3);
 beta_vs_m_comb_expected->SetLineColor(kBlue);
 beta_vs_m_comb_expected->SetLineStyle(2);
 beta_vs_m_comb_expected->Draw("C");

 gPad->RedrawAxis();

 TLegend *legend = new TLegend(.46,.15,.92,.37);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetMargin(0.15);
//  legend->SetHeader("LQ#bar{LQ} #rightarrow e#nuqq");
 legend->AddEntry(gr_D0_excl,"D#oslash exclusion (1 fb^{-1})","f");
 legend->AddEntry(beta_vs_m_eejj_observed,"eejj 95% CL limit (obs., 33.2 pb^{-1})","l");
 legend->AddEntry(beta_vs_m_enujj_observed,"e#nujj 95% CL limit (obs., 36 pb^{-1})","l");
 legend->AddEntry(beta_vs_m_comb_observed,"Combined 95% CL limit (obs.)","l");
 legend->AddEntry(beta_vs_m_comb_expected,"Combined 95% CL limit (exp.)","l");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextFont(42);
 l1.SetNDC();
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.70,0.50,"CMS");
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.70,0.43,sqrts.c_str());

 TLatex l2;
 l2.SetTextAlign(12);
 l2.SetTextFont(42);
 l2.SetNDC();
 l2.SetTextSize(0.04);
 l2.SetTextColor(kGreen+2);
 l2.SetTextAngle(59);
 l2.DrawLatex(0.49,0.72,"eejj");
 l2.SetTextColor(kRed);
 l2.SetTextAngle(-30);
 l2.DrawLatex(0.33,0.85,"e#nujj");

 c->SetGridx();
 c->SetGridy();
 c->SetLogy(0);
 c->SaveAs(fileName.c_str());

 delete legend;
 delete beta_vs_m_eejj_observed;
 delete beta_vs_m_enujj_observed;
 delete beta_vs_m_comb_observed;
 delete gr_D0_excl;
 delete bg;
 delete c;
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
