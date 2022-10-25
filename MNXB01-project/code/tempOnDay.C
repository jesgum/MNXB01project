#include <TF1.h> 
#include <TH1.h> 
#include <TStyle.h>
#include <TCanvas.h>
#include <fstream>
#include <iostream>

using namespace std; 

void tempOnDay(TString MM, TString DD) {

  TH1I* hist = new TH1I("temperature", "Temperature;Temperature [#circC];Entries", 300, -20, 40);
  hist->SetFillColor(kRed + 1);

  ifstream file("../datasets/lund.csv");

  TString Date = MM + DD;
  TString line;
  Double_t line_two;
  

  while(file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      cout << line << " : " << line_two << endl;
      hist->Fill(line_two);
    } // end if contains
  } // end while file

  
  Double_t mean = hist->GetMean(); //The mean of the distribution
  Double_t stdev = hist->GetRMS(); //The standard deviation
  TCanvas* can = new TCanvas();
  hist->Draw();
} // End tempOnDay
 
