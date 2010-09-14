
{

  TCanvas c1; 
  c1.SetLogy();       
  c1->Divide(Int_t nx = 2, Int_t ny = 2, Float_t xmargin = 0.01, Float_t ymargin = 0.01, Int_t color = 0);
  
  TH1F ah[10];
  TString as[10];
  TString ak[10];

  ////////////// USER INPUTS STARTS HERE //////////////////

  #define NH 4 // Number of histograms to plot

  TFile * infile = TFile::Open("$LQDATA/collisions/2.9pb-1/output_cutTable_eejjSample_elePt25_jetPt20/analysisClass_eejjSample_plots.root");

  TString outputFilename = "electronEta_elePt25_jetPt20.ps";

  as[0] =  "histo1D__DATA__cutHisto_allPreviousCuts________Eta1stEle_after1stJet";
  as[1] =  "histo1D__DATA__cutHisto_allPreviousCuts________Eta2ndEle_after1stJet";
  as[2] =  "histo1D__DATA__cutHisto_allPreviousCuts________Eta1stEle_PAS";
  as[3] =  "histo1D__DATA__cutHisto_allPreviousCuts________Eta2ndEle_PAS";
   
  ak[0] =  "Eta 1st Ele (1 jet pt > 20 GeV/c)";
  ak[1] =  "Eta 2nd Ele (1 jet pt > 20 GeV/c)";
  ak[2] =  "Eta 1st Ele (2 jets pt > 20 GeV/c))";
  ak[3] =  "Eta 2nd Ele (2 jets pt > 20 GeV/c))";


  TString xtitle = "#eta";

  float rebin = 5;
  float markerSize = 0.5;
  bool ylog = false;

  float legend_xmin = 0.15;
  float legend_xsiz = 0.55;
  float legend_ymin = 0.80;
  float legend_ysiz = 0.07;
  float legend_textSize = 0.04;

  ////////////// END OF USER INPUTS //////////////////

  //  c1->Print("tmp.pdf[","pdf");
  //c1->Print("tmp.ps[");
   
  for(int i=0; i<NH; i++)
    { 
      c1->cd(i+1);
      if (ylog) (c1->cd(i+1))->SetLogy();
      ah[i] = (TH1F) infile->Get(as[i]);
      ah[i]->Rebin(rebin);
      ah[i]->SetMarkerSize(markerSize);
      //ah[i]->GetXaxis()->SetRangeUser(-3, 3); 
      //ah[i]->GetYaxis()->SetRangeUser(0.0001,300); 
      ah[i]->GetXaxis().SetTitle(xtitle);
      ah[i]->Draw("histep"); 

      TLegend * legend = new TLegend(legend_xmin, legend_ymin, legend_xmin+legend_xsiz, legend_ymin+legend_ysiz);
      legend->SetTextSize(legend_textSize);
      legend->SetFillColor(kWhite);
      legend->AddEntry(as[i],ak[i],"l");
      legend->Draw();
      //      c1->Print("tmp.pdf","pdf");
      //c1->Print("tmp.ps");
      //delete legend;
    }

  //    c1->Print("tmp.pdf]","pdf");
  //c1->Print("tmp.ps]");

  c1->Print(outputFilename);

}
