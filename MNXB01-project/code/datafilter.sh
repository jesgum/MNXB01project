#!/bin/bash


FILE='test'
OUT_MAX=max.txt
OUT_MIN=min.txt

# Clear file contents
> $OUT_MAX
> $OUT_MIN

tail -n +11 "$FILE.csv" > $FILE-clean.csv

# Get Max and Min for each year
for YEAR in {1884..2021}; do
	grep $YEAR $FILE-clean.csv | sort -k3 -g -t ';' | { head -n1 >> $OUT_MIN; tail -n1 >> $OUT_MAX; } > /dev/null;
done

# Sort by date
sort -o $OUT_MIN $OUT_MIN
sort -o $OUT_MAX $OUT_MAX

# Change date to day of year
sed -i -r 's#([0-9]{4}-[0-9]{2}-[0-9]{2})(.*)#printf "%s%s" $(date -d "\1" +%j) "\2";#ge' $OUT_MIN
sed -i -r 's#([0-9]{4}-[0-9]{2}-[0-9]{2})(.*)#printf "%s%s" $(date -d "\1" +%j) "\2";#ge' $OUT_MAX

