# MNXB01project


# How to use this shared repository:
I've constructed a main and work branch. You guys pull it. Create and edit files inside the work branch.  Whenever you do something significant in your local work branch, commit to your local main branch with a descriptive comment (we will need these to construct our ChangeLog). Now and then, when you've finished a part, send me a pull request to merge your local main with the remote main.





# How to compile and run the code:

##How to compile Zack's part:

1. Specify input file for datafilter.sh.
 e.g. test.csv

2. Use output file as input for csvreader.cpp, this should give a single file txt file as output
 e.g input-> test.csv
     output -> testVals.txt

3. Use the value file made as input for plotting code, hist1.cpp. This takes 2 files as input
 e.g. input -> minVals.txt, maxVals.txt

4. When compling hist1.cpp make sure to use root config to get the correct flags
 e.g - g++ hist1.cpp $(root-config --glibs --cflags --libs) -o main 


                                        

## How to compile Jesper's part:

### TempOnDay(int Month, int Day)
1. Specify include path for header(s) in "rootlogon.C" ~/MNXB01-project/code/include (please use full path and not relative).
2. Start "root"
3. Now you can call "[] TempOnDay(int Month, int Day)"

### Comp(int Month)
1. Same as tempOnDay 1
2. Same as tempOnDay 2
3. Now you can call "[] Comp(int Month)"

## How to compile Ashar's part:

### TempPerDay()
1. Same as tempOnDay 1
2. Same as tempOnDay 2
3. Now you can call "[] TempPerDay()"
