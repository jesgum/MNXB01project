#include <TF1.h> 
#include <TH1.h> 
#include <TStyle.h>
#include <TCanvas.h>
#include <fstream>
#include <iostream>

using namespace std; 

void tempOnDay(Int_t year, Int_t month, Int_t day) {
ifstream file("../datasets/smhi-opendata_1_72450_20210926_100728_Boras.csv");

string helpString;
Int_t counter = 0;
cout << counter << endl;
while(file >> helpString){
  cout << helpString << endl;
  counter++;
  
  if(counter > 100){
    break;
  }
}


}
 
