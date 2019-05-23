#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "City.h"
#define BUFFER_SIZE 50

void printSomething(void *value);

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
        // printf("NEW CITY: %s, %s\n", c->name, c->stateCode);
        insertValue(list, c);
    }
    
    if( false == isEmpty(list) ){
        printf("The list is not empty\n");
    }
    printf("\n");

    printList(list);
    printf("Length before: %d\n", list->length);

    printf("\n");   
    
    LinkedList *places = newLinkedList();

    City *remOne = newCity("Houston", "TX");
    City *remTwo = newCity("New York", "NY");
    City *remThree = newCity("San Jose", "CA"); 
    
    
    insertAtIndex(places, remOne, 0);
    insertValue(places, remThree);
    insertAtIndex(places, remTwo, 1);
    
    printf("\n\nplaces:\n");
    printList(places);

    freeValue(remOne);
    freeValue(remTwo);
    freeValue(remThree);

    freeList(list);
    freeList(places);

    fclose(fpData);

    return 0;
}













