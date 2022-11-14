# MNXB01project


# How to use this shared repository:
I've constructed a main and work branch. You guys pull it. Create and edit files inside the work branch.  Whenever you do something significant in your local work branch, commit to your local main branch with a descriptive comment (we will need these to construct our ChangeLog). Now and then, when you've finished a part, send me a pull request to merge your local main with the remote main.



# How to compile and run the code:

## How to compile Zack's part:

1. Open file datafilter.sh, at the second line edit FILE to be the name of your file without any extension, e.g. FILE='myfilename'. Run this code on the bash terminal. This should createtwo different files called min.txt and max.txt, you can change the name of these output files by editing the 3rd and 4th line, e.g. OUT_MIN=yourfilename.txt.

2. Compile the csvreader-2.cpp file and run, make sure you edit the input file names if changed in the previous bash file. This should then result in two more output files maxVals.txt and minVals.txt. 

3. The final step is to compile and run the hist1.cpp code, When compling hist1.cpp make sure to use root config to get the correct flags. When compling hist1.cpp make sure to use root config to get the correct flags
 e.g - g++ hist1.cpp $(root-config --glibs --cflags --libs) -o main 
     
## How to compile Jesper's part:

### TempOnDay(int Month, int Day)
1. Specify include path for header(s) in "rootlogon.C" ~/MNXB01-project/code/include (please use full path and not relative).
2. Start "root"
3. Now you can call "[] TempOnDay(int Month, int Day)"

### Compare(int Month)
1. Same as tempOnDay 1
2. Same as tempOnDay 2
3. Now you can call "[] Compare(int Month)"

## How to compile Ashar's part:

### TempPerDay()
1. Run data_cleaner2.sh, located in /code
2. Same as tempOnDay 1
3. Same as tempOnDay 2
4. Now you can call "[] TempPerDay()"
