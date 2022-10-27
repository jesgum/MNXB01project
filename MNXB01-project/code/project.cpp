#include "tempTrender.h"
//#include "tempTrender.cpp"

#include <string>
#include <iostream>
using namespace std;

void project() {
	const string pathToFile = "/home/akamal/git/MNXB01project/MNXB01-project/datasets/Test1";   //"../datasets/smhi_Lund_1965" 
	tempTrender t(pathToFile); //Instantiate your analysis object

	cout << "cpp file works" << endl;
	cout << t.tempPerDay() << endl;
}

int main() {
	project();
}
