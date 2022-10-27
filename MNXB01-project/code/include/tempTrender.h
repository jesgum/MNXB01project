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
	explicit tempTrender(const std::string& filePath); 
	~tempTrender() {} //Destructor

	std::string tempPerDay() const; 
	
	private:
		int _Day[365];
		double _Temp[365];
};
#endif
