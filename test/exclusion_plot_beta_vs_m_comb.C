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
 Double_t beta_eejj_observed[50] = {0.19334, 0.197135, 0.201812, 0.207359, 0.213773, 0.22105, 0.229191, 0.238192, 0.248049, 0.258754, 0.270292, 0.282638, 0.29576, 0.309611, 0.324129, 0.339236, 0.354836, 0.37081, 0.387019, 0.403299, 0.419467, 0.435472, 0.451473, 0.467675, 0.484313, 0.501652, 0.519836, 0.538861, 0.558709, 0.579359, 0.60078, 0.622914, 0.645677, 0.668971, 0.69268, 0.716687, 0.741022, 0.765813, 0.79121, 0.817373, 0.844486, 0.872752, 0.902394, 0.933424, 0.965485, 0.998134, 1.03087, 1.06311, 1.09424, 1.12356};
 Double_t beta_eejj_expected[50] = {0.241229, 0.249665, 0.258252, 0.266998, 0.275909, 0.284993, 0.29426, 0.30372, 0.313385, 0.323268, 0.333384, 0.343748, 0.354377, 0.365293, 0.376514, 0.388066, 0.399974, 0.412264, 0.424969, 0.438119, 0.451751, 0.465884, 0.480511, 0.495624, 0.511209, 0.527252, 0.543723, 0.560581, 0.577778, 0.595259, 0.61297, 0.630946, 0.649307, 0.668187, 0.687738, 0.708113, 0.729349, 0.751399, 0.774208, 0.797705, 0.821807, 0.846418, 0.871434, 0.896802, 0.922564, 0.948779, 0.975511, 1.00283, 1.03082, 1.05955};
 // enujj limits
 Double_t m_enujj_observed[100] = {200, 202.029, 204.058, 206.087, 208.116, 210.145, 212.174, 214.203, 216.232, 218.261, 220.289, 222.318, 224.347, 226.376, 228.405, 230.434, 232.463, 234.492, 236.521, 238.55, 240.579, 242.608, 244.637, 246.666, 248.695, 250.724, 252.753, 254.782, 256.811, 258.839, 260.868, 262.897, 264.926, 266.955, 268.984, 271.013, 273.042, 275.071, 277.1, 279.129, 281.158, 283.187, 285.216, 287.245, 289.274, 291.303, 293.332, 295.361, 297.389, 299.418, 299.418, 297.389, 295.361, 293.332, 291.303, 289.274, 287.245, 285.216, 283.187, 281.158, 279.129, 277.1, 275.071, 273.042, 271.013, 268.984, 266.955, 264.926, 262.897, 260.868, 258.839, 256.811, 254.782, 252.753, 250.724, 248.695, 246.666, 244.637, 242.608, 240.579, 238.55, 236.521, 234.492, 232.463, 230.434, 228.405, 226.376, 224.347, 222.318, 220.289, 218.261, 216.232, 214.203, 212.174, 210.145, 208.116, 206.087, 204.058, 202.029, 200};
 Double_t beta_enujj_observed[100] = {0.0664215, 0.0644765, 0.0630191, 0.0619986, 0.0613758, 0.0611208, 0.0612115, 0.0616322, 0.0623726, 0.0634272, 0.0647944, 0.0664763, 0.0684784, 0.0708087, 0.0734782, 0.0765003, 0.0798903, 0.0836658, 0.0878458, 0.0924512, 0.0975037, 0.103026, 0.109042, 0.115574, 0.122645, 0.130276, 0.138488, 0.147297, 0.156716, 0.166751, 0.177402, 0.188661, 0.200505, 0.212898, 0.225784, 0.239081, 0.252677, 0.266419, 0.280101, 0.293451, 0.306137, 0.318066, 0.329457, 0.340661, 0.352183, 0.364745, 0.379437, 0.398132, 0.425124, 0.5, 0.5, 0.574876, 0.601868, 0.620563, 0.635255, 0.647817, 0.659339, 0.670543, 0.681934, 0.693863, 0.706549, 0.719899, 0.733581, 0.747323, 0.760919, 0.774216, 0.787102, 0.799495, 0.811339, 0.822598, 0.833249, 0.843284, 0.852703, 0.861512, 0.869724, 0.877355, 0.884426, 0.890958, 0.896974, 0.902496, 0.907549, 0.912154, 0.916334, 0.92011, 0.9235, 0.926522, 0.929191, 0.931522, 0.933524, 0.935206, 0.936573, 0.937627, 0.938368, 0.938788, 0.938879, 0.938624, 0.938001, 0.936981, 0.935523, 0.933579};
 Double_t m_enujj_expected[100] = {200, 202.401, 204.802, 207.204, 209.605, 212.006, 214.407, 216.808, 219.21, 221.611, 224.012, 226.413, 228.815, 231.216, 233.617, 236.018, 238.419, 240.821, 243.222, 245.623, 248.024, 250.425, 252.827, 255.228, 257.629, 260.03, 262.432, 264.833, 267.234, 269.635, 272.036, 274.438, 276.839, 279.24, 281.641, 284.042, 286.444, 288.845, 291.246, 293.647, 296.049, 298.45, 300.851, 303.252, 305.653, 308.055, 310.456, 312.857, 315.258, 317.659, 317.659, 315.258, 312.857, 310.456, 308.055, 305.653, 303.252, 300.851, 298.45, 296.049, 293.647, 291.246, 288.845, 286.444, 284.042, 281.641, 279.24, 276.839, 274.438, 272.036, 269.635, 267.234, 264.833, 262.432, 260.03, 257.629, 255.228, 252.827, 250.425, 248.024, 245.623, 243.222, 240.821, 238.419, 236.018, 233.617, 231.216, 228.815, 226.413, 224.012, 221.611, 219.21, 216.808, 214.407, 212.006, 209.605, 207.204, 204.802, 202.401, 200};
 Double_t beta_enujj_expected[100] = {0.0645899, 0.0665075, 0.0684946, 0.0705541, 0.0726893, 0.0749036, 0.0772006, 0.0795842, 0.0820584, 0.0846274, 0.087296, 0.0900689, 0.0929514, 0.095949, 0.0990675, 0.102313, 0.105693, 0.109215, 0.112886, 0.116714, 0.120709, 0.124882, 0.129242, 0.133801, 0.138573, 0.143572, 0.148814, 0.154316, 0.160097, 0.166179, 0.172586, 0.179346, 0.186491, 0.194055, 0.202081, 0.210603, 0.219655, 0.229274, 0.239505, 0.2504, 0.262023, 0.274455, 0.287799, 0.302242, 0.318125, 0.335968, 0.356635, 0.381772, 0.415545, 0.5, 0.5, 0.584455, 0.618228, 0.643365, 0.664032, 0.681875, 0.697758, 0.712201, 0.725545, 0.737977, 0.7496, 0.760495, 0.770726, 0.780345, 0.789397, 0.797919, 0.805945, 0.813509, 0.820654, 0.827414, 0.833821, 0.839903, 0.845684, 0.851186, 0.856428, 0.861427, 0.866199, 0.870758, 0.875118, 0.879291, 0.883286, 0.887114, 0.890785, 0.894307, 0.897687, 0.900932, 0.904051, 0.907049, 0.909931, 0.912704, 0.915373, 0.917942, 0.920416, 0.922799, 0.925096, 0.927311, 0.929446, 0.931505, 0.933492, 0.93541};
 // combined limits
 Double_t beta_comb_observed[21] = {0.066942, 0.07, 0.118947, 0.167895, 0.216842, 0.265789, 0.314737, 0.363684, 0.412632, 0.461579, 0.510526, 0.559474, 0.608421, 0.657368, 0.706316, 0.755263, 0.804211, 0.853158, 0.902105, 0.951053, 1};
 Double_t m_comb_observed[21] = {200.000, 226.263, 249.526, 262.534, 273.278, 288.154, 302.204, 309.244, 314.448, 319.223, 323.508, 328.099, 332.293, 336.731, 342.118, 347.903, 354.637, 361.279, 367.983, 374.503, 384.542};

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_comb.eps";

 // axes labels for the final plot
 string title = ";m [GeV];#beta";

  // integrated luminosity
 string lint = "#intLdt=33.2 pb^{-1}";

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

 TGraph *beta_vs_m_comb_observed = new TGraph(21, m_comb_observed, beta_comb_observed);
 beta_vs_m_comb_observed->SetLineWidth(2);
 beta_vs_m_comb_observed->SetLineColor(kBlack);
 beta_vs_m_comb_observed->Draw("C");

 gPad->RedrawAxis();

 TLegend *legend = new TLegend(.48,.35,.91,.57);
 legend->SetBorderSize(1);
 legend->SetFillColor(0);
 //legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetMargin(0.15);
//  legend->SetHeader("LQ#bar{LQ} #rightarrow e#nuqq");
 legend->AddEntry(gr_D0_excl,"D#oslash exclusion (1 fb^{-1})","f");
 legend->AddEntry(beta_vs_m_eejj_observed,"eejj 95% C.L. limit (obs.)","l");
 legend->AddEntry(beta_vs_m_enujj_observed,"e#nujj 95% C.L. limit (obs.)","l");
 legend->AddEntry(beta_vs_m_comb_observed,"Combined 95% C.L. limit (obs.)","l");
 legend->Draw();

 TLatex l1;
 l1.SetTextAlign(12);
 l1.SetTextSize(0.04);
 l1.SetTextFont(42);
 l1.SetNDC();
 l1.DrawLatex(0.60,0.3,"CMS 2010");
 l1.DrawLatex(0.60,0.2,lint.c_str());

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
