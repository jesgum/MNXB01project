// tempOnDay.C
// Requires the script "data_format_filter.sh" to be executed

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
  

  // Read in the data and fill histogram
  ifstream lund_file("../datasets/smhi_Lund.csv");
  while(lund_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    }
  }
  lund_file.close();
  cout << "Lund done" << endl;

  ifstream falun_file("../datasets/smhi_Falun.csv");
  while(falun_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    }
  }
  falun_file.close();
  cout << "Falun done" << endl;

  ifstream boras_file("../datasets/smhi_Boras.csv");
  while(boras_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    }
  } 
  boras_file.close();
  cout << "Boras done" << endl;

  ifstream visby_file("../datasets/smhi_Visby.csv");
  while(visby_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    }
  }
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
    } 
  }
  umea_file.close(); 
  cout << "Umea done" << endl;

  ifstream lulea_file("../datasets/smhi_Lulea.csv");
  while(lulea_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } 
  } 
  lulea_file.close();
  cout << "Lulea done" << endl; 

  ifstream soderarm_file("../datasets/smhi_Soderarm.csv");
  while(soderarm_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    } 
  }
  soderarm_file.close(); 
  cout << "Soderarm done" << endl;

  ifstream falsterbo_file("../datasets/smhi_Falsterbo.csv");
  while(falsterbo_file >> line >> line_two) {
    line.Remove(0,4);
    if(line.Contains(Date)) {
      hist->Fill(line_two);
    }
  }
  falsterbo_file.close();
  cout << "Falsterbo done" << endl;   

  TString uppsala_year;
  TString uppsala_month;
  TString uppsala_day;
  Double_t day_avg_temp;
  Double_t day_avg_temp_corr;
  Int_t city;

  ifstream uppsala_file("../datasets/uppsala_tm_1722-2020.dat");
  while(uppsala_file >> uppsala_year >> uppsala_month >> uppsala_day >> day_avg_temp >> day_avg_temp_corr >> city) {
    if(uppsala_month.Length() == 1 ) {
      uppsala_month.Prepend("0");
    }
    line = uppsala_month + uppsala_day;
    if(line.Contains(Date)) {
      hist->Fill(day_avg_temp_corr);
    }  
  }
  uppsala_file.close();

  cout << "Uppsala done" << endl; 
  cout << endl;
  
  
  Double_t mean = hist->GetMean(); //The mean of the distribution
  Double_t stdev = hist->GetRMS(); //The standard deviation
  cout << "Mean: " << mean << endl;
  cout << "Stdev : " << stdev << endl;
  TCanvas* can = new TCanvas();
  hist->Draw();

  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  TString leg_text = "Temperature on " + DD + "/" + MM;
  leg->SetBorderSize(0);
  leg->AddEntry(hist, leg_text, "f");
  leg->Draw();

} // End tempOnDay
 
