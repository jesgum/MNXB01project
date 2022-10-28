#include "tempTrender.h"

#include "tempOnDay.C"
#include "comp.C"

#include <string>
#include <iostream>
using namespace std;

void TempPerDay() {
	const string pathToFile = "/home/akamal/git/MNXB01project/MNXB01-project/datasets/smhiLund_8089.csv";  
	tempTrender t(pathToFile); //Instantiate your analysis object

	cout << t.tempPerDay() << endl;
}

void TempOnDay(int Month, int Day) {
	system("data_cleaner.sh");  //Calls batch script to filer data
	tempOnDay(Month, Day);	   //Calls function in tempOnDay.C root file
}

void Compare(int Month) {
	system("data_cleaner.sh");
	comp(Month);
}

