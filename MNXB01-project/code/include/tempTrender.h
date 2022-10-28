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
	explicit tempTrender(const std::string& filePath); //Constructor initializes Average daily temperature
							   // over a period of years, and associated error bars
	~tempTrender() {} //Destructor

	std::string tempPerDay() const; //tempPerDay memeber function constructs the histogram with error bars
	
	private:
		double _Error[365];	//Error assocoiated with measurment. 365 entries for 365 days of the year.
		double _Temp[365];	//Measurment itself. 29 february (extra day in leap year) removed in filtering process!
};
#endif
