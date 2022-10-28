# MNXB01project


How to use this shared repository:
   I am a bit unsure on how to structure the repository, but this is how it currently looks: I've
   constructed a main and work branch. You guys pull it. Create and edit files inside the work branch,
   inside your personal directory.  Whenever you do something significant in your local work branch,
   commit to your local main branch with a descriptive comment (we will need these to construct our
   ChangeLog, unless we decide to do it some other way). Now and then, when you've finished a part,
   send me a pull request to merge your local main with the remote main (i.e main on github).

   Let me know if the exists a more resonable way.



How to compile and run the code:

Specify input file for datafilter.sh.
 e.g. test.csv

Use output file as input for csvreader.cpp, this should give a single file txt file as output
 e.g input-> test.csv
     output -> testVals.txt

Use the value file made as input for plotting code, hist1.cpp. This takes 2 files as input
 e.g. input -> minVals.txt, maxVals.txt

When compling hist1.cpp make sure to use root config to get the correct flags
 e.g - g++ hist1.cpp $(root-config --glibs --cflags --libs) -o main 

~                                        
