#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Queue.h"
#include "PriorityQueue.h"
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
    PriorityQueue *pq = newPriorityQueue();

    City *c;
    
    // reads in data from cities.txt
    while( NULL != fgets(buffer, BUFFER_SIZE, fpData) ){
        
        iScanCnt = sscanf( buffer, "%[^,], %s", cityName, cityStateCode );
        c = newCity( cityName, cityStateCode );
        // printf("NEW CITY: %s, %s\n", c->name, c->stateCode);
        // insertValue(list, c);
        priorityEnqueue(pq, c);
    }
    
    if( false == isEmpty(pq) ){
        printf("The queue is not empty\n");
    }
    printf("\n");

    printPriorityQueue(pq);
    printf("Length before: %d\n", pq->length);

    printf("\n");   

    City *pqRem = priorityDequeue(pq);
    printf("Name of removed city: %s\n", pqRem->name);
    printPriorityQueue(pq);
    printf("\nLength of queue is now: %d\n\n", pq->length);

    // City *remOne = newCity("Houston", "TX");
    // City *remTwo = newCity("New York", "NY");
    // City *remThree = newCity("San Jose", "CA"); 
    
    // freeValue(remOne);
    // freeValue(remTwo);
    // freeValue(remThree);
    
    freeValue(pqRem);
    freePriorityQueue(pq);
    fclose(fpData);

    return 0;
}

void printListLength(void *listStruct){
    
    LinkedList *list = (LinkedList*)listStruct;
    printf("\nLength of the list is: %d\n", list->length);
}













