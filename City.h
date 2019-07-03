#ifndef _City_h_
#define _City_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQUAL 0
#define LESS_THAN 1
#define GREATER_THAN 2

typedef struct City{
    
    char name[32];
    char stateCode[3];

}City;

City* newCity(char *name, char *stateCode);

// used by test.c
City* newCity(char *name, char *stateCode){
    
    // if char *name is NULL
    if( NULL == name ){
        printf("\n\n\tWarning: City.h: newCity(): char *name was NULL\n\n");
    }
    
    // if char *stateCode is NULL
    if( NULL == stateCode ){
        printf("\n\n\tWarning: City.h: newCity(): char *stateCode was NULL\n\n");
    }

    // says that a new City was unable to be created
    if( NULL == name || NULL == stateCode ){
        printf("\n\n\tWarning: City.h: newCity(): unable to create new City since NULL was received\n\n");
        return NULL;
    }

    City *c = (City*)malloc(sizeof(City));
    
    if( NULL == c ){
        printf("\n\n\tError: City.h: newCity(): unable to allocate memory for City *c\n\n");
        exit(1);
    }
    
    // if the received name is too long, the name is shortened
    if( strlen(name) > 31 ){
        name[31] = '\0';
    }
    
    // if the received stateCode is too long, it is shortened
    if( strlen(stateCode) > 2 ){
        stateCode[2] = '\0';
    }
    
    // assigns name and stateCode to the City
    strcpy(c->name, name);
    strcpy(c->stateCode, stateCode);

    return c;
}

// returns LESS_THAN, EQUALS, GREATER_THAN, or ERROR
int compareCities(void *firstValue, void *secondValue){
    
    firstValue = (City*)firstValue;
    secondValue = (City*)secondValue;

    if( NULL == firstValue ){
        printf("\n\n\tWarning: LinkedList.h: compareValues(): void *firstValue was NULL\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: LinkedList.h: compareValues(): void *secondValue was NULL\n\n");
        return -1;
    }


    // MODIFICATION BEGINS HERE
    City *cityOne = (City*)firstValue;
    City *cityTwo = (City*)secondValue;
    
    if( NULL == cityOne->name ){
        printf("\n\n\tWarning: LinkedList.h: compareValues(): cityOne->name is NULL\n\n");
        return -1;
    }

    if( NULL == cityTwo->name ){
        printf("\n\n\tWarning: LinkedList.h: compareValues(): cityTwo->name is NULL\n\n");
        return -1;
    }

    int comparisonResult = strcmp(cityOne->name, cityTwo->name);
    
    if( comparisonResult < 0 ){
        return LESS_THAN;
    }

    else if( comparisonResult > 0 ){
        return GREATER_THAN;
    }

    else{
        return EQUAL;
    }
}

// used by the printList function in LinkedList.h
void printCity(City *c){
    
    printf("%s, %s\n", c->name, c->stateCode);
}

#endif








