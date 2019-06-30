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
    LinkedList *list = newLinkedList();

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
    
    LinkedList *clone = (LinkedList*)cloneList(list);
    printf("\nCloned list:\n");
    printList(clone);

    printf("\nOriginal List:\n");
    City *lookingFor = newCity("New York", "NY");
    // void *wasFound = containsValue(list, lookingFor);
    
    removeValue(list, lookingFor);
    void *wasFound = sortedContainsValue(list, lookingFor);

    if( NULL == wasFound ){
        printf("The city was not found...\n");
    }

    else{
        printf("The city was found!\n");
        printCity(wasFound);
        printf("\n");
    }

    printf("Cloned List:\n");
    // void *wasFound = containsValue(list, lookingFor);
    // removeValue(clone, lookingFor);
    wasFound = sortedContainsValue(clone, lookingFor);

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
    
    return 0;
}

void printListLength(void *listStruct){
    
    LinkedList *list = (LinkedList*)listStruct;
    printf("\nLength of the list is: %d\n", list->length);
}













