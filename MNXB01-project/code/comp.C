// comp.C
// Requires the script "data_cleaner.sh" to be executed
//REmove
#include "TF1.h" 
#include "TH1.h" 
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include <fstream>
#include <iostream>

using namespace std; 


void comp(Int_t MONTH) {

  TString MM = Form("%d", MONTH);
  if(MM.Length() == 1 ) {
      MM.Prepend("0");
  }

  TH1I* hist_lund = new TH1I("temperature", "Temperature;Temperature [#circC];Entries", 300, -20, 40);

  TH1I* hist_lulea = new TH1I("temperature", "Temperature;Temperature [#circC];Entries", 300, -20, 40);

  TCanvas* c1 = new TCanvas();

  TString line;
  Double_t line_two;

  ifstream lund_file("../datasets/smhi_Lund.csv");
  while(lund_file >> line >> line_two) {
    line.Remove(0,4);
    line.Remove(2,4);
    if(line.Contains(MM)) {
      hist_lund->Fill(line_two);
    }    
  }
  lund_file.close();
  cout << "Lund done" << endl;


  ifstream lulea_file("../datasets/smhi_Lulea.csv");
  while(lulea_file >> line >> line_two) {
    line.Remove(0,4);
    line.Remove(2,4);
    if(line.Contains(MM)) {
      hist_lulea->Fill(line_two);
    }
  }
  lulea_file.close();
  cout << "Lulea done" << endl;
  

  Double_t mean_lund = hist_lund->GetMean();
  Double_t stdev_lund = hist_lund->GetRMS();
  Double_t mean_lulea = hist_lulea->GetMean();
  Double_t stdev_lulea = hist_lulea->GetRMS();

  cout << "City : " << " mean" << "      stdev" << endl;
  cout << "Lund : " << " " << mean_lund << " : " << stdev_lund << endl;
  cout << "Lulea : " << mean_lulea << " : " << stdev_lulea << endl;


  hist_lund->SetFillColor(kRed + 1);
  hist_lulea->SetFillColor(kBlue + 1);
  hist_lund->Draw();
  hist_lulea->Draw("same");
  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->SetBorderSize(0);
  leg->AddEntry(hist_lund, "Lund", "f");
  leg->AddEntry(hist_lulea, "Lulea", "f");
  leg->Draw();
  c1->SaveAs("comp.png");

} // End comp

 
