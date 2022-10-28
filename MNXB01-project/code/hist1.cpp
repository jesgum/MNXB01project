#include "TH1I.h"
#include "TF1.h"
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


double Gaussian(double* x, double* par) { //A custom function
  return par[0]*exp(-0.5*(x[0]*x[0] - 2*x[0]*par[1] +
    par[1]*par[1])/(par[2]*par[2]));
}


int main()
{
	TCanvas *c1 = new TCanvas("c1", "c1");

	histo_plot("minVals.txt");
	c1->Update();
	histo->SetLineColor(kRed);
	histo->SetFillColor(kRed);
	
	histo_plot("maxVals.txt");
	histo->SetLineColor(kBlue);
	histo->SetFillColor(kBlue);

	TF1* func = new TF1("Gaussian", Gaussian, 90, 300, 3);
	func->SetParameters(5, 190, 50); //Starting values for fitting
	func->SetLineColor(kBlack);
	histo->Fit(func, "QR");

	histo->Draw("SAME");

	cout << "The mean is " << func->GetParameter(1) << endl;
	c1->Print("demo.pdf");
	return 0;
}
