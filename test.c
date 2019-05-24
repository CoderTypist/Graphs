#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "City.h"
#define BUFFER_SIZE 50

void printListLength(LinkedList *list);

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
        // insertValue(list, c);
        insertSorted(list, c);
    }
    
    if( false == isEmpty(list) ){
        printf("The list is not empty\n");
    }
    printf("\n");

    printList(list);
    printf("Length before: %d\n", list->length);

    printf("\n");   
    
    // testing insertSorted
    LinkedList *places = newLinkedList();

    City *remOne = newCity("Houston", "TX");
    City *remTwo = newCity("New York", "NY");
    City *remThree = newCity("San Jose", "CA"); 
    
    insertSorted(places, remOne);
    insertSorted(places, remTwo);
    insertSorted(places, remThree);
    
    printf("\n\nplaces:\n");
    printList(places);

    freeValue(remOne);
    freeValue(remTwo);
    freeValue(remThree);
    
    // testing removeAtIndex()
    printListLength(list);
    remOne = removeAtIndex(list, 9);
    printListLength(list);
    remTwo = removeAtIndex(list, 0);
    printListLength(list);
    remThree = removeAtIndex(list, 2);
    printListLength(list);

    printf("\n\nTesting removeAtIndex():\n");
    printList(list);
    printf("List length after: %d\n", list->length);
    printf("\nGotta represent %s\n", remThree->name);

    freeValue(remOne);
    freeValue(remTwo);
    freeValue(remThree);

    freeList(list);
    freeList(places);

    fclose(fpData);

    return 0;
}

void printListLength(LinkedList *list){
    
    printf("\nLength of the list is: %d\n", list->length);
}













