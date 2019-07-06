# generateComparisons


DESCRIPTION


Bash script that generates a header file (Comparisons.h) to be used by LinkedList.h


WHAT IS Comparisons.h?


Each Linked List must be given a function to compare values. That means that the user must write a function to compare the data type being stored in the list. Comparisons.h contians functions that will compare most of the built in types in C


USAGE


You must have generateComparisons.sh, typeList.txt, comparisonTemplate.txt, and compareString.txt in the same folder


chmod u+x generateComparisons.sh


./generateComparisons.sh < typeList.txt
