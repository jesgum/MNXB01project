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
~                                        

How to compile Jesper's part:

# tempOnDay
1. From this directory as source go to /MNXB01-project/code
2. Run bash script "data_cleaner.sh"
2.5 (Optional) open tempOnDay and choose dataset, default is Lund.
3. Open "Root" 
4. Load the tempOnDay function ".L tempOnDay.C"
5. Generate histogram tempOnDay(Int_t month, Int_t day), example "tempOnDay(6,19)"
6. Histogram is also saved as 'tempOnDay.jpg'
