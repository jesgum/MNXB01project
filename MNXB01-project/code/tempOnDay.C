#include <TF1.h> 
#include <TH1.h> 
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <fstream>
#include <iostream>

using namespace std; 

void tempOnDay(TString MM, TString DD) {

  TH1I* hist = new TH1I("temperature", "Temperature;Temperature [#circC];Entries", 300, -20, 40);
  hist->SetFillColor(kRed + 1);

  TString Date = MM + DD;
  TString line;
  Double_t line_two;
  
  ifstream lund_file("../datasets/smhi_Lund.csv");
  while(lund_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  lund_file.close();
  cout << "Lund done" << endl;

  ifstream falun_file("../datasets/smhi_Falun.csv");
  while(falun_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  falun_file.close();
  cout << "Falun done" << endl;

  ifstream boras_file("../datasets/smhi_Boras.csv");
  while(boras_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  boras_file.close();
  cout << "Boras done" << endl;

  ifstream visby_file("../datasets/smhi_Visby.csv");
  while(visby_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  visby_file.close();
  cout << "Visby done" << endl;

  ifstream karlstad_file("../datasets/smhi_Karlstad.csv");
  while(karlstad_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  karlstad_file.close();
  cout << "Karlstad done" << endl;

  ifstream umea_file("../datasets/smhi_Umea.csv");
  while(umea_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  umea_file.close(); 
  cout << "Umea done" << endl;

  ifstream lulea_file("../datasets/smhi_Lulea.csv");
  while(lulea_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  lulea_file.close();
  cout << "Lulea done" << endl; 

  ifstream soderarm_file("../datasets/smhi_Soderarm.csv");
  while(soderarm_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  soderarm_file.close(); 
  cout << "Soderarm done" << endl;

  ifstream falsterbo_file("../datasets/smhi_Falsterbo.csv");
  while(falsterbo_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } // end if contains
  } // end while file
  falsterbo_file.close();
  cout << "Falsterbo done" << endl; 
  cout << endl;
  
  Double_t mean = hist->GetMean(); //The mean of the distribution
  Double_t stdev = hist->GetRMS(); //The standard deviation
  cout << "Mean: " << mean << endl;
  cout << "Stdev : " << stdev << endl;
  TCanvas* can = new TCanvas();
  hist->Draw();

  //TLegend *legend = new TLegend(0.75,0.75,0.95,0.95);
  //legend->AddEntry(hist,"Histogram","l");
  //legend->Draw(); 

} // End tempOnDay
 
