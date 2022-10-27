#!/bin/bash
#84,88 leap year. Line 178-180
> TempFile1     #Empty content of file 

for i in {1981..1990}
do
	grep "$i" smhi-opendata_1_53430_20210926_101122_Lund.csv >> TempFile1
	if [ "$i" == 1984 ] || [ "$i" == 1988 ]
	then
		echo "leap year!"
		
	fi
done	 

	awk 'BEGIN {FS = ";"} ; {print $1,$3}' TempFile1 > TempFile2

	grep -v 02-29 TempFile2 > TempFile3
        sed -i 's/-//' TempFile3
	sed -i 's/-//' TempFile3

	awk '{print NR " " $0}' TempFile3 > smhiLund_8089.csv
	
	#Clean-up of temporary files
	rm TempFile1
	rm TempFile2
	rm TempFile3

