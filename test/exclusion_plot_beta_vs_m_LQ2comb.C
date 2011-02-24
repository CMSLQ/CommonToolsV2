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

 // mumujj limits
 Double_t m_mumujj[50] = {200, 204.49, 208.98, 213.469, 217.959, 222.449, 226.939, 231.429, 235.918, 240.408, 244.898, 249.388, 253.878, 258.367, 262.857, 267.347, 271.837, 276.327, 280.816, 285.306, 289.796, 294.286, 298.776, 303.265, 307.755, 312.245, 316.735, 321.224, 325.714, 330.204, 334.694, 339.184, 343.673, 348.163, 352.653, 357.143, 361.633, 366.122, 370.612, 375.102, 379.592, 384.082, 388.571, 393.061, 397.551, 402.041, 406.531, 411.02, 415.51, 420};
 Double_t beta_mumujj_observed[50] = {0.191851, 0.194661, 0.199559, 0.206439, 0.215225, 0.225851, 0.238249, 0.252331, 0.267974, 0.285, 0.303165, 0.322142, 0.341545, 0.361149, 0.380788, 0.400274, 0.4194, 0.43794, 0.455656, 0.472466, 0.488713, 0.504871, 0.521485, 0.539082, 0.557363, 0.575473, 0.592443, 0.607209, 0.619417, 0.630183, 0.640885, 0.653, 0.667949, 0.686048, 0.707116, 0.73096, 0.757357, 0.786049, 0.816731, 0.849036, 0.88253, 0.916698, 0.950944, 0.984586, 1.01686, 1.04693, 1.07442, 1.09951, 1.12246, 1.14361};
 Double_t beta_mumujj_expected[50] = {0.241668, 0.251374, 0.26103, 0.270664, 0.28031, 0.290012, 0.299821, 0.309796, 0.320006, 0.330528, 0.341449, 0.352868, 0.364879, 0.377503, 0.390727, 0.404535, 0.418903, 0.433804, 0.449202, 0.46505, 0.481273, 0.497785, 0.514485, 0.531274, 0.548159, 0.565217, 0.582538, 0.600225, 0.618381, 0.637101, 0.656489, 0.676658, 0.697724, 0.719733, 0.742697, 0.766619, 0.791498, 0.817325, 0.844089, 0.871773, 0.900355, 0.929805, 0.96009, 0.991168, 1.02299, 1.0555, 1.08866, 1.12251, 1.15704, 1.1923};
 // munujj limits
 Double_t m_munujj_observed[100] = {200, 201.368, 202.735, 204.103, 205.47, 206.838, 208.206, 209.573, 210.941, 212.309, 213.676, 215.044, 216.411, 217.779, 219.147, 220.514, 221.882, 223.25, 224.617, 225.985, 227.352, 228.72, 230.088, 231.455, 232.823, 234.191, 235.558, 236.926, 238.293, 239.661, 241.029, 242.396, 243.764, 245.132, 246.499, 247.867, 249.234, 250.602, 251.97, 253.337, 254.705, 256.073, 257.44, 258.808, 260.175, 261.543, 262.911, 264.278, 265.646, 267.014, 267.014, 265.646, 264.278, 262.911, 261.543, 260.175, 258.808, 257.44, 256.073, 254.705, 253.337, 251.97, 250.602, 249.234, 247.867, 246.499, 245.132, 243.764, 242.396, 241.029, 239.661, 238.293, 236.926, 235.558, 234.191, 232.823, 231.455, 230.088, 228.72, 227.352, 225.985, 224.617, 223.25, 221.882, 220.514, 219.147, 217.779, 216.411, 215.044, 213.676, 212.309, 210.941, 209.573, 208.206, 206.838, 205.47, 204.103, 202.735, 201.368, 200};
 Double_t beta_munujj_observed[100] = {0.110055, 0.10943, 0.109011, 0.108791, 0.108765, 0.108926, 0.109271, 0.109796, 0.1105, 0.111382, 0.112441, 0.113677, 0.115092, 0.116689, 0.118469, 0.120436, 0.122594, 0.124949, 0.127505, 0.130271, 0.133252, 0.136457, 0.139896, 0.143577, 0.147513, 0.151716, 0.156198, 0.160976, 0.166064, 0.171483, 0.177251, 0.183393, 0.189932, 0.196899, 0.204326, 0.212252, 0.22072, 0.229782, 0.239502, 0.249954, 0.261234, 0.27346, 0.286792, 0.301444, 0.317723, 0.336099, 0.357361, 0.383044, 0.417117, 0.5, 0.5, 0.582883, 0.616956, 0.642639, 0.663901, 0.682277, 0.698556, 0.713208, 0.72654, 0.738766, 0.750046, 0.760498, 0.770218, 0.77928, 0.787748, 0.795674, 0.803101, 0.810068, 0.816607, 0.822749, 0.828517, 0.833936, 0.839024, 0.843802, 0.848284, 0.852487, 0.856423, 0.860104, 0.863543, 0.866748, 0.869729, 0.872495, 0.875051, 0.877406, 0.879564, 0.881531, 0.883311, 0.884908, 0.886323, 0.887559, 0.888618, 0.8895, 0.890204, 0.890729, 0.891074, 0.891235, 0.891209, 0.890989, 0.89057, 0.889945};
 Double_t m_munujj_expected[100] = {200, 202.317, 204.635, 206.952, 209.27, 211.587, 213.905, 216.222, 218.54, 220.857, 223.175, 225.492, 227.81, 230.127, 232.445, 234.762, 237.079, 239.397, 241.714, 244.032, 246.349, 248.667, 250.984, 253.302, 255.619, 257.937, 260.254, 262.572, 264.889, 267.206, 269.524, 271.841, 274.159, 276.476, 278.794, 281.111, 283.429, 285.746, 288.064, 290.381, 292.699, 295.016, 297.334, 299.651, 301.968, 304.286, 306.603, 308.921, 311.238, 313.556, 313.556, 311.238, 308.921, 306.603, 304.286, 301.968, 299.651, 297.334, 295.016, 292.699, 290.381, 288.064, 285.746, 283.429, 281.111, 278.794, 276.476, 274.159, 271.841, 269.524, 267.206, 264.889, 262.572, 260.254, 257.937, 255.619, 253.302, 250.984, 248.667, 246.349, 244.032, 241.714, 239.397, 237.079, 234.762, 232.445, 230.127, 227.81, 225.492, 223.175, 220.857, 218.54, 216.222, 213.905, 211.587, 209.27, 206.952, 204.635, 202.317, 200};
 Double_t beta_munujj_expected[100] = {0.0627425, 0.0648851, 0.0670872, 0.0693511, 0.0716791, 0.0740739, 0.0765384, 0.0790756, 0.0816888, 0.0843815, 0.0871576, 0.0900213, 0.0929769, 0.0960294, 0.099184, 0.102446, 0.105823, 0.10932, 0.112944, 0.116705, 0.120611, 0.12467, 0.128894, 0.133293, 0.137882, 0.142673, 0.147682, 0.152927, 0.158427, 0.164203, 0.17028, 0.176686, 0.183453, 0.190616, 0.198218, 0.206309, 0.214939, 0.224161, 0.23404, 0.244651, 0.256091, 0.268481, 0.28198, 0.296803, 0.313262, 0.331847, 0.353382, 0.379465, 0.414181, 0.5, 0.5, 0.585819, 0.620535, 0.646618, 0.668153, 0.686738, 0.703197, 0.71802, 0.731519, 0.743909, 0.755349, 0.76596, 0.775839, 0.785061, 0.793691, 0.801782, 0.809384, 0.816547, 0.823314, 0.82972, 0.835797, 0.841573, 0.847073, 0.852318, 0.857327, 0.862118, 0.866707, 0.871106, 0.87533, 0.879389, 0.883295, 0.887056, 0.89068, 0.894177, 0.897554, 0.900816, 0.903971, 0.907023, 0.909979, 0.912842, 0.915618, 0.918311, 0.920924, 0.923462, 0.925926, 0.928321, 0.930649, 0.932913, 0.935115, 0.937257};
 // combined limits
 Double_t beta_comb_observed[20] = {0.108694, 0.12, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[20] = {200.000, 222.069, 236.517, 249.893, 258.8, 266.269, 273.125, 279.278, 285.981, 296.174, 333.272, 340.006, 346.556, 352.036, 357.882, 364.708, 370.952, 377.564, 385.736, 395.347};

 // filename for the final plot (NB: changing the name extension changes the file format)
 string fileName = "beta_vs_m_excl_LQ2comb.eps";

 // axes labels for the final plot
 string title = ";M_{LQ} [GeV];#beta";

  // integrated luminosity
 string lint = "#intLdt=34, 36 pb^{-1}";

 // region excluded by Tevatron limits (1 fb-1)
 // MuMuJJ + MuNuJJ
 Double_t x_excl[12] = {100, 152, 170, 200 ,230, 241, 252, 271, 286, 302, 316, 100 };
 Double_t y_excl[12] = {0.0, 0.05, 0.07, 0.13, 0.21, 0.27, 0.35, 0.52, 0.67, 0.82, 1.0, 1};
 // NuNuJJ
 Double_t x_excl_nunujj[6] = {147, 188 , 202, 210, 214, 147};
 Double_t y_excl_nunujj[6] = {0.15, 0.13, .125, .025, 0.0, 0.0};

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

 TGraph *gr_D0_excl = new TGraph(12,x_excl,y_excl);
 gr_D0_excl->SetLineColor(0);
 gr_D0_excl->SetFillColor(kGray);
 gr_D0_excl->Draw("f");

 TGraph *gr_D0_excl_nunujj = new TGraph(6,x_excl_nunujj,y_excl_nunujj);
 gr_D0_excl_nunujj->SetLineColor(0);
 gr_D0_excl_nunujj->SetFillColor(kBlack);
 gr_D0_excl_nunujj->SetFillStyle(3002);
//  gr_D0_excl_nunujj->Draw("f");

 TGraph *beta_vs_m_mumujj_observed = new TGraph(50, m_mumujj, beta_mumujj_observed);
 beta_vs_m_mumujj_observed->SetLineWidth(2);
 beta_vs_m_mumujj_observed->SetLineStyle(2);
 beta_vs_m_mumujj_observed->Draw("C");

 TPolyLine *beta_vs_m_munujj_observed = new TPolyLine(100, m_munujj_observed, beta_munujj_observed);
 beta_vs_m_munujj_observed->SetLineWidth(2);
 beta_vs_m_munujj_observed->SetLineStyle(4);
 beta_vs_m_munujj_observed->Draw("C");

 TGraph *beta_vs_m_comb_observed = new TGraph(20, m_comb_observed, beta_comb_observed);
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
//  legend->AddEntry(gr_D0_excl,"#mu#mujj+#mu#nujj D#oslash exclusion (1 fb^{-1})","f");
//  legend->AddEntry(gr_D0_excl_nunujj,"#nu#nujj D#oslash exclusion (1 fb^{-1})","f");
 legend->AddEntry(beta_vs_m_mumujj_observed,"#mu#mujj 95% C.L. limit (obs., 34 pb^{-1})","l");
 legend->AddEntry(beta_vs_m_munujj_observed,"#mu#nujj 95% C.L. limit (obs., 36 pb^{-1})","l");
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
 delete beta_vs_m_mumujj_observed;
 delete beta_vs_m_munujj_observed;
 delete beta_vs_m_comb_observed;
 delete gr_D0_excl;
 delete bg;
 delete c;
}
