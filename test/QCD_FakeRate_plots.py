#!/usr/bin/env python

## Instructions and description:
##     This code uses defined methods to divide histograms and compute the proper error bars (only for the fixed bin case, not yet for the var bin case) for efficiencies from weighted samples.
##     Change the name of the input files to be the output of analysisClass_SCFakeRate.C
##     If fitting is required, uncomment the lines relevant to the function "f1" in the method GetEffFixBinning.
##     Towards the bottom of the macro change the names of the histograms passed to GetEffFixBinning to be those for the appropriate dataset.
##     Adjust plotting option at the very end of the macro.



#---Import
import sys
import string
from optparse import OptionParser
import os.path
from ROOT import *
import re
import ROOT
from array import array

#--- ROOT general options
gStyle.SetOptStat(0)
gStyle.SetPalette(1)
gStyle.SetCanvasBorderMode(0)
gStyle.SetFrameBorderMode(0)
gStyle.SetCanvasColor(kWhite)
gStyle.SetPadTickX(1);
gStyle.SetPadTickY(1);
#--- TODO: WHY IT DOES NOT LOAD THE DEFAULT ROOTLOGON.C ? ---#


#--- Root files

# %%%%%%% BEGIN %%%%%%%
def GetFile(filename):
    file = TFile(filename)
    if( not file):
        print "ERROR: file " + filename + " not found"
        print "exiting..."
        sys.exit()
    return file
# %%%%%%% END %%%%%%%

#output from /rootNtupleMacros/src/analysisClass_elecStudies2.C

File1 = GetFile("July19_FakeRate_MET/analysisClass_SCFakeRate_plots.root")
File2 = GetFile("oldTest.root")
File3 = GetFile("analysisClass_SCFakeRate_Variation_plots.root")
#File3 = GetFile("NewData_NoSpike.root")

#--- Define functions

# %%%%%%% BEGIN %%%%%%%     

def GetHisto( histoName , file ):
    histo = file.Get( histoName )
    if( not histo):
        print "ERROR: histo " + histoName + " not found in " + file.GetName()
        print "exiting..."
        sys.exit()
    return histo



def GetEffFixBinning( num , den , m_size , m_style , m_color , xtitle , ytitle , min , max, rebin):
    #print num;
    num.Rebin(rebin)
    den.Rebin(rebin)
    nBins_num = num.GetXaxis().GetNbins()
    nBins_den = den.GetXaxis().GetNbins()
    Xmin = num.GetXaxis().GetXmin()
    Xmax = num.GetXaxis().GetXmax()

##     for i in range (1,nBins_num):
##         print num.GetBinError(i)

    Tmp = TH1F("","",nBins_num,Xmin,Xmax)
    Tmp.Divide(num,den,1,1)

    #print values
##     for bin in range (1,nBins_num):
##         if (num.GetXaxis().GetBinLowEdge(bin)>max): continue
##         print (round(num.GetBinContent(bin),1)),
##     print ''
##     for bin in range (1,nBins_den):
##         if (den.GetXaxis().GetBinLowEdge(bin)>max): continue
##         print (round(den.GetBinContent(bin),1)),
##     print ''
##     for bin in range (1,nBins_den):
##         if (Tmp.GetXaxis().GetBinLowEdge(bin)>max): continue
##         print (round(Tmp.GetBinContent(bin),1)),
##     print '\n'
        #print 'num: %f   denom: %f  FakeRate: %f' % (num.GetBinContent(bin),den.GetBinContent(bin),Tmp.GetBinContent(bin))


    
    GraphEff = TGraphAsymmErrors()
    GraphEff.SetMarkerSize( m_size )
    GraphEff.SetMarkerStyle( m_style )
    GraphEff.SetMarkerColor( m_color )
    GraphEff.SetLineColor( m_color )
    GraphEff.GetXaxis().SetTitle(xtitle)
    GraphEff.GetYaxis().SetTitle(ytitle)
    GraphEff.GetXaxis().SetRangeUser(min,max);
    for bin in range (1,nBins_num):
        if (Tmp.GetXaxis().GetBinUpEdge(bin)<=min): continue
        if (Tmp.GetXaxis().GetBinLowEdge(bin)>max): continue
        GraphEff.SetPoint(bin-1,Tmp.GetBinCenter(bin),Tmp.GetBinContent(bin))
        eff = Tmp.GetBinContent(bin)
        dNum = num.GetBinError(bin)
        dDenom = den.GetBinError(bin)
        Denom = den.GetBinContent(bin)
        if (Denom!=0):
            sigma = sqrt((dNum*dNum)+(eff*eff*dDenom*dDenom))/Denom
            GraphEff.SetPointEYhigh(bin-1,sigma) # 0 is underflow bins for histo, but first point in TGraph
            GraphEff.SetPointEYlow(bin-1,sigma)

##     f1 = TF1("f1","pol0",20,70);
##     GraphEff.Fit("f1","R")

    return GraphEff



def GetEffVarBinning( num , den , m_size , m_style , m_color , xtitle , ytitle , min , max, Bins):

    NbinTot = len(Bins) 
    BinsFinal = array( 'f', Bins ) 

    num_varBin = TH1F("num_varBin",
                      "num_varBin",
                      NbinTot - 1 , BinsFinal );
    nBins_num = num.GetXaxis().GetNbins()
    getxmax_num = num.GetXaxis().GetXmax();
    getxmin_num = num.GetXaxis().GetXmin();
    step_num = (getxmax_num - getxmin_num) / nBins_num;
    for bin in range( 1 , nBins_num+1 ):
        #for entry in range( 0 , int(num.GetBinContent(bin)) ):
            num_varBin.Fill(step_num * bin-1, num.GetBinContent(bin))

    den_varBin = TH1F("den_varBin",
                      "den_varBin",
                      NbinTot - 1 , BinsFinal );
    nBins_den = den.GetXaxis().GetNbins()
    getxmax_den = den.GetXaxis().GetXmax();
    getxmin_den = den.GetXaxis().GetXmin();
    step_den = (getxmax_den - getxmin_den) / nBins_den;
    for bin in range( 1 , nBins_den+1 ):
        #for entry in range( 0 , int(den.GetBinContent(bin)) ):
            den_varBin.Fill(step_den * bin-1, den.GetBinContent(bin) )

    #--- create final graph
    Tmp = TH1F("","",NbinTot - 1 , BinsFinal)
    Tmp.Divide(num_varBin,den_varBin,1,1)
    GraphEff = TGraphAsymmErrors(Tmp)

##     for i in range (1,NbinTot):
##         print num_varBin.GetBinError(i))

    GraphEff.SetMarkerSize( m_size )
    GraphEff.SetMarkerStyle( m_style )
    GraphEff.SetMarkerColor( m_color )
    GraphEff.SetLineColor( m_color )
    GraphEff.GetXaxis().SetTitle(xtitle)
    GraphEff.GetYaxis().SetTitle(ytitle)
    GraphEff.GetXaxis().SetRangeUser(min,max);

##     f1 = TF1("f1","pol1",30,100);
##     GraphEff.Fit("f1","R")

    for bin in range (1,nBins_num):
        eff = Tmp.GetBinContent(bin)
        dNum = num_varBin.GetBinError(bin)
        dDenom = den_varBin.GetBinError(bin)
        Denom = den_varBin.GetBinContent(bin)
        if (Denom!=0):
            sigma = sqrt((dNum*dNum)+(eff*eff*dDenom*dDenom))/Denom
            GraphEff.SetPointEYhigh(bin-1,sigma) # 0 is underflow bins for histo, but first point in TGraph
            GraphEff.SetPointEYlow(bin-1,sigma)

    return GraphEff



def GetRatioEff( num , den , m_size , m_style , m_color , xtitle , ytitle ):

    ratio = TGraphAsymmErrors()
    npoint = 0;

    if(num.GetN() != den.GetN()):
        print "ERROR in GetRatioEff: num.GetN() != den.GetN()"
        print "exiting..."
        sys.exit()
        
    for point in range( 0 , den.GetN() ):
        
        x1, y1, x2, y2 = ROOT.Double(1), ROOT.Double(1), ROOT.Double(1), ROOT.Double(1)

        
        num.GetPoint(point, x1, y1)
        ehx1 = num.GetErrorXhigh(point)  
        ehy1 = num.GetErrorYhigh(point)  
        elx1 = num.GetErrorXlow(point)  
        ely1 = num.GetErrorYlow(point)  
        
        den.GetPoint(point, x2, y2)
        ehx2 = den.GetErrorXhigh(point)  
        ehy2 = den.GetErrorYhigh(point)  
        elx2 = den.GetErrorXlow(point)  
        ely2 = den.GetErrorYlow(point)  
        
        if( y2 == 0 or y1==0 ):
            ratio.SetPoint(npoint,x1, 0)
            ratio.SetPointEXhigh(npoint, ehx1)
            ratio.SetPointEXlow(npoint, elx1)
            ratio.SetPointEYhigh(npoint, 0)
            ratio.SetPointEYlow(npoint, 0)
        else:
            r = y1/y2
            erelhy1 = ehy1 / y1
            erelhy2 = ehy2 / y2
            erelly1 = ely1 / y1
            erelly2 = ely2 / y2
            erelhr = sqrt(erelhy1 * erelhy1 + erelhy2 * erelhy2)
            erellr = sqrt(erelly1 * erelly1 + erelly2 * erelly2)
            ehr=erelhr*r
            elr=erellr*r
            
            ratio.SetPoint(npoint, x1, r)
            ratio.SetPointEXhigh(npoint, ehx1)
            ratio.SetPointEXlow(npoint, elx1)
            ratio.SetPointEYhigh(npoint, ehr)
            ratio.SetPointEYlow(npoint, elr)
        
        npoint = npoint + 1

    ratio.SetMarkerSize( m_size )
    ratio.SetMarkerStyle( m_style )
    ratio.SetMarkerColor( m_color )
    ratio.GetXaxis().SetTitle(xtitle)
    ratio.GetYaxis().SetTitle(ytitle)

    return ratio


def GetHistoRescaled( histo , function ):

    Bins = []
    BinsContent = []
    BinsContentErrMax = []
    for point in range( 0 , function.GetN() ):
        x, y = ROOT.Double(1), ROOT.Double(1)
        function.GetPoint(point, x, y)
        ehx = function.GetErrorXhigh(point)  
        elx = function.GetErrorXlow(point)
        ehy = function.GetErrorYhigh(point)
        ely = function.GetErrorYlow(point)  
        up = x + ehx
        low = x - elx
        if(point == 0):
            Bins.append( low )
        Bins.append( up )
        BinsContent.append( y )
        BinsContentErrMax.append( max(ehy,ely) )

    BinsFinal = array( 'f', Bins ) 

    ##define the tmp-histo
    histoFinal = TH1F("histoFinal",
                      histo.GetName()+"_rescaled",
                      len(Bins) - 1 , BinsFinal )
    histoFinal.Sumw2()

    ##fill the tmp-histo with the content of the histo passed as argument to the function
    for bin1 in range( 1 , histoFinal.GetNbinsX()+1 ):
        center = histoFinal.GetBinCenter(bin1)
        halfwidth = histoFinal.GetBinWidth(bin1) / 2
        #print center
        #print halfwidth
        newValue = 0
        newErr = 0
        for bin2 in range( 1 , histo.GetNbinsX()+1 ):
            if(histo.GetBinCenter(bin2) > (center - halfwidth)
               and
               histo.GetBinCenter(bin2) < (center + halfwidth) ):
                newValue = newValue + histo.GetBinContent(bin2)
                newErr = newErr + histo.GetBinError(bin2)*histo.GetBinError(bin2)

        histoFinal.SetBinContent(bin1,newValue)
        histoFinal.SetBinError(bin1,sqrt(newErr))

#    for bin in range( 1 , histo.GetNbinsX()+1 ):
#        for entry in range( 0 , int(histo.GetBinContent(bin)) ):
#            histoFinal.SetBinContent( histo.GetBinCenter(bin) , float(histo.GetBinContent(bin) )

    ##rescale tmp-histo with the function
    for index, rescaleFactor in enumerate( BinsContent ):
        #print index
        #print "histoFinal.GetBinContent(index+1): " + str(histoFinal.GetBinContent(index+1))
        #print "histoFinal.GetBinError(index+1): " + str(histoFinal.GetBinError(index+1))
        #print "rescaleFactor: " + str(rescaleFactor)
        #print "BinsContentErrMax[index]: " + str(BinsContentErrMax[index])
        rescaledBinContent = rescaleFactor * histoFinal.GetBinContent(index+1)
        if( histoFinal.GetBinContent(index+1) >0 and rescaleFactor >0 ):
            erelh = histoFinal.GetBinError(index+1) / histoFinal.GetBinContent(index+1)
            erelf = BinsContentErrMax[index] / rescaleFactor
            erelhfin = sqrt(erelh*erelh + erelf*erelf)
            rescaledBinError = erelhfin * rescaledBinContent
            #print "rescaledBinContent: " + str(rescaledBinContent)
            #print "rescaledBinError: " + str(rescaledBinError)
            histoFinal.SetBinContent(index+1 , rescaledBinContent )
            histoFinal.SetBinError(index+1 , rescaledBinError )
        else:
            histoFinal.SetBinContent(index+1 , 0 )
            histoFinal.SetBinError(index+1 , 0 )
        #print ""

    return histoFinal

def GetIntegral(histo):
    return histo.Integral()

def GetIntegralError(histo):
    integralError = 0
    for bin in range( 1 , histo.GetNbinsX()+1 ):
        integralError = integralError + (histoFinal.GetBinError(bin)*histoFinal.GetBinError(bin))
    integralError = sqrt(integralError)
    return integralError
        
# %%%%%%% END %%%%%%% 
                
#--- Define all the histograms
MyBins = [10,15,20,25,30,40,60,80,100,200,300,400,500]



#PT ratios

## h_ele_pt_loose_qcd_barrel = GetHisto( "histo1D__QCDPythia__goodSCPt_Barrel" , File1)
## h_ele_pt_heep_qcd_barrel = GetHisto( "histo1D__QCDPythia__goodEleSCPt_Barrel" , File1)
## fakeRate_qcd_barrel = GetEffFixBinning( h_ele_pt_heep_qcd_barrel , h_ele_pt_loose_qcd_barrel
##                                  , 1.2 , 4 , 2
##                                  , "Supercluster Pt (GeV)" , "fake probability - Barrel"
##                                  , 20 , 100, 10)


## h_ele_pt_loose_qcd_endcap = GetHisto( "histo1D__QCDPythia__goodSCPt_Endcap" , File1)
## h_ele_pt_heep_qcd_endcap = GetHisto( "histo1D__QCDPythia__goodEleSCPt_Endcap" , File1)
## fakeRate_qcd_endcap = GetEffFixBinning( h_ele_pt_heep_qcd_endcap , h_ele_pt_loose_qcd_endcap
##                                  , 1.2 , 4 , 2
##                                  , "Supercluster Pt (GeV)" , "fake probability - Endcap"
##                                  , 20 , 100, 10)


h_ele_pt_loose_NewData_barrel = GetHisto( "histo1D__data__goodSCPt_Barrel" , File3)
h_ele_pt_heep_NewData_barrel = GetHisto( "histo1D__data__goodEleSCPt_Barrel" , File3)
fakeRate_NewData_barrel = GetEffFixBinning( h_ele_pt_heep_NewData_barrel , h_ele_pt_loose_NewData_barrel
                                 , 1.2 , 20 , 1
                                 , "Supercluster Pt (GeV)" , "fake probability - Barrel"
                                 , 20 , 100, 10)


h_ele_pt_loose_NewData_endcap = GetHisto( "histo1D__data__goodSCPt_Endcap" , File3)
h_ele_pt_heep_NewData_endcap = GetHisto( "histo1D__data__goodEleSCPt_Endcap" , File3)
fakeRate_NewData_endcap = GetEffFixBinning( h_ele_pt_heep_NewData_endcap , h_ele_pt_loose_NewData_endcap
                                 , 1.2 , 20 , 1
                                 , "Supercluster Pt (GeV)" , "fake probability - Endcap"
                                 , 20 , 100, 10)



## h_ele_pt_loose_data_barrel = GetHisto( "goodSCPt_Barrel" , File2)
## h_ele_pt_heep_data_barrel = GetHisto( "goodEleSCPt_Barrel" , File2)
## fakeRate_data_barrel = GetEffFixBinning( h_ele_pt_heep_data_barrel , h_ele_pt_loose_data_barrel
##                                  , 1.2 , 20 , 1
##                                  , "Supercluster Pt (GeV)" , "fake probability - Barrel"
##                                  , 20 , 100, 10)

## h_ele_pt_loose_data_endcap= GetHisto( "goodSCPt_Endcap" , File2)
## h_ele_pt_heep_data_endcap = GetHisto( "goodEleSCPt_Endcap" , File2)
## fakeRate_data_endcap = GetEffFixBinning( h_ele_pt_heep_data_endcap , h_ele_pt_loose_data_endcap
##                                  , 1.2 , 20 , 1
##                                  , "Supercluster Pt (GeV)" , "fake probability - Endcap"
##                                  , 20 , 100, 10)




#--- Final plots
cAll = TCanvas();
cAll.Print("FakeRatePlots.ps[");

#all fake rate
c0 = TCanvas()
c0.SetGridy();
c0.SetGridx();
fakeRate_NewData_barrel.GetYaxis().SetRangeUser(0,0.025);
#fakeRate_NewData_barrel.GetXaxis().SetRangeUser(15,55);
fakeRate_NewData_barrel.Draw("ap")
fakeRate_NewData_barrel.SetLineWidth(2)
## fakeRate_qcd_barrel.Draw("pSAME")
## fakeRate_data_barrel.Draw("pSAME")
fakeRate_NewData_barrel.GetXaxis().SetTitle("Supercluster Pt (GeV)")
fakeRate_NewData_barrel.GetYaxis().SetTitle("fake probability - Barrel")
legend = TLegend(0.15,0.75,0.4,0.90)
legend.SetFillColor(kWhite)
legend.SetMargin(0.2)
#legend.AddEntry(fakeRate_data_barrel,"Data: 58 nb^{-1}","p")
legend.AddEntry(fakeRate_NewData_barrel,"Data: 254 nb^{-1}","p")
#legend.AddEntry(fakeRate_qcd_barrel,"QCD Pythia","p")
#legend.AddEntry(fakeRate_qcdMG_barrel,"QCD MadGraph","p")
#legend.AddEntry(fakeRate_allPt15_barrel,"All Bkgnd","p")
#legend.AddEntry(fakeRate_allMG_barrel,"All Bkgnd w/ QCD MG","p")
legend.Draw()

## slope = 0.0
## intercept = 0.00715202
## x_line=array("d",[20.0,100.0])
## y_line= array("d",[slope*x_line[0]+intercept,slope*x_line[1]+intercept])
## line = TPolyLine(2,x_line,y_line,"L")
## line.SetLineWidth(2)
## line.Draw()

## slope = 0.0
## intercept = 0.006245
## x_line_sigPlus=array("d",[30.0,100.0])
## y_line_sigPlus= array("d",[slope*x_line_sigPlus[0]+intercept,slope*x_line_sigPlus[1]+intercept])
## line_sigPlus = TPolyLine(2,x_line_sigPlus,y_line_sigPlus,"L")
## line_sigPlus.SetLineColor(2)
## line_sigPlus.SetLineWidth(2)
## line_sigPlus.SetLineStyle(5)
## line_sigPlus.Draw()

## slope = 0.0
## intercept = 0.0054311
## x_line_sigMinus=array("d",[30.0,100.0])
## y_line_sigMinus= array("d",[slope*x_line_sigMinus[0]+intercept,slope*x_line_sigMinus[1]+intercept])
## line_sigMinus = TPolyLine(2,x_line_sigMinus,y_line_sigMinus,"L")
## line_sigMinus.SetLineColor(2)
## line_sigMinus.SetLineWidth(2)
## line_sigMinus.SetLineStyle(5)
## line_sigMinus.Draw()

c0.Print("FakeRate_barrel_variation.gif","gif");
c0.Print("FakeRate_barrel_variation.pdf","pdf");
c0.Print("FakeRate_barrel_variation.eps","eps");
c0.Print("FakeRatePlots.ps");

c1 = TCanvas()
c1.SetGridy();
c1.SetGridx();
fakeRate_NewData_endcap.GetYaxis().SetRangeUser(0,0.12);
## fakeRate_NewData_endcap.GetXaxis().SetRangeUser(20,500);
fakeRate_NewData_endcap.Draw("ap")
fakeRate_NewData_endcap.SetLineWidth(2)
## fakeRate_qcd_endcap.Draw("pSAME")
## fakeRate_data_endcap.Draw("pSAME")
fakeRate_NewData_endcap.GetXaxis().SetTitle("Supercluster Pt (GeV)")
fakeRate_NewData_endcap.GetYaxis().SetTitle("fake probability - Endcap")
legend.Draw()

## slope = 0.0
## intercept = 0.0465969
## x_line_endcap=array("d",[20.0,100.0])
## y_line_endcap= array("d",[slope*x_line_endcap[0]+intercept,slope*x_line_endcap[1]+intercept,slope*x_line_endcap[1]+intercept])
## line_endcap = TPolyLine(2,x_line_endcap,y_line_endcap,"L")
## line_endcap.SetLineWidth(2)
## line_endcap.Draw()

## slope = 0.00132
## intercept = -0.00439
## x_line_endcap_sigPlus=array("d",[30.0,70.0,100.0])
## y_line_endcap_sigPlus= array("d",[slope*x_line_endcap_sigPlus[0]+intercept,slope*x_line_endcap_sigPlus[1]+intercept,slope*x_line_endcap_sigPlus[1]+intercept])
## line_endcap_sigPlus = TPolyLine(3,x_line_endcap_sigPlus,y_line_endcap_sigPlus,"L")
## line_endcap_sigPlus.SetLineColor(2)
## line_endcap_sigPlus.SetLineWidth(2)
## line_endcap_sigPlus.SetLineStyle(5)
## line_endcap_sigPlus.Draw()

## slope = 0.00110
## intercept = -0.01353
## x_line_endcap_sigMinus=array("d",[30.0,70.0,100.0])
## y_line_endcap_sigMinus= array("d",[slope*x_line_endcap_sigMinus[0]+intercept,slope*x_line_endcap_sigMinus[1]+intercept,slope*x_line_endcap_sigMinus[1]+intercept])
## line_endcap_sigMinus = TPolyLine(3,x_line_endcap_sigMinus,y_line_endcap_sigMinus,"L")
## line_endcap_sigMinus.SetLineColor(2)
## line_endcap_sigMinus.SetLineWidth(2)
## line_endcap_sigMinus.SetLineStyle(5)
## line_endcap_sigMinus.Draw()


c1.Print("FakeRate_endcap_variation.gif","gif");
c1.Print("FakeRate_endcap_variation.pdf","pdf");
c1.Print("FakeRate_endcap_variation.eps","eps");
c1.Print("FakeRatePlots.ps");

## c2 = TCanvas()
## c2.SetGridy();
## c2.SetGridx();
## fakeRate_qcd_eta.GetYaxis().SetRangeUser(0,0.08);
## fakeRate_qcd_eta.Draw("ap")
## fakeRate_data_eta.Draw("pSAME")
## ## legend.Draw()
## c2.Print("FakeRate_eta_data.gif","gif");
## c2.Print("FakeRate_eta_data.pdf","pdf");
## c2.Print("FakeRate_eta_data.eps","eps");
## c2.Print("FakeRatePlots.ps");

## c1 = TCanvas()
## c1.SetGridy();
## c1.SetGridx();
## fakeRate_eta.Draw("ap")
## ## fakeRate_eta_2.Draw("pSAME")
## c1.Print("FakeRate_eta.gif","gif");
## c1.Print("FakeRatePlots.ps");

## c2 = TCanvas()
## c2.SetGridy();
## c2.SetGridx();
## fakeRate_ST.Draw("ap")
## c2.Print("FakeRate_ST.gif","gif");
## c2.Print("FakeRatePlots.ps");

## ### 1_ele fake rate
## line1 = TLine();
## line1.SetLineStyle(7);
## line1.DrawLine(50,0.04437,300,0.135173);





cAll.Print("FakeRatePlots.ps]");


# lasthisto = File5.Get( "histo1D__QCD_MdGrph__cutHisto_allOtherCuts___________sT" )
# lasthisto.GetXaxis().SetTitle("St")
# c4 = TCanvas()
# c4.SetGridy();
# c4.SetGridx();
# lasthisto.Draw("ap")


## Terminate the program
print "Press ENTER to terminate"
wait=raw_input()
