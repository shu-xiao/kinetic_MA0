#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "cstdlib"
#include "iostream"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TROOT.h"
#include "setNCUStyle.C"


void plot()
{
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetFrameLineWidth(3);
    setNCUStyle();
	
    TCanvas *c1 = new TCanvas("c1","hmzp",900,700);
	TLegend* leg = new TLegend(0.5,0.6593,0.95,0.8761);
    
    TFile *f_mzp1 = TFile::Open("MZp600Ma0_400.root"); //dm=10
    TFile *f_mzp2 = TFile::Open("MZp600Ma0_500.root"); //old
    TFile *f_mzp3 = TFile::Open("MZp600Ma0_600.root");
    TFile *f_mzp4 = TFile::Open("MZp600Ma0_700.root"); //dm=100
    TFile *f_mzp5 = TFile::Open("MZp600Ma0_800.root");
    TFile *f_mzp6 = TFile::Open("MZp600Ma0_300.root");


    TH1F* h_A0m1 = (TH1F*)f_mzp1->Get("h_Dpt_0");
    TH1F* h_A0m2 = (TH1F*)f_mzp2->Get("h_Dpt_0");
    TH1F* h_A0m3 = (TH1F*)f_mzp3->Get("h_Dpt_0");    
    TH1F* h_A0m4 = (TH1F*)f_mzp4->Get("h_Dpt_0");
    TH1F* h_A0m5 = (TH1F*)f_mzp5->Get("h_Dpt_0");
    TH1F* h_A0m6 = (TH1F*)f_mzp6->Get("h_Dpt_0");

//dR(bb):h_D_dR0
//PT(A0): h_Bpt1
//PT(H): h_Bpt0
//TM(x):h_XmT
//h_Xm; h_Xy;
//h_Xpz;h_Bpz0;h_Bpz1;h_Dpz0;h_Dpz1;
//h_cosThetaStar;h_cosPhi;h_Bm0;h_BmT0;h_BmT1;h_By0;h_By1

    float scale1 = 1.0/h_A0m1->Integral();
    float scale2 = 1.0/h_A0m2->Integral();
    float scale3 = 1.0/h_A0m3->Integral();
    float scale4 = 1.0/h_A0m4->Integral();
    float scale5 = 1.0/h_A0m5->Integral();
    float scale6 = 1.0/h_A0m6->Integral();

    h_A0m1->Scale(scale1);
    h_A0m2->Scale(scale2);
    h_A0m3->Scale(scale3);
    h_A0m4->Scale(scale4);
    h_A0m5->Scale(scale5);
    h_A0m6->Scale(scale6);
    // h_zpM700_hA0_bbxx->Scale(scale7);

    h_A0m1->Sumw2();
    h_A0m2->Sumw2();
    h_A0m3->Sumw2();
    h_A0m4->Sumw2();
    h_A0m5->Sumw2();
    h_A0m6->Sumw2();

    h_A0m1->SetLineColor(100);
    h_A0m2->SetLineColor(84);
    h_A0m3->SetLineColor(74);
    h_A0m4->SetLineColor(68);
    h_A0m5->SetLineColor(62);
    h_A0m6->SetLineColor(95);

    h_A0m1->GetXaxis()->SetTitleFont(22);
    h_A0m1->GetYaxis()->SetTitleFont(22);
    h_A0m2->GetXaxis()->SetLabelFont(22);
    h_A0m2->GetYaxis()->SetLabelFont(22);
    h_A0m3->GetXaxis()->SetLabelFont(22);
    h_A0m3->GetYaxis()->SetLabelFont(22);
    h_A0m4->GetXaxis()->SetLabelFont(22);
    h_A0m4->GetYaxis()->SetLabelFont(22);
    h_A0m5->GetXaxis()->SetLabelFont(22);
    h_A0m5->GetYaxis()->SetLabelFont(22);
    h_A0m6->GetXaxis()->SetLabelFont(22);
    h_A0m6->GetYaxis()->SetLabelFont(22);

    h_A0m1->GetXaxis()->SetTitleSize(0.045);
    h_A0m1->GetYaxis()->SetTitleSize(0.045);  
    h_A0m2->GetXaxis()->SetLabelSize(0.045);
    h_A0m2->GetYaxis()->SetLabelSize(0.045);
    h_A0m3->GetXaxis()->SetLabelSize(0.045);
    h_A0m3->GetYaxis()->SetLabelSize(0.045);
    h_A0m4->GetXaxis()->SetLabelSize(0.045);
    h_A0m4->GetYaxis()->SetLabelSize(0.045);
    h_A0m5->GetXaxis()->SetLabelSize(0.045);
    h_A0m5->GetYaxis()->SetLabelSize(0.045);
    h_A0m6->GetXaxis()->SetLabelSize(0.045);
    h_A0m6->GetYaxis()->SetLabelSize(0.045);

    h_A0m1->GetYaxis()->SetTitleOffset(1.45);
    h_A0m2->GetYaxis()->SetTitleOffset(1.45);
    h_A0m3->GetYaxis()->SetTitleOffset(1.45);   
    h_A0m4->GetYaxis()->SetTitleOffset(1.45);
    h_A0m5->GetYaxis()->SetTitleOffset(1.45);
    h_A0m6->GetYaxis()->SetTitleOffset(1.45);

    h_A0m1->SetLineWidth(2);
    h_A0m2->SetLineWidth(2);
    h_A0m3->SetLineWidth(2);
    h_A0m4->SetLineWidth(2);
    h_A0m5->SetLineWidth(2);
    h_A0m6->SetLineWidth(2);
    // h->SetLineColor(1);

    // h_A0m1->GetYaxis()->SetRange(0,700);
    // h_A0m2->GetYaxis()->SetRange(0,700);
    // h_A0m3->GetYaxis()->SetRange(0,700);
    h_A0m3->GetYaxis()->SetTitle("Normalized to 1");
    h_A0m3->GetYaxis()->SetTitleSize(0.04);
    h_A0m3->GetXaxis()->SetTitle("pt (GeV)");
    h_A0m3->GetXaxis()->SetTitleSize(0.04);
    h_A0m3->SetAxisRange(0,500,"X");
    h_A0m3->SetAxisRange(0,0.4,"y");
    // h_A0m5->GetYaxis()->SetRange(0,700);
    // h_A0m6->GetYaxis()->SetRange(0,700); 

    h_A0m3->Draw("hist");        
    h_A0m2->Draw("histsame");
    h_A0m6->Draw("histsame"); 
    h_A0m1->Draw("histsame");
    h_A0m5->Draw("histsame");
    h_A0m4->Draw("histsame");

    leg->AddEntry(h_A0m6,"MZ'_600GeV,MA0_300GeV");
    leg->AddEntry(h_A0m1,"MZ'_600GeV,MA0_400GeV");
    leg->AddEntry(h_A0m2,"MZ'_600GeV,MA0_500GeV");
    leg->AddEntry(h_A0m3,"MZ'_600GeV,MA0_600GeV");
    leg->AddEntry(h_A0m4,"MZ'_600GeV,MA0_700GeV");
    leg->AddEntry(h_A0m5,"MZ'_600GeV,MA0_800GeV");
    //leg->AddEntry(h_A0m6,"MZ'_1400GeV,DM_100GeV");

    leg->Draw();


    c1->Update();
    // Latex
    TString latexCMSname= "CMS Simulation Preliminary at #sqrt{s} = 13TeV";
    TString latexCMSname2= "Z^{'} #rightarrow A0, A0 #rightarrow n_{1}, n_{2}";
    TLatex Tl; Tl.SetTextFont(72); Tl.SetTextSize(0.04); 
    Tl.SetNDC(kTRUE); 
    Tl.SetTextAlign(22);
    Tl.DrawLatex(0.5,0.95,latexCMSname);
    Tl.DrawLatex(0.75,0.6,latexCMSname2);

}
