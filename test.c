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
    Stack *s = newStack();

    City *c;
    
    // reads in data from cities.txt
    while( NULL != fgets(buffer, BUFFER_SIZE, fpData) ){
        
        iScanCnt = sscanf( buffer, "%[^,], %s", cityName, cityStateCode );
        c = newCity( cityName, cityStateCode );
        // printf("NEW CITY: %s, %s\n", c->name, c->stateCode);
        // insertValue(list, c);
        push(s, c);
    }
    
    printf("\nOriginal data in List Structure:\n");
    printList(s);

    void **arr = listToIndependentArray(s);
    printf("\nOriginal data in array:\n");
    printArray(arr);
    printf("\nThe size of the array is %d\n", arrayLength(arr)); 

    // City *cityFromArray = arr[0];
    // strcpy(cityFromArray->name, "Pizza Town");
    
    strcpy( ((City*)s->pHead->value)->name, "Pizza Town");

    printf("\nData in array after the change:\n");
    printArray(arr);

    printf("\nData in the List Structure after the change:\n");
    printList(s);

    if( false == isEmpty(s) ){
        printf("The queue is not empty\n");
    }
    printf("\n");

    printStack(s);
    printf("\nLength before: %d\n", s->length);

    printf("\n");   

    City *sRem = pop(s);
    printf("Name of removed city: %s\n", sRem->name);
    printStack(s);
    printf("\nLength of queue is now: %d\n\n", s->length);

    // City *remOne = newCity("Houston", "TX");
    // City *remTwo = newCity("New York", "NY");
    // City *remThree = newCity("San Jose", "CA"); 
    
    // freeValue(remOne);
    // freeValue(remTwo);
    // freeValue(remThree);
    
    freeValue(sRem);
    freeStack(s);
    fclose(fpData);
    
    City *sample = newCity("Ababua", "AB");
    City *clone = cloneValue(sample);
    printf("ORIGINAL:\n");
    printCity(sample);
    printf("CLONE:\n");
    printCity(clone);
    freeValue(sample);
    freeValue(clone);

    return 0;
}

void printListLength(void *listStruct){
    
    LinkedList *list = (LinkedList*)listStruct;
    printf("\nLength of the list is: %d\n", list->length);
}













