#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

void printSomething(void *value);

int main(){
	
    double x = 25;
    double *px = &x;
    printSomething(px);

    printf("This is the main function\n");

    return 0;
}

void printSomething(void* value){
    printf("Accepted the pointer\n");
}
