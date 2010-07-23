/*
Ellie Twedt, June 2010
Description and instructions:
This is mean to run on the output of analysisClass_PDFweighting.C .
Change the name of the input file in this macro accordingly.

Usage: 
>root -l
>.L PDFvar.C
>RunPDF()

This produces an output of the bin with the largest variation from the central value (bin "1", 0th vector element).
*/

void getEff(TFile *file, char* histo)
{
  file->cd();
 int N_bins=0;
 double highVar=0;
 double lowVar=99;
 double N_Central=0;
 
 TH1D N_Bkgd;
 //((TH1D*)gDirectory->Get("histo1D__ALLBKG__PDFWeight_Npass"))->Copy(N_Bkgd); 
 //((TH1D*)gDirectory->Get("histo1D__LQeejj_M100__PDFWeight_eff"))->Copy(N_Bkgd); 
 ((TH1D*)gDirectory->Get(histo))->Copy(N_Bkgd); 
 
 N_bins = N_Bkgd.GetNbinsX();
 N_Central = N_Bkgd.GetBinContent(1);
 for (int i=2; i<N_bins; i++){
   double tmp = N_Bkgd.GetBinContent(i);
   if (tmp>highVar) highVar=tmp;
   if (tmp<lowVar) lowVar=tmp;
     }
 //cout << 100*(highVar-N_Central)/N_Central << "%  " << 100*(lowVar-N_Central)/N_Central<< "%" << endl;
 cout << 100*(highVar-N_Central) << "%  " << 100*(lowVar-N_Central)<< "%" << endl;
}

void getNbkgd(TFile *file,char* histo)
{
  file->cd();
 TH1D N_Bkgd;
 ((TH1D*)gDirectory->Get(histo))->Copy(N_Bkgd); 
 
 int N_bins=0;
 double N_Central=N_Bkgd.GetBinContent(1);
 double highVar=N_Central;
 double lowVar=N_Central;
 
 N_bins = N_Bkgd.GetNbinsX();
 N_Central = N_Bkgd.GetBinContent(1);
 for (int i=2; i<N_bins; i++){
   double tmp = N_Bkgd.GetBinContent(i);
   if (tmp>highVar) highVar=tmp;
   if (tmp<lowVar) lowVar=tmp;
     }
 //cout << 100*(highVar-N_Central)/N_Central << "%  " << 100*(lowVar-N_Central)/N_Central<< "%" << endl;
 cout << 100*(highVar-N_Central)/N_Central << "%  " << 100*(lowVar-N_Central)/N_Central<< "%" << endl;
}


void RunPDF()
{
  cout << "LQ100 eff: +";
  TFile file100("July14_PDFweights/analysisClass_PDFweighting___LQ_ue_100_7TeV_eejj_RAW__ferencek-LQ_ue_100_7TeV_eejj_RECO-d0c450599c7f4954244d4e7cbeababc4__USER.root");
  getEff(&file100,"PDFWeight_eff");

  cout << "LQ200 eff: +" ;
  TFile file200("July14_PDFweights/analysisClass_PDFweighting___LQ_ue_200_7TeV_eejj_RAW__ferencek-LQ_ue_200_7TeV_eejj_RECO-d0c450599c7f4954244d4e7cbeababc4__USER.root");
  getEff(&file200,"PDFWeight_eff");

  cout << "LQ300 eff: +";
  TFile file300("July14_PDFweights/analysisClass_PDFweighting___LQToUE_M-300_7TeV-pythia6__Spring10-START3X_V26-v1__GEN-SIM-RECO.root");
  getEff(&file300,"PDFWeight_eff");

  cout << "All Bkgd N_events: +" ;
  TFile fileAllBkgd("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileAllBkgd,"histo1D__ALLBKG__PDFWeight_Npass");

  cout << "All Bkgd eff: +" ;
  TFile fileAllBkgd("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileAllBkgd,"histo1D__ALLBKG__PDFWeight_eff");

  cout << "TTBar N_events: +" ;
  TFile fileTTBar("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileTTBar,"histo1D__TTbar__PDFWeight_Npass");

  cout << "TTBar eff: +" ;  
  TFile fileTTBar("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileTTBar,"histo1D__TTbar__PDFWeight_eff");

  cout << "Z N_events: +" ;
  TFile fileZ("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileZ,"histo1D__ZJetAlpgen__PDFWeight_Npass");

  cout << "Z eff: +" ;
  TFile fileZ("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileZ,"histo1D__ZJetAlpgen__PDFWeight_eff");

  cout << "W N_events: +" ;
  TFile fileW("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileW,"histo1D__WJetAlpgen__PDFWeight_Npass");

  cout << "W eff: +" ;
  TFile fileW("July14_PDFweights//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileW,"histo1D__WJetAlpgen__PDFWeight_eff");

}
