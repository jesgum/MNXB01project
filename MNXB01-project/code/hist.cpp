#include "TH1I.h"
#include "TCanvas.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream file;
TH1I* histo; 

void histo_plot(string input_name) {
	histo = new TH1I("hist", "histogram", 365, 1, 365);
	file.open(input_name, ios::in);
	
	int value;
	while(!file.eof())
	{ 
		file >> value;
		histo->Fill(value);
	}

	histo->GetXaxis()->SetTitle("Days");
	histo->GetYaxis()->SetTitle("Entries");

	histo->Draw("SAME");
	file.close();
	
}

int main()
{
	TCanvas *c1 = new TCanvas("c1", "c1");

	histo_plot("maxVals.txt");
	c1->Update();
	histo->SetLineColor(kRed);
	histo->SetFillColor(kRed);
	histo_plot("minVals.txt");
	histo->SetLineColor(kBlue);
	histo->SetFillColor(kBlue);
	c1->Print("demo.pdf");
	return 0;
}
