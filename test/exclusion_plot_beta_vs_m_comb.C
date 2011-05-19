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
 Double_t m_enujj_observed[100] = {200, 202.457, 204.914, 207.371, 209.828, 212.285, 214.742, 217.199, 219.656, 222.114, 224.571, 227.028, 229.485, 231.942, 234.399, 236.856, 239.313, 241.77, 244.227, 246.684, 249.141, 251.598, 254.055, 256.512, 258.969, 261.426, 263.884, 266.341, 268.798, 271.255, 273.712, 276.169, 278.626, 281.083, 283.54, 285.997, 288.454, 290.911, 293.368, 295.825, 298.282, 300.739, 303.196, 305.654, 308.111, 310.568, 313.025, 315.482, 317.939, 320.396, 320.396, 317.939, 315.482, 313.025, 310.568, 308.111, 305.654, 303.196, 300.739, 298.282, 295.825, 293.368, 290.911, 288.454, 285.997, 283.54, 281.083, 278.626, 276.169, 273.712, 271.255, 268.798, 266.341, 263.884, 261.426, 258.969, 256.512, 254.055, 251.598, 249.141, 246.684, 244.227, 241.77, 239.313, 236.856, 234.399, 231.942, 229.485, 227.028, 224.571, 222.114, 219.656, 217.199, 214.742, 212.285, 209.828, 207.371, 204.914, 202.457, 200};
 Double_t beta_enujj_observed[100] = {0.0460222, 0.0445886, 0.0436087, 0.0430318, 0.042821, 0.0429499, 0.0434007, 0.0441627, 0.0452311, 0.0466058, 0.0482912, 0.0502948, 0.0526274, 0.055302, 0.0583334, 0.0617377, 0.0655312, 0.0697303, 0.0743495, 0.0794011, 0.0848936, 0.0908294, 0.097204, 0.104003, 0.111199, 0.11875, 0.126597, 0.134657, 0.142824, 0.150964, 0.158914, 0.166481, 0.173443, 0.179565, 0.184802, 0.189382, 0.193601, 0.197805, 0.202384, 0.207783, 0.214524, 0.223244, 0.234502, 0.248563, 0.265797, 0.286797, 0.312574, 0.345107, 0.389539, 0.5, 0.5, 0.610461, 0.654893, 0.687426, 0.713203, 0.734203, 0.751437, 0.765498, 0.776756, 0.785476, 0.792217, 0.797616, 0.802195, 0.806399, 0.810618, 0.815198, 0.820435, 0.826557, 0.833519, 0.841086, 0.849036, 0.857176, 0.865343, 0.873403, 0.88125, 0.888801, 0.895997, 0.902796, 0.909171, 0.915106, 0.920599, 0.925651, 0.93027, 0.934469, 0.938262, 0.941667, 0.944698, 0.947373, 0.949705, 0.951709, 0.953394, 0.954769, 0.955837, 0.956599, 0.95705, 0.957179, 0.956968, 0.956391, 0.955411, 0.953978};
 Double_t m_enujj_expected[100] = {200, 202.46, 204.919, 207.379, 209.839, 212.299, 214.758, 217.218, 219.678, 222.138, 224.597, 227.057, 229.517, 231.976, 234.436, 236.896, 239.356, 241.815, 244.275, 246.735, 249.194, 251.654, 254.114, 256.574, 259.033, 261.493, 263.953, 266.413, 268.872, 271.332, 273.792, 276.251, 278.711, 281.171, 283.631, 286.09, 288.55, 291.01, 293.47, 295.929, 298.389, 300.849, 303.308, 305.768, 308.228, 310.688, 313.147, 315.607, 318.067, 320.526, 320.526, 318.067, 315.607, 313.147, 310.688, 308.228, 305.768, 303.308, 300.849, 298.389, 295.929, 293.47, 291.01, 288.55, 286.09, 283.631, 281.171, 278.711, 276.251, 273.792, 271.332, 268.872, 266.413, 263.953, 261.493, 259.033, 256.574, 254.114, 251.654, 249.194, 246.735, 244.275, 241.815, 239.356, 236.896, 234.436, 231.976, 229.517, 227.057, 224.597, 222.138, 219.678, 217.218, 214.758, 212.299, 209.839, 207.379, 204.919, 202.46, 200};
 Double_t beta_enujj_expected[100] = {0.0587323, 0.0604527, 0.0622606, 0.0641596, 0.0661534, 0.068246, 0.0704417, 0.0727449, 0.07516, 0.0776921, 0.0803461, 0.0831273, 0.0860414, 0.0890941, 0.0922916, 0.0956404, 0.0991472, 0.102819, 0.106664, 0.110689, 0.114903, 0.119314, 0.123933, 0.128768, 0.133832, 0.139134, 0.144688, 0.150507, 0.156604, 0.162995, 0.169699, 0.176732, 0.184116, 0.191874, 0.200035, 0.208629, 0.217696, 0.22728, 0.237434, 0.248223, 0.259729, 0.272052, 0.285346, 0.299844, 0.315885, 0.333979, 0.354975, 0.380503, 0.414701, 0.5, 0.5, 0.585299, 0.619497, 0.645025, 0.666021, 0.684115, 0.700156, 0.714654, 0.727948, 0.740271, 0.751777, 0.762566, 0.77272, 0.782304, 0.791371, 0.799965, 0.808126, 0.815884, 0.823268, 0.830301, 0.837005, 0.843396, 0.849493, 0.855312, 0.860866, 0.866168, 0.871232, 0.876067, 0.880686, 0.885097, 0.889311, 0.893336, 0.897181, 0.900853, 0.90436, 0.907708, 0.910906, 0.913959, 0.916873, 0.919654, 0.922308, 0.92484, 0.927255, 0.929558, 0.931754, 0.933847, 0.93584, 0.937739, 0.939547, 0.941268};
 // combined limits
 Double_t beta_comb_observed[22] = {0.046875, 0.06, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[22] = {200.000, 234.313, 246.434, 255.28, 272.574, 297.123, 309.795, 317.141, 323.079, 328.864, 334.068, 340.006, 346.22, 352.586, 358.984, 364.616, 368.534, 371.074, 374.197, 377.227, 380.165, 384.42};
 Double_t beta_comb_expected[21] = {0.060759, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_expected[21] = {200.000, 221.855, 237.741, 265.075, 284.451, 299.847, 312.335, 322.559, 331.129, 338.414, 344.567, 349.954, 354.729, 359.106, 363.147, 367.003, 370.707, 374.656, 378.88, 384.022, 390.603};

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
