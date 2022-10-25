#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


class tempTrender {
	public:
	explicit tempTrender(const std::string& filePath) { //Construct using the specified file
		ifstream file(filePath);
		double num1{-1}; int num2{-1};double num3{-1};
		int i{0};
		vector<double> Temp{};
		//int nEntries{24};
		//double TempAvg[nEntries];
		while(file >> num1 >> num2 >> num3) {
			Temp.push_back(num3);
			if ((i+1)%3==0) {
				int j = (i+1)/3-1;
				//TempAvg[j] = (Temp[i]+Temp[i-1]+Temp[i-2])/3;
				_Temp.push_back((Temp[i]+Temp[i-1]+Temp[i-2])/3);
				//_Day.push_back(j);
				//cout << "Avgg temp is " << TempAvg[j] << endl;
			};
			i++;
		}
		cout << "Filee read" << endl;
	}

		~tempTrender() {} //Destructor

		// void tempOnDay(int monthToCalculate, int dayToCalculate) const; //Make a histogram of the temperature on this day
		// void tempOnDay(int dateToCalculate) const; //Make a histogram of the temperature on this date
		std::string tempPerDay() const {  //Make a histogram of the average temperature of each day of the year   //Add const!!
			TCanvas *c1 = new TCanvas("c1","Title",200,10,700,500);
			
			//c1->SetFillColor(42);
			//c1->SetGrid();
		
			//gr = new TGraph(n,x,y);

			//gr->SetLineColor(2);
			//gr->SetLineWidth(4);
			//gr->SetMarkerColor(4);
			//gr->SetMarkerStyle(21);
			//gr->SetTitle("a simple graph");
			//gr->GetXaxis()->SetTitle("X title");
			//gr->GetYaxis()->SetTitle("Y title");
			//gr->Draw("ACP");

			// TCanvas::Update() draws the frame, after which one can change it
			// c1->Update();
			// c1->GetFrame()->SetFillColor(21);
			// c1->GetFrame()->SetBorderSize(12);
			// c1->Modified();

			
			return "Created a histogram of the average temperature of each day of the year";
		}

	
	// void hotCold() const; //Make a histogram of the hottest and coldest day of the year
	// void tempPerYear(int yearToExtrapolate) const; //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
		vector<double> _Temp;
		//vector<int> _Day;

};
#endif
