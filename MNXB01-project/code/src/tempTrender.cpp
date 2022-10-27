#include <iostream>
#include "tempTrender.h"
#include <fstream>
#include <TCanvas.h>
#include <TH1.h>
using namespace std;

tempTrender::tempTrender(const std::string& filePath) {
	std::cout << "The user supplied " << filePath <<" as the path to the data file.\n";
	ifstream file(filePath);	//Read filtered file
	double num1{-1}; int num2{-1};double num3{-1};
	int i{0};

	//Temp will contain all temperature meassurments between 1981-1990. ATemp is the daily average termperature between 1981-1990.
	vector<double> Temp{}; vector<double> ATemp{};	

	while(file >> num1 >> num2 >> num3) {
		Temp.push_back(num3);
		if ((i+1)%3==0) {
			ATemp.push_back((Temp[i]+Temp[i-1]+Temp[i-2])/3);	//3 measurments per day. Average them.
		};
		i++;
	}
	for (int j=0; j<365; j++) {		//Measurments taken over 10 years. Average them.
		double a{0};
		double b{0};
		for (int k=0; k<10; k++) {
			a+=ATemp[j+k*365];
		}
		_Temp[j]=a/10;
		for (int l=0; l<10; l++) {	//Associated errors
			b+= pow(ATemp[j+l*365]-_Temp[j], 2);
		}
		_Error[j]=sqrt(b/10);
	}
}


std::string tempTrender::tempPerDay() const {	//Constructing histogram
	TCanvas* c1 = new TCanvas("c1", "TempPerDay canvas", 900, 600);

	TH1D* PerDayHist = new TH1D("PerDayHist", "Temperature for every day of the year",365, 1, 366);
	for(int bin=1; bin<366; ++bin) {	//Fill bins with measurments and error bars
		PerDayHist->SetBinContent(bin,_Temp[bin-1]);
		PerDayHist->SetBinError(bin,_Error[bin-1]);
	}
	PerDayHist->SetTitle("Temperature for every day of the year");
	PerDayHist->GetXaxis()->SetTitle("Day");
	PerDayHist->GetYaxis()->SetTitle("Temperature [#circC]");
	PerDayHist->GetYaxis()->CenterTitle(true);
	PerDayHist->GetXaxis()->CenterTitle(true);


	PerDayHist->Draw();
	return "Here is a histogram of the daily average temperature between 1981-1990";
} 


