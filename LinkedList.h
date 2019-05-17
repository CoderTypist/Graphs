#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LESS_THAN -1
#define EQUAL 0
#define GREATER_THAN 1

typedef struct llNode{

    void *value;
    struct lNode *pNext;
}llNode;

typedef struct LinkedList{
	
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
}LinkedList;

void* newList();
LinkedList* newLinkedList();
void freeList();
void printList();

void insertValue(void *listStruct, void *newValue);
void removeValue(void *listStruct, void *valueToRemove);

void insertAtIndex(void *listStruct, void *newValue, int index);
void removeAtIndex(void *listStruct, void *valueToRemove, int index);

bool isEmpty(void *listStruct);
llNode* valueToNode(void *value);
int compareValues(void *firstValue, void *secondValue);

void* newList(){

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    if( NULL == list ){
        printf("\n\n\tError: List.h: newList(): Could not allocate memory for new List\n\n");
        exit(1);
    }
    
    // sets initial values
    list->pHead = NULL;
    list->pTail = NULL;
    list->length = 0;

    return list;
}

LinkedList* newLinkedList(){
    return NULL;
}

void freeList(){

}

void printList(void *listStruct){
    
}

void insertValue(void *listStruct, void *newValue){

}

void removeValue(void *listStruct, void *valueToRemove){

}

void insertAtIndex(void *listStruct, void *newValue, int index){

}

void removeAtIndex(void *listStruct, void *valueToRemove, int index){

}

int compareValues(void *firstValue, void *secondValue){
    return -2;
}

bool isEmpty(void* listStruct){
    return false;
}

llNode* valueToNode(void* value){

}

#endif // _LinkedList_h_

