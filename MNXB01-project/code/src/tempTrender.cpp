#include <iostream>
#include "tempTrender.h"
#include <fstream>
#include <TCanvas.h>
#include <TH1.h>
using namespace std;

tempTrender::tempTrender(const std::string& filePath) {
	std::cout << "The user supplied " << filePath <<" as the path to the data file.\n";
	ifstream file(filePath);
	double num1{-1}; int num2{-1};double num3{-1};
	int i{0};
	//int j{0};
	vector<double> Temp{}; vector<double> ATemp{};
	while(file >> num1 >> num2 >> num3) {
		Temp.push_back(num3);
		if ((i+1)%3==0) {
			//int k = (i+1)/3-1;
			//_Day[k]=k;
			ATemp.push_back((Temp[i]+Temp[i-1]+Temp[i-2])/3);
		};
		i++;
	}
	for (int j=0; j<365; j++) {
		int a{0};
		for (int k=0; k<10; k++) {
			a+=ATemp[j+k*365];
		}
		_Temp[j]=a/10;
	}
}


std::string tempTrender::tempPerDay() const {
	TCanvas* c1 = new TCanvas("c1", "TempPerDay canvas", 900, 600);
	//c1->SetFillColor(42);

	TH1D* PerDayHist = new TH1D("PerDayHist", "Temperature for every day of the year",365, 1, 366);
	for(int bin=1; bin<366; ++bin) {
		PerDayHist->SetBinContent(bin,_Temp[bin-1]);
	}
	PerDayHist->SetTitle("Temperature for every day of the year");
	PerDayHist->GetXaxis()->SetTitle("Day");
	PerDayHist->GetYaxis()->SetTitle("Temperature [#circC]");

	PerDayHist->Draw();
	return "Created histogram";
} //Make a histogram of the average temperature of each day of the year


