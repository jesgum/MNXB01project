#!/bin/bash
echo "Formatting datasets..."

FILE=../datasets/smhi_Falsterbo.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_52230_20210926_100815_Falsterbo.csv > ../datasets/smhi_Falsterbo.csv
	sed -i 's/-//' ../datasets/smhi_Falsterbo.csv
	sed -i 's/-//' ../datasets/smhi_Falsterbo.csv
    echo "File created: smhi_Falsterbo.csv"
fi

FILE=../datasets/smhi_Lund.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_53430_20210926_101122_Lund.csv > ../datasets/smhi_Lund.csv
	sed -i 's/-//' ../datasets/smhi_Lund.csv
	sed -i 's/-//' ../datasets/smhi_Lund.csv
    echo "File created: smhi_Lund.csv"
fi

FILE=../datasets/smhi_Boras.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_72450_20210926_100728_Boras.csv > ../datasets/smhi_Boras.csv
	sed -i 's/-//' ../datasets/smhi_Boras.csv
	sed -i 's/-//' ../datasets/smhi_Boras.csv
	echo "File created: smhi_Boras.csv"
fi


FILE=../datasets/smhi_Visby.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_78400_20210926_101340_Visby.csv > ../datasets/smhi_Visby.csv
	sed -i 's/-//' ../datasets/smhi_Visby.csv
	sed -i 's/-//' ../datasets/smhi_Visby.csv
	echo "File created: smhi_Visby.csv"
fi

FILE=../datasets/smhi_Karlstad.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_93250_20210926_100622_Karlstad.csv > ../datasets/smhi_Karlstad.csv
	sed -i 's/-//' ../datasets/smhi_Karlstad.csv
	sed -i 's/-//' ../datasets/smhi_Karlstad.csv
	echo "File created: smhi_Karlstad.csv"
fi

FILE=../datasets/smhi_Soderarm.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_99450_20210926_101209_Soderarm.csv > ../datasets/smhi_Soderarm.csv
	sed -i 's/-//' ../datasets/smhi_Soderarm.csv
	sed -i 's/-//' ../datasets/smhi_Soderarm.csv
	echo "File created: smhi_Soderarm.csv"
fi

FILE=../datasets/smhi_Falun.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_105370_20210926_100841_Falun.csv > ../datasets/smhi_Falun.csv
	sed -i 's/-//' ../datasets/smhi_Falun.csv
	sed -i 's/-//' ../datasets/smhi_Falun.csv
	echo "File created: smhi_Falun.csv"
fi

FILE=../datasets/smhi_Umea.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_140480_20210926_101307_Umea.csv > ../datasets/smhi_Umea.csv
	sed -i 's/-//' ../datasets/smhi_Umea.csv
	sed -i 's/-//' ../datasets/smhi_Umea.csv
	echo "File created: smhi_Umea.csv"
fi

FILE=../datasets/smhi_Lulea.csv
if ! [[ -f "$FILE" ]]; then
	awk 'BEGIN {FS = ";"} ; /;G/ {print $1, $3}' ../datasets/smhi-opendata_1_162870_20210926_101011_Lulea.csv > ../datasets/smhi_Lulea.csv
	sed -i 's/-//' ../datasets/smhi_Lulea.csv
	sed -i 's/-//' ../datasets/smhi_Lulea.csv
	echo "File created: smhi_Lulea.csv"
fi

echo "Done"
