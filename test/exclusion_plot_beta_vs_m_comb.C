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
 Double_t m_enujj_observed[100] = {200, 202.436, 204.871, 207.307, 209.743, 212.179, 214.614, 217.05, 219.486, 221.922, 224.357, 226.793, 229.229, 231.665, 234.1, 236.536, 238.972, 241.408, 243.843, 246.279, 248.715, 251.15, 253.586, 256.022, 258.458, 260.893, 263.329, 265.765, 268.201, 270.636, 273.072, 275.508, 277.944, 280.379, 282.815, 285.251, 287.687, 290.122, 292.558, 294.994, 297.429, 299.865, 302.301, 304.737, 307.172, 309.608, 312.044, 314.48, 316.915, 319.351, 319.351, 316.915, 314.48, 312.044, 309.608, 307.172, 304.737, 302.301, 299.865, 297.429, 294.994, 292.558, 290.122, 287.687, 285.251, 282.815, 280.379, 277.944, 275.508, 273.072, 270.636, 268.201, 265.765, 263.329, 260.893, 258.458, 256.022, 253.586, 251.15, 248.715, 246.279, 243.843, 241.408, 238.972, 236.536, 234.1, 231.665, 229.229, 226.793, 224.357, 221.922, 219.486, 217.05, 214.614, 212.179, 209.743, 207.307, 204.871, 202.436, 200};
 Double_t beta_enujj_observed[100] = {0.0473347, 0.0458643, 0.0448535, 0.044251, 0.0440195, 0.044132, 0.0445703, 0.0453232, 0.0463856, 0.047757, 0.0494413, 0.051446, 0.0537814, 0.0564604, 0.0594977, 0.0629093, 0.0667117, 0.0709214, 0.0755536, 0.0806213, 0.0861339, 0.0920958, 0.0985042, 0.105347, 0.112601, 0.120229, 0.128174, 0.136361, 0.144691, 0.153035, 0.161238, 0.169112, 0.176442, 0.182987, 0.188607, 0.193482, 0.197895, 0.202182, 0.206725, 0.211956, 0.218378, 0.226603, 0.237305, 0.250842, 0.267577, 0.288101, 0.313433, 0.345571, 0.389703, 0.5, 0.5, 0.610297, 0.654429, 0.686567, 0.711899, 0.732423, 0.749158, 0.762695, 0.773397, 0.781622, 0.788044, 0.793275, 0.797818, 0.802105, 0.806518, 0.811393, 0.817013, 0.823558, 0.830888, 0.838762, 0.846965, 0.855309, 0.863639, 0.871826, 0.879771, 0.887399, 0.894653, 0.901496, 0.907904, 0.913866, 0.919379, 0.924446, 0.929079, 0.933288, 0.937091, 0.940502, 0.94354, 0.946219, 0.948554, 0.950559, 0.952243, 0.953614, 0.954677, 0.95543, 0.955868, 0.95598, 0.955749, 0.955147, 0.954136, 0.952665};
 Double_t m_enujj_expected[100] = {200, 202.424, 204.848, 207.272, 209.696, 212.12, 214.544, 216.969, 219.393, 221.817, 224.241, 226.665, 229.089, 231.513, 233.937, 236.361, 238.785, 241.209, 243.633, 246.057, 248.482, 250.906, 253.33, 255.754, 258.178, 260.602, 263.026, 265.45, 267.874, 270.298, 272.722, 275.146, 277.57, 279.995, 282.419, 284.843, 287.267, 289.691, 292.115, 294.539, 296.963, 299.387, 301.811, 304.235, 306.659, 309.083, 311.507, 313.932, 316.356, 318.78, 318.78, 316.356, 313.932, 311.507, 309.083, 306.659, 304.235, 301.811, 299.387, 296.963, 294.539, 292.115, 289.691, 287.267, 284.843, 282.419, 279.995, 277.57, 275.146, 272.722, 270.298, 267.874, 265.45, 263.026, 260.602, 258.178, 255.754, 253.33, 250.906, 248.482, 246.057, 243.633, 241.209, 238.785, 236.361, 233.937, 231.513, 229.089, 226.665, 224.241, 221.817, 219.393, 216.969, 214.544, 212.12, 209.696, 207.272, 204.848, 202.424, 200};
 Double_t beta_enujj_expected[100] = {0.0604443, 0.0621977, 0.0640372, 0.0659664, 0.067989, 0.0701089, 0.0723303, 0.0746574, 0.0770948, 0.0796472, 0.0823196, 0.0851173, 0.0880456, 0.0911105, 0.0943179, 0.0976743, 0.101186, 0.104861, 0.108706, 0.112729, 0.116939, 0.121344, 0.125954, 0.130778, 0.135829, 0.141117, 0.146655, 0.152457, 0.158537, 0.164912, 0.171598, 0.178617, 0.18599, 0.193742, 0.2019, 0.210497, 0.219571, 0.229167, 0.239337, 0.250147, 0.261678, 0.27403, 0.28734, 0.301829, 0.317827, 0.33584, 0.356703, 0.382025, 0.415902, 0.5, 0.5, 0.584098, 0.617975, 0.643297, 0.66416, 0.682173, 0.698171, 0.71266, 0.72597, 0.738322, 0.749853, 0.760663, 0.770833, 0.780429, 0.789503, 0.7981, 0.806258, 0.81401, 0.821383, 0.828402, 0.835088, 0.841463, 0.847543, 0.853345, 0.858883, 0.864171, 0.869222, 0.874046, 0.878656, 0.883061, 0.887271, 0.891294, 0.895139, 0.898814, 0.902326, 0.905682, 0.908889, 0.911954, 0.914883, 0.91768, 0.920353, 0.922905, 0.925343, 0.92767, 0.929891, 0.932011, 0.934034, 0.935963, 0.937802, 0.939556};
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
 beta_vs_m_eejj_observed->SetLineColor(kGreen+2);
 beta_vs_m_eejj_observed->SetLineStyle(2);
 beta_vs_m_eejj_observed->Draw("C");

 TPolyLine *beta_vs_m_enujj_observed = new TPolyLine(100, m_enujj_observed, beta_enujj_observed);
 beta_vs_m_enujj_observed->SetLineWidth(2);
 beta_vs_m_enujj_observed->SetLineColor(kBlue);
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
 l1.SetTextSize(0.045);
 l1.DrawLatex(0.52,0.53,"CMS Preliminary 2010");
 l1.SetTextSize(0.05);
 l1.DrawLatex(0.52,0.43,lint.c_str());

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
