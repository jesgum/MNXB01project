#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <TObject.h>
using namespace std;


class tempTrender {
	public:
	explicit tempTrender(const std::string& filePath); 
	~tempTrender() {} //Destructor

	string tempPerDay() const;

	// void tempOnDay(int monthToCalculate, int dayToCalculate) const; //Make a histogram of the temperature on this day
	// void tempOnDay(int dateToCalculate) const; //Make a histogram of the temperature on this date
	// void hotCold() const; //Make a histogram of the hottest and coldest day of the year
	// void tempPerYear(int yearToExtrapolate) const; //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
		//vector<double> _Temp;
		//vector<int> _Day;
		int _Day[24];
		double _Temp[24];

};
#endif
