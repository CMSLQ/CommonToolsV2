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
 Double_t m_munujj_observed[100] = {200, 201.801, 203.601, 205.402, 207.203, 209.004, 210.804, 212.605, 214.406, 216.207, 218.007, 219.808, 221.609, 223.41, 225.21, 227.011, 228.812, 230.612, 232.413, 234.214, 236.015, 237.815, 239.616, 241.417, 243.218, 245.018, 246.819, 248.62, 250.421, 252.221, 254.022, 255.823, 257.623, 259.424, 261.225, 263.026, 264.826, 266.627, 268.428, 270.229, 272.029, 273.83, 275.631, 277.431, 279.232, 281.033, 282.834, 284.634, 286.435, 288.236, 288.236, 286.435, 284.634, 282.834, 281.033, 279.232, 277.431, 275.631, 273.83, 272.029, 270.229, 268.428, 266.627, 264.826, 263.026, 261.225, 259.424, 257.623, 255.823, 254.022, 252.221, 250.421, 248.62, 246.819, 245.018, 243.218, 241.417, 239.616, 237.815, 236.015, 234.214, 232.413, 230.612, 228.812, 227.011, 225.21, 223.41, 221.609, 219.808, 218.007, 216.207, 214.406, 212.605, 210.804, 209.004, 207.203, 205.402, 203.601, 201.801, 200};
 Double_t beta_munujj_observed[100] = {0.0869589, 0.0881285, 0.0894684, 0.0909798, 0.0926647, 0.0945256, 0.0965657, 0.0987886, 0.101199, 0.1038, 0.106599, 0.1096, 0.112811, 0.116236, 0.119884, 0.123761, 0.127874, 0.132233, 0.136844, 0.141716, 0.146859, 0.152279, 0.157987, 0.163991, 0.1703, 0.176923, 0.183869, 0.191147, 0.198766, 0.206734, 0.21506, 0.223752, 0.232818, 0.242266, 0.252104, 0.262339, 0.272979, 0.284031, 0.295505, 0.30741, 0.319758, 0.332563, 0.345847, 0.359641, 0.373992, 0.388991, 0.405038, 0.423163, 0.445988, 0.5, 0.5, 0.554012, 0.576837, 0.594962, 0.611009, 0.626008, 0.640359, 0.654153, 0.667437, 0.680242, 0.69259, 0.704495, 0.715969, 0.727021, 0.737661, 0.747896, 0.757734, 0.767182, 0.776248, 0.78494, 0.793266, 0.801234, 0.808853, 0.816131, 0.823077, 0.8297, 0.836009, 0.842013, 0.847721, 0.853141, 0.858284, 0.863156, 0.867767, 0.872126, 0.876239, 0.880116, 0.883764, 0.887189, 0.8904, 0.893401, 0.8962, 0.898801, 0.901211, 0.903434, 0.905474, 0.907335, 0.90902, 0.910532, 0.911872, 0.913041};
 Double_t m_munujj_expected[100] = {200, 202.173, 204.345, 206.518, 208.69, 210.863, 213.035, 215.208, 217.38, 219.553, 221.725, 223.898, 226.07, 228.243, 230.416, 232.588, 234.761, 236.933, 239.106, 241.278, 243.451, 245.623, 247.796, 249.968, 252.141, 254.313, 256.486, 258.659, 260.831, 263.004, 265.176, 267.349, 269.521, 271.694, 273.866, 276.039, 278.211, 280.384, 282.557, 284.729, 286.902, 289.074, 291.247, 293.419, 295.592, 297.764, 299.937, 302.109, 304.282, 306.454, 306.454, 304.282, 302.109, 299.937, 297.764, 295.592, 293.419, 291.247, 289.074, 286.902, 284.729, 282.557, 280.384, 278.211, 276.039, 273.866, 271.694, 269.521, 267.349, 265.176, 263.004, 260.831, 258.659, 256.486, 254.313, 252.141, 249.968, 247.796, 245.623, 243.451, 241.278, 239.106, 236.933, 234.761, 232.588, 230.416, 228.243, 226.07, 223.898, 221.725, 219.553, 217.38, 215.208, 213.035, 210.863, 208.69, 206.518, 204.345, 202.173, 200};
 Double_t beta_munujj_expected[100] = {0.0637112, 0.066806, 0.0699217, 0.0730536, 0.0761974, 0.0793496, 0.0825072, 0.0856678, 0.0888301, 0.0919936, 0.0951584, 0.0983259, 0.101498, 0.104679, 0.107873, 0.111085, 0.114322, 0.117593, 0.120906, 0.124274, 0.127707, 0.13122, 0.13483, 0.138553, 0.14241, 0.146423, 0.150618, 0.155023, 0.15967, 0.164595, 0.16984, 0.175453, 0.181489, 0.188012, 0.195097, 0.202836, 0.211338, 0.220736, 0.231161, 0.242675, 0.255343, 0.269241, 0.284465, 0.301145, 0.319461, 0.339693, 0.36232, 0.388425, 0.421632, 0.5, 0.5, 0.578368, 0.611575, 0.63768, 0.660307, 0.680539, 0.698855, 0.715535, 0.730759, 0.744657, 0.757325, 0.768839, 0.779264, 0.788662, 0.797164, 0.804903, 0.811988, 0.818511, 0.824547, 0.83016, 0.835405, 0.84033, 0.844977, 0.849382, 0.853577, 0.85759, 0.861447, 0.86517, 0.86878, 0.872293, 0.875726, 0.879094, 0.882407, 0.885678, 0.888915, 0.892127, 0.895321, 0.898502, 0.901674, 0.904842, 0.908006, 0.91117, 0.914332, 0.917493, 0.92065, 0.923803, 0.926946, 0.930078, 0.933194, 0.936289};
 // combined limits
 Double_t beta_comb_observed[20] = {0.088682, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[20] = {200.000, 211.081, 238.567, 254.209, 267.156, 280.9, 297.888, 308.418, 315.519, 322.436, 329.538, 336.945, 343.465, 349.311, 355.525, 361.586, 367.585, 375.023, 383.563, 395.317};

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
