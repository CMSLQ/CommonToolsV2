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
 Double_t m_enujj_observed[100] = {200, 202.456, 204.911, 207.367, 209.823, 212.279, 214.734, 217.19, 219.646, 222.102, 224.557, 227.013, 229.469, 231.924, 234.38, 236.836, 239.292, 241.747, 244.203, 246.659, 249.115, 251.57, 254.026, 256.482, 258.937, 261.393, 263.849, 266.305, 268.76, 271.216, 273.672, 276.128, 278.583, 281.039, 283.495, 285.95, 288.406, 290.862, 293.318, 295.773, 298.229, 300.685, 303.14, 305.596, 308.052, 310.508, 312.963, 315.419, 317.875, 320.331, 320.331, 317.875, 315.419, 312.963, 310.508, 308.052, 305.596, 303.14, 300.685, 298.229, 295.773, 293.318, 290.862, 288.406, 285.95, 283.495, 281.039, 278.583, 276.128, 273.672, 271.216, 268.76, 266.305, 263.849, 261.393, 258.937, 256.482, 254.026, 251.57, 249.115, 246.659, 244.203, 241.747, 239.292, 236.836, 234.38, 231.924, 229.469, 227.013, 224.557, 222.102, 219.646, 217.19, 214.734, 212.279, 209.823, 207.367, 204.911, 202.456, 200};
 Double_t beta_enujj_observed[100] = {0.0463838, 0.044945, 0.0439609, 0.0433809, 0.043168, 0.0432958, 0.0437463, 0.0445088, 0.0455783, 0.0469548, 0.0486423, 0.0506484, 0.0529837, 0.0556609, 0.0586947, 0.0621011, 0.0658963, 0.0700961, 0.0747153, 0.0797659, 0.085256, 0.0911882, 0.0975578, 0.10435, 0.111539, 0.119081, 0.126919, 0.13497, 0.143128, 0.151262, 0.159208, 0.166776, 0.173746, 0.179883, 0.185135, 0.189729, 0.19396, 0.198172, 0.202754, 0.20815, 0.214878, 0.223576, 0.234806, 0.248841, 0.266045, 0.287011, 0.312744, 0.345215, 0.389541, 0.5, 0.5, 0.610459, 0.654785, 0.687256, 0.712989, 0.733955, 0.751159, 0.765194, 0.776424, 0.785122, 0.79185, 0.797246, 0.801828, 0.80604, 0.810271, 0.814865, 0.820117, 0.826254, 0.833224, 0.840792, 0.848738, 0.856872, 0.86503, 0.873081, 0.880919, 0.888461, 0.89565, 0.902442, 0.908812, 0.914744, 0.920234, 0.925285, 0.929904, 0.934104, 0.937899, 0.941305, 0.944339, 0.947016, 0.949352, 0.951358, 0.953045, 0.954422, 0.955491, 0.956254, 0.956704, 0.956832, 0.956619, 0.956039, 0.955055, 0.953616};
 Double_t m_enujj_expected[100] = {200, 202.458, 204.917, 207.375, 209.834, 212.292, 214.75, 217.209, 219.667, 222.126, 224.584, 227.042, 229.501, 231.959, 234.417, 236.876, 239.334, 241.793, 244.251, 246.709, 249.168, 251.626, 254.085, 256.543, 259.001, 261.46, 263.918, 266.377, 268.835, 271.293, 273.752, 276.21, 278.669, 281.127, 283.585, 286.044, 288.502, 290.96, 293.419, 295.877, 298.336, 300.794, 303.252, 305.711, 308.169, 310.628, 313.086, 315.544, 318.003, 320.461, 320.461, 318.003, 315.544, 313.086, 310.628, 308.169, 305.711, 303.252, 300.794, 298.336, 295.877, 293.419, 290.96, 288.502, 286.044, 283.585, 281.127, 278.669, 276.21, 273.752, 271.293, 268.835, 266.377, 263.918, 261.46, 259.001, 256.543, 254.085, 251.626, 249.168, 246.709, 244.251, 241.793, 239.334, 236.876, 234.417, 231.959, 229.501, 227.042, 224.584, 222.126, 219.667, 217.209, 214.75, 212.292, 209.834, 207.375, 204.917, 202.458, 200};
 Double_t beta_enujj_expected[100] = {0.0590938, 0.0608221, 0.0626373, 0.0645431, 0.0665431, 0.0686415, 0.0708423, 0.0731499, 0.0755689, 0.0781041, 0.0807606, 0.0835436, 0.0864587, 0.0895117, 0.0927087, 0.0960561, 0.0995608, 0.10323, 0.107071, 0.111091, 0.1153, 0.119705, 0.124317, 0.129145, 0.1342, 0.139494, 0.145039, 0.150848, 0.156936, 0.163319, 0.170013, 0.177038, 0.184415, 0.192168, 0.200324, 0.208916, 0.217982, 0.227566, 0.237721, 0.248511, 0.260018, 0.272341, 0.285632, 0.300124, 0.316153, 0.334231, 0.355203, 0.380696, 0.414834, 0.5, 0.5, 0.585166, 0.619304, 0.644797, 0.665769, 0.683847, 0.699876, 0.714368, 0.727659, 0.739982, 0.751489, 0.762279, 0.772434, 0.782018, 0.791084, 0.799676, 0.807832, 0.815585, 0.822962, 0.829987, 0.836681, 0.843064, 0.849152, 0.854961, 0.860506, 0.8658, 0.870855, 0.875683, 0.880295, 0.8847, 0.888909, 0.892929, 0.89677, 0.900439, 0.903944, 0.907291, 0.910488, 0.913541, 0.916456, 0.919239, 0.921896, 0.924431, 0.92685, 0.929158, 0.931359, 0.933457, 0.935457, 0.937363, 0.939178, 0.940906};
 // combined limits
 Double_t beta_comb_observed[22] = {0.046875, 0.06, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[22] = {200.000, 234.313, 246.434, 255.28, 272.574, 297.123, 309.795, 317.141, 323.079, 328.864, 334.068, 340.006, 346.22, 352.586, 358.984, 364.616, 368.534, 371.074, 374.197, 377.227, 380.165, 384.42};

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_comb.eps";

 // axes labels for the final plot
 string title = ";M_{LQ} [GeV];#beta";

 // integrated luminosity
 string sqrts = "#sqrt{s}=7 TeV";

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
 beta_vs_m_eejj_observed->SetLineStyle(2);
 beta_vs_m_eejj_observed->Draw("C");

 TPolyLine *beta_vs_m_enujj_observed = new TPolyLine(100, m_enujj_observed, beta_enujj_observed);
 beta_vs_m_enujj_observed->SetLineWidth(3);
 beta_vs_m_enujj_observed->SetLineColor(kBlue);
 beta_vs_m_enujj_observed->SetLineStyle(4);
 beta_vs_m_enujj_observed->Draw("C");

 TGraph *beta_vs_m_comb_observed = new TGraph(22, m_comb_observed, beta_comb_observed);
 beta_vs_m_comb_observed->SetLineWidth(3);
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
 l2.SetTextColor(kBlue);
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
