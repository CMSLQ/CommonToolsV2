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
 Double_t m_enujj_observed[100] = {200, 202.439, 204.878, 207.317, 209.756, 212.195, 214.634, 217.073, 219.513, 221.952, 224.391, 226.83, 229.269, 231.708, 234.147, 236.586, 239.025, 241.464, 243.903, 246.342, 248.781, 251.22, 253.659, 256.099, 258.538, 260.977, 263.416, 265.855, 268.294, 270.733, 273.172, 275.611, 278.05, 280.489, 282.928, 285.367, 287.806, 290.246, 292.685, 295.124, 297.563, 300.002, 302.441, 304.88, 307.319, 309.758, 312.197, 314.636, 317.075, 319.514, 319.514, 317.075, 314.636, 312.197, 309.758, 307.319, 304.88, 302.441, 300.002, 297.563, 295.124, 292.685, 290.246, 287.806, 285.367, 282.928, 280.489, 278.05, 275.611, 273.172, 270.733, 268.294, 265.855, 263.416, 260.977, 258.538, 256.099, 253.659, 251.22, 248.781, 246.342, 243.903, 241.464, 239.025, 236.586, 234.147, 231.708, 229.269, 226.83, 224.391, 221.952, 219.513, 217.073, 214.634, 212.195, 209.756, 207.317, 204.878, 202.439, 200};
 Double_t beta_enujj_observed[100] = {0.0464746, 0.0450426, 0.0440626, 0.0434846, 0.0432719, 0.0433985, 0.0438466, 0.0446056, 0.0456707, 0.0470419, 0.0487232, 0.0507225, 0.0530503, 0.0557197, 0.0587455, 0.062144, 0.0659319, 0.0701257, 0.074741, 0.0797907, 0.0852845, 0.0912267, 0.0976147, 0.104436, 0.111669, 0.119273, 0.127195, 0.135356, 0.143659, 0.151973, 0.160144, 0.167984, 0.175275, 0.181779, 0.187369, 0.192231, 0.196649, 0.200959, 0.205542, 0.210831, 0.217332, 0.225657, 0.23647, 0.250107, 0.266934, 0.287545, 0.312954, 0.345157, 0.389317, 0.5, 0.5, 0.610683, 0.654843, 0.687046, 0.712455, 0.733066, 0.749893, 0.76353, 0.774343, 0.782668, 0.789169, 0.794458, 0.799041, 0.803351, 0.807769, 0.812631, 0.818221, 0.824725, 0.832016, 0.839856, 0.848027, 0.856341, 0.864644, 0.872805, 0.880727, 0.888331, 0.895564, 0.902385, 0.908773, 0.914715, 0.920209, 0.925259, 0.929874, 0.934068, 0.937856, 0.941255, 0.94428, 0.94695, 0.949277, 0.951277, 0.952958, 0.954329, 0.955394, 0.956153, 0.956602, 0.956728, 0.956515, 0.955937, 0.954957, 0.953525};
 Double_t m_enujj_expected[100] = {200, 202.427, 204.855, 207.282, 209.71, 212.137, 214.564, 216.992, 219.419, 221.847, 224.274, 226.701, 229.129, 231.556, 233.984, 236.411, 238.839, 241.266, 243.693, 246.121, 248.548, 250.976, 253.403, 255.83, 258.258, 260.685, 263.113, 265.54, 267.967, 270.395, 272.822, 275.25, 277.677, 280.104, 282.532, 284.959, 287.387, 289.814, 292.241, 294.669, 297.096, 299.524, 301.951, 304.379, 306.806, 309.233, 311.661, 314.088, 316.516, 318.943, 318.943, 316.516, 314.088, 311.661, 309.233, 306.806, 304.379, 301.951, 299.524, 297.096, 294.669, 292.241, 289.814, 287.387, 284.959, 282.532, 280.104, 277.677, 275.25, 272.822, 270.395, 267.967, 265.54, 263.113, 260.685, 258.258, 255.83, 253.403, 250.976, 248.548, 246.121, 243.693, 241.266, 238.839, 236.411, 233.984, 231.556, 229.129, 226.701, 224.274, 221.847, 219.419, 216.992, 214.564, 212.137, 209.71, 207.282, 204.855, 202.427, 200};
 Double_t beta_enujj_expected[100] = {0.0595571, 0.0612904, 0.0631109, 0.0650222, 0.0670281, 0.0691325, 0.0713398, 0.0736541, 0.07608, 0.0786225, 0.0812865, 0.0840773, 0.0870004, 0.0900617, 0.0932673, 0.0966236, 0.100137, 0.103816, 0.107666, 0.111696, 0.115915, 0.12033, 0.124952, 0.129791, 0.134857, 0.140161, 0.145717, 0.151537, 0.157635, 0.164028, 0.170733, 0.177769, 0.185156, 0.192919, 0.201085, 0.209687, 0.218763, 0.22836, 0.238531, 0.249343, 0.260879, 0.273244, 0.286579, 0.301107, 0.317159, 0.335242, 0.356192, 0.381624, 0.415646, 0.5, 0.5, 0.584354, 0.618376, 0.643808, 0.664758, 0.682841, 0.698893, 0.713421, 0.726756, 0.739121, 0.750657, 0.761469, 0.77164, 0.781237, 0.790313, 0.798915, 0.807081, 0.814844, 0.822231, 0.829267, 0.835972, 0.842365, 0.848463, 0.854283, 0.859839, 0.865143, 0.870209, 0.875048, 0.87967, 0.884085, 0.888304, 0.892334, 0.896184, 0.899863, 0.903376, 0.906733, 0.909938, 0.913, 0.915923, 0.918714, 0.921377, 0.92392, 0.926346, 0.92866, 0.930867, 0.932972, 0.934978, 0.936889, 0.93871, 0.940443};
 // combined limits
 Double_t beta_comb_observed[22] = {0.046875, 0.06, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[22] = {200.000, 234.313, 246.434, 255.28, 272.574, 297.123, 309.795, 317.141, 323.079, 328.864, 334.068, 340.006, 346.22, 352.586, 358.984, 364.616, 368.534, 371.074, 374.197, 377.227, 380.165, 384.42};

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_comb.eps";

 // axes labels for the final plot
 string title = ";M_{LQ} [GeV];#beta";

  // integrated luminosity
 string lint = "#intLdt=33.2, 36 pb^{-1}";

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
 beta_vs_m_eejj_observed->SetLineWidth(2);
 beta_vs_m_eejj_observed->SetLineStyle(2);
 beta_vs_m_eejj_observed->Draw("C");

 TPolyLine *beta_vs_m_enujj_observed = new TPolyLine(100, m_enujj_observed, beta_enujj_observed);
 beta_vs_m_enujj_observed->SetLineWidth(2);
 beta_vs_m_enujj_observed->SetLineStyle(4);
 beta_vs_m_enujj_observed->Draw("C");

 TGraph *beta_vs_m_comb_observed = new TGraph(22, m_comb_observed, beta_comb_observed);
 beta_vs_m_comb_observed->SetLineWidth(2);
 beta_vs_m_comb_observed->SetLineColor(kBlack);
 beta_vs_m_comb_observed->Draw("C");

 gPad->RedrawAxis();

 TLegend *legend = new TLegend(.46,.15,.91,.37);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetMargin(0.15);
//  legend->SetHeader("LQ#bar{LQ} #rightarrow e#nuqq");
 legend->AddEntry(gr_D0_excl,"D#oslash exclusion (1 fb^{-1})","f");
 legend->AddEntry(beta_vs_m_eejj_observed,"eejj 95% C.L. limit (obs., 33.2 pb^{-1})","l");
 legend->AddEntry(beta_vs_m_enujj_observed,"e#nujj 95% C.L. limit (obs., 36 pb^{-1})","l");
 legend->AddEntry(beta_vs_m_comb_observed,"Combined 95% C.L. limit (obs.)","l");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextFont(42);
 l1.SetNDC();
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.54,0.53,"CMS 2010");
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.54,0.43,lint.c_str());

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
