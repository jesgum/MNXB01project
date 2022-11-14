# Instructions:

Specify input file for datafilter.sh.
 e.g. test.csv

Use output file as input for csvreader.cpp, this should give a single file txt file as output
 e.g input-> test.csv
     output -> testVals.txt

Use the value file made as input for plotting code, hist1.cpp. This takes 2 files as input
 e.g. input -> minVals.txt, maxVals.txt

When compling hist1.cpp make sure to use root config to get the correct flags
 e.g - g++ hist1.cpp $(root-config --glibs --cflags --libs) -o main 

