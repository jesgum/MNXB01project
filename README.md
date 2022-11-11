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

Open file datafilter.sh, at the second edit FILE to be the name of your file without any extension, e.g. FILE='myfilename'. Run this code on the bash terminal. This should createtwo different files called min.txt and max.txt, you can change the name of these output files by editing the 3rd and 4th line, e.g. OUT_MIN=yourfilename.txt.

Compile the csvreader-2.cpp file and run, make sure you edit the input file names if changed in the previous bash file. This should then result in two more output files maxVals.txt and minVals.txt. 

The final step is to compile and run the hist1.cpp code, When compling hist1.cpp make sure to use root config to get the correct flags
 e.g - g++ hist1.cpp $(root-config --glibs --cflags --libs) -o main 

~                                        
