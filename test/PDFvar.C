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

void getEff(TFile *file, char* histoTop, char* histoBottom)
{
  file->cd();
 int N_bins=0;
 double highVar=0;
 double lowVar=99;
 double N_Central=0;
 
 TH1D *N_Pass = ((TH1D*)gDirectory->Get(histoTop));
 TH1D *N_Tot = ((TH1D*)gDirectory->Get(histoBottom));
 TH1D *Eff= new TH1D ("","",41,-0.5,40.5);

 Eff->Divide(N_Pass,N_Tot,1.,1.);
 
 N_bins = Eff->GetNbinsX();
 N_Central = Eff->GetBinContent(1);
 for (int i=2; i<N_bins; i++){
   double tmp = Eff->GetBinContent(i);
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
  cout << "LQ400 eff: +";
  TFile file100("Oct15_PDF_10pb/analysisClass_PDFweighting_plots.root");
  getEff(&file100,"histo1D__LQeejj_M400__PDFWeight_Npass_400","histo1D__LQeejj_M400__PDFWeight_Ntot");

  cout << "All Bkgd N_events: +" ;
  TFile fileAllBkgd("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileAllBkgd,"histo1D__ALLBKG__PDFWeight_Npass_400");

  cout << "All Bkgd eff: +" ;
  TFile fileAllBkgd("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getEff(&fileAllBkgd,"histo1D__ALLBKG__PDFWeight_Npass_400","histo1D__ALLBKG__PDFWeight_Ntot");

  cout << "TTBar N_events: +" ;
  TFile fileTTBar("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileTTBar,"histo1D__TTbar_Madgraph__PDFWeight_Npass_400");

  cout << "TTBar eff: +" ;  
  TFile fileTTBar("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getEff(&fileTTBar,"histo1D__TTbar_Madgraph__PDFWeight_Npass_400","histo1D__TTbar_Madgraph__PDFWeight_Ntot");

  cout << "Z N_events: +" ;
  TFile fileZ("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileZ,"histo1D__ZJetAlpgen__PDFWeight_Npass_400");

  cout << "Z eff: +" ;
  TFile fileZ("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getEff(&fileZ,"histo1D__ZJetAlpgen__PDFWeight_Npass_400","histo1D__ZJetAlpgen__PDFWeight_Ntot");

  cout << "W N_events: +" ;
  TFile fileW("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getNbkgd(&fileW,"histo1D__WJetAlpgen__PDFWeight_Npass_400");

  cout << "W eff: +" ;
  TFile fileW("Oct15_PDF_10pb//analysisClass_PDFweighting_plots.root");
  getEff(&fileW,"histo1D__WJetAlpgen__PDFWeight_Npass_400","histo1D__WJetAlpgen__PDFWeight_Ntot");

}
