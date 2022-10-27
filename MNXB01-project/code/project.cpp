#include "tempTrender.h"

#include "tempOnDay.C"
#include "comp.C"

#include <string>
#include <iostream>
using namespace std;

void TempPerDay() {
	const string pathToFile = "/home/akamal/git/MNXB01project/MNXB01-project/datasets/smhi_Lund_1965";   //"../datasets/smhi_Lund_1965" 
	tempTrender t(pathToFile); //Instantiate your analysis object

	cout << "cpp file works" << endl;
	cout << t.tempPerDay() << endl;
}

void TempOnDay(int Month, int Day) {
	system("data_cleaner.sh");  //Calls batch script to filer data
	tempOnDay(Month, Day);
}

void Compare(int Month) {
	system("data_cleaner.sh");
	comp(Month);
}

