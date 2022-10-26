#include <iostream>
#include "tempTrender.h"

tempTrender::tempTrender(const std::string& filePath) {
	std::cout << "The user supplied " << filePath <<" as the path to the data file.\n";
	ifstream file(filePath);
	double num1{-1}; int num2{-1};double num3{-1};
	int i{0};
	vector<double> Temp{};
	while(file >> num1 >> num2 >> num3) {
		Temp.push_back(num3);
		if ((i+1)%3==0) {
			int j = (i+1)/3-1;
			//_Temp.push_back((Temp[i]+Temp[i-1]+Temp[i-2])/3);
			//_Day.push_back(j);
			_Day[j]=j;
			_Temp[j]=(Temp[i]+Temp[i-1]+Temp[i-2])/3;
			//cout << i << endl;
			//cout << j << endl;
		};
		i++;
	}
}

// void tempTrender::tempOnDay(int monthToCalculate, int dayToCalculate) const {} //Make a histogram of the temperature on this day
// void tempTrender::tempOnDay(int dateToCalculate) const {} //Make a histogram of the temperature on this date

std::string tempTrender::tempPerDay() const {
	//TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
	//c1->SetFillColor(42);
	//c1->SetGrid();
	//const Int_t n = 20;
	//Double_t x[n], y[n];
	//for (Int_t i=0;i<n;i++) {
		//x[i] = i*0.1;
		//y[i] = 10*sin(x[i]+0.2);
	//}

	//gr = new TGraph(n,x,y);
	//gr->SetLineColor(2);
	//gr->SetLineWidth(4);
	//gr->SetMarkerColor(4);
	//gr->SetMarkerStyle(21);
	//gr->SetTitle("a simple graph");
	//gr->GetXaxis()->SetTitle("X title");
	//gr->GetYaxis()->SetTitle("Y title");
	//gr->Draw("ACP");

	// c1->Update();
	// c1->GetFrame()->SetFillColor(21);
	// c1->GetFrame()->SetBorderSize(12);
	// c1->Modified();


	return "Created histogram";
} //Make a histogram of the average temperature of each day of the year


// void tempTrender::hotCold() const {} //Make a histogram of the hottest and coldest day of the year
// void tempTrender::tempPerYear(int yearToExtrapolate) const {} //Make a histogram of average temperature per year, then fit and extrapolate to the given year
