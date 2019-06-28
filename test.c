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
    // LinkedList *list = newLinkedList();
    Stack *list = newStack();

    City *c;
    
    // reads in data from cities.txt
    while( NULL != fgets(buffer, BUFFER_SIZE, fpData) ){
        
        iScanCnt = sscanf( buffer, "%[^,], %s", cityName, cityStateCode );
        c = newCity( cityName, cityStateCode );
        // printf("NEW CITY: %list, %list\n", c->name, c->stateCode);
        // insertValue(list, c);
        insertSorted(list, c);
    }
    
    printf("\nOriginal data in List Structure:\n");
    printList(list);

    void **arr = listToDependentArray(list);
    printf("\nOriginal data in array:\n");
    printArray(arr);
    printf("\nThe size of the array is %d\n", arrayLength(arr)); 
    
    printf("\n");
    City *lookingFor = newCity("Houston", "TX");
    void *wasFound = binarySearch(arr, list->length, lookingFor);

    if( NULL == wasFound ){
        printf("The city was not found...\n");
    }

    else{
        printf("The city was found!\n");
        printCity(wasFound);
        printf("\n");
    }

    // City *remOne = newCity("Houston", "TX");
    // City *remTwo = newCity("New York", "NY");
    // City *remThree = newCity("San Jose", "CA"); 
    
    // freeValue(remOne);
    // freeValue(remTwo);
    // freeValue(remThree);
    
    freeList(list);
    fclose(fpData);
    
    freeDependentArray(arr);

    return 0;
}

void printListLength(void *listStruct){
    
    LinkedList *list = (LinkedList*)listStruct;
    printf("\nLength of the list is: %d\n", list->length);
}













