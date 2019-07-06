#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "City.h"
#define BUFFER_SIZE 50

void printListLength(void *listStruct);
bool mySpecs(void *value);

int main(){
    
    FILE* fpData;
    
    // opens cities.txt
    if ( (fpData = fopen("cities.txt", "r")) == NULL ){
        printf("\n\nError: test.c: main(): Failed to open cities.txt\n\n");
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    // cityName and cityStateCode sizes are based off
    // specifications in City.h
    char cityName[32];
    char cityStateCode[3];
    int iScanCnt;
    // new City to be inserted to LinkedList
    LinkedList *list = newLinkedList();
    list->compareValues = compareCities;

    City *c;
    
    // reads in data from cities.txt
    while( NULL != fgets(buffer, BUFFER_SIZE, fpData) ){
        
        iScanCnt = sscanf( buffer, "%[^,], %s", cityName, cityStateCode );
        c = newCity( cityName, cityStateCode );
        // printf("NEW CITY: %list, %list\n", c->name, c->stateCode);
        insertSorted(list, c);
        // insertSorted(list, c);
    }
    
    printf("\nOriginal list:\n");
    printList(list);
    
    // City *lookingFor = newCity("Houston", "TX");
    // void **arr = listToDependentArray(list);
    // void *wasFound = binarySearch(arr, list->length, lookingFor, compareCities);
    
    LinkedList *replica = filteredCopy(list, mySpecs);
    printf("\nFiltered copy:\n");
    printList(replica);

    printf("\nUntouched original:\n");
    printList(list);

    printf("\nFiltered List:\n");
    filterList(list, mySpecs);
    printList(list);

    reverseList(list);
    printf("\nReverse list:\n");
    printList(list);

    // City *remOne = newCity("Houston", "TX");
    // City *remTwo = newCity("New York", "NY");
    // City *remThree = newCity("San Jose", "CA"); 

    // freeValue(remOne);
    // freeValue(remTwo);
    // freeValue(remThree);
    
    // freeDependentArray(arr);
    freeList(list);
    freeList(replica);
    fclose(fpData);
    
    return 0;
}

void printListLength(void *listStruct){
    
    LinkedList *list = (LinkedList*)listStruct;
    printf("\nLength of the list is: %d\n", list->length);
}

bool mySpecs(void *value){
    
    City *c = value;
    char* cityName = c->name;

    if( 'S' == cityName[0] ){
        return true;
    }
    
    return false;
}











