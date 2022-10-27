#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 

ifstream inputfile;
ofstream outfile;

int day;
double temp;
string tme;
string qual;
string tempstring;

vector<int> dys = {};       

void read_temp(string input_name, string output_name) {
    inputfile.open(input_name);
    outfile.open(output_name);

    string line;
    while(getline(inputfile, line)){
	string token = line.substr(0, line.find(';'));
        day = atoi(token.c_str());
	outfile << day << '\n';
        dys.push_back(day);
    }

    outfile.close();
    inputfile.close();
    
}

int main(int argc, char** argv) {
    read_temp("max.txt", "maxVals.txt");
    read_temp("min.txt", "minVals.txt");
    return 0;        
}
