#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 

ifstream inputFile;
ofstream outfile;

int day;
double temp;
string tme;
string qual;
string tempstring;

vector<int> dys = {};       

int main(int argc, char** argv) {
    
    inputFile.open("max.txt");
    outfile.open("maxVals.txt");

    string line = "";
    while(getline(inputFile, line)){
        tempstring = "";

	// string count;
        stringstream inputString(line);
    
        getline(inputString, tempstring, ',');
        day = atoi(tempstring.c_str());
        getline(inputString, tme, ',');
        tempstring = "";
        getline(inputString, tempstring, ',');
        temp = atof(tempstring.c_str());
        getline(inputString, qual, ',');

        dys.push_back(day);

        line = "";
    
    for (auto v : dys)
        outfile << v << "\n";
    }
   
    outfile.close();
    return 0;        
}
