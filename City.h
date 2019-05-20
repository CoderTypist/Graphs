#ifndef _City_h_
#define _City_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// used by the printList function in LinkedList.h
void printCity(City *c){
    
    printf("%s, %s\n", c->name, c->stateCode);
}

#endif
