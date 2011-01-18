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
 Double_t m_enujj_observed[100] = {200, 202.431, 204.861, 207.292, 209.723, 212.154, 214.584, 217.015, 219.446, 221.877, 224.307, 226.738, 229.169, 231.6, 234.03, 236.461, 238.892, 241.323, 243.753, 246.184, 248.615, 251.046, 253.476, 255.907, 258.338, 260.768, 263.199, 265.63, 268.061, 270.491, 272.922, 275.353, 277.784, 280.214, 282.645, 285.076, 287.507, 289.937, 292.368, 294.799, 297.23, 299.66, 302.091, 304.522, 306.953, 309.383, 311.814, 314.245, 316.675, 319.106, 319.106, 316.675, 314.245, 311.814, 309.383, 306.953, 304.522, 302.091, 299.66, 297.23, 294.799, 292.368, 289.937, 287.507, 285.076, 282.645, 280.214, 277.784, 275.353, 272.922, 270.491, 268.061, 265.63, 263.199, 260.768, 258.338, 255.907, 253.476, 251.046, 248.615, 246.184, 243.753, 241.323, 238.892, 236.461, 234.03, 231.6, 229.169, 226.738, 224.307, 221.877, 219.446, 217.015, 214.584, 212.154, 209.723, 207.292, 204.861, 202.431, 200};
 Double_t beta_enujj_observed[100] = {0.0483783, 0.0468024, 0.0457053, 0.0450323, 0.0447429, 0.0448083, 0.0452084, 0.0459311, 0.0469699, 0.0483241, 0.0499968, 0.0519952, 0.0543297, 0.0570128, 0.0600595, 0.063486, 0.067309, 0.0715453, 0.0762108, 0.0813188, 0.0868794, 0.0928974, 0.0993707, 0.106288, 0.113626, 0.121348, 0.129399, 0.137701, 0.146155, 0.154631, 0.162972, 0.170988, 0.178457, 0.185132, 0.190852, 0.195782, 0.200207, 0.204465, 0.208941, 0.214071, 0.22036, 0.228417, 0.238939, 0.252312, 0.268891, 0.28926, 0.314424, 0.346362, 0.390213, 0.5, 0.5, 0.609787, 0.653638, 0.685576, 0.71074, 0.731109, 0.747688, 0.761061, 0.771583, 0.77964, 0.785929, 0.791059, 0.795535, 0.799793, 0.804218, 0.809148, 0.814868, 0.821543, 0.829012, 0.837028, 0.845369, 0.853845, 0.862299, 0.870601, 0.878652, 0.886374, 0.893712, 0.900629, 0.907103, 0.913121, 0.918681, 0.923789, 0.928455, 0.932691, 0.936514, 0.93994, 0.942987, 0.94567, 0.948005, 0.950003, 0.951676, 0.95303, 0.954069, 0.954792, 0.955192, 0.955257, 0.954968, 0.954295, 0.953198, 0.951622};
 Double_t m_enujj_expected[100] = {200, 202.422, 204.845, 207.267, 209.69, 212.112, 214.534, 216.957, 219.379, 221.802, 224.224, 226.647, 229.069, 231.491, 233.914, 236.336, 238.759, 241.181, 243.603, 246.026, 248.448, 250.871, 253.293, 255.715, 258.138, 260.56, 262.983, 265.405, 267.827, 270.25, 272.672, 275.095, 277.517, 279.94, 282.362, 284.784, 287.207, 289.629, 292.052, 294.474, 296.896, 299.319, 301.741, 304.164, 306.586, 309.008, 311.431, 313.853, 316.276, 318.698, 318.698, 316.276, 313.853, 311.431, 309.008, 306.586, 304.164, 301.741, 299.319, 296.896, 294.474, 292.052, 289.629, 287.207, 284.784, 282.362, 279.94, 277.517, 275.095, 272.672, 270.25, 267.827, 265.405, 262.983, 260.56, 258.138, 255.715, 253.293, 250.871, 248.448, 246.026, 243.603, 241.181, 238.759, 236.336, 233.914, 231.491, 229.069, 226.647, 224.224, 221.802, 219.379, 216.957, 214.534, 212.112, 209.69, 207.267, 204.845, 202.422, 200};
 Double_t beta_enujj_expected[100] = {0.0616954, 0.063582, 0.0655469, 0.0675934, 0.069725, 0.0719452, 0.0742579, 0.076667, 0.0791767, 0.0817914, 0.0845158, 0.0873547, 0.0903132, 0.0933969, 0.0966114, 0.0999628, 0.103458, 0.107103, 0.110905, 0.114873, 0.119014, 0.123338, 0.127854, 0.132573, 0.137505, 0.142663, 0.14806, 0.15371, 0.159631, 0.165838, 0.172353, 0.179197, 0.186394, 0.193972, 0.201964, 0.210404, 0.219329, 0.228787, 0.238831, 0.249527, 0.260959, 0.273228, 0.286476, 0.300921, 0.316901, 0.334925, 0.355837, 0.381262, 0.415331, 0.5, 0.5, 0.584669, 0.618738, 0.644163, 0.665075, 0.683099, 0.699079, 0.713524, 0.726772, 0.739041, 0.750473, 0.761169, 0.771213, 0.780671, 0.789596, 0.798036, 0.806028, 0.813606, 0.820803, 0.827647, 0.834162, 0.840369, 0.84629, 0.85194, 0.857337, 0.862495, 0.867427, 0.872146, 0.876662, 0.880986, 0.885127, 0.889095, 0.892897, 0.896542, 0.900037, 0.903389, 0.906603, 0.909687, 0.912645, 0.915484, 0.918209, 0.920823, 0.923333, 0.925742, 0.928055, 0.930275, 0.932407, 0.934453, 0.936418, 0.938305};
 // combined limits
 Double_t beta_comb_observed[22] = {0.049189, 0.06, 0.08, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
 Double_t m_comb_observed[22] = {200.000, 234.282, 246.036, 254.76, 271.748, 295.562, 308.938, 316.713, 322.712, 328.038, 333.486, 338.965, 345.761, 352.831, 359.259, 363.636, 367.646, 371.074, 374.166, 376.309, 379.308, 383.716};

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
