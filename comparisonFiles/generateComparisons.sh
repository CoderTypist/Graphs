#!/bin/bash
# author Christian Bargraser

echo "// author Christian Bargraser" > ./Comparisons.h
echo "" >> ./Comparisons.h
echo "#ifndef _Comparisons_h_" >> ./Comparisons.h
echo "#define _Comparisons_h_" >> ./Comparisons.h
echo "" > ./comparisonPrototypes.txt
echo "" > ./comparisonFunctions.txt

while read unspaced && read spacedOut; do
    
    echo "$unspaced and $spacedOut"
    
    # reads the first line from the template
    read firstLine < ./comparisonTemplate.txt
    firstLine=$(echo "$firstLine" | sed "s/COMPACT/$unspaced/g")
    prototype="${firstLine};"
    echo "$prototype" >> ./comparisonPrototypes.txt

    header="${firstLine}{"
    echo "$header" >> ./comparisonFunctions.txt
    
    # reads the entire template
    isFirstLine=0
    while IFS= read line; do

        if [ 0 -eq "$isFirstLine" ]; then
            isFirstLine=1
            continue
        fi

        line=$(echo "$line" | sed "s/TYPE/$spacedOut/g")
        line=$(echo "$line" | sed "s/COMPACT/$unspaced/g")
        echo "line is $line"
        echo "$line" >> ./comparisonFunctions.txt

    done < ./comparisonTemplate.txt
    echo "" >> ./comparisonFunctions.txt

done

echo "int compareString(void *firstValue, void *secondValue);" >> ./comparisonPrototypes.txt
cat ./compareString.txt >> ./comparisonFunctions.txt

cat ./comparisonPrototypes.txt >> ./Comparisons.h
cat ./comparisonFunctions.txt >> ./Comparisons.h

echo "#endif" >> ./Comparisons.h
 


