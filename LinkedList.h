/* The compareValues() and printList functions must be rewritten to accomodate 
 * for the data type being stored in the List.
 *
 * City.h is included for testing purposes.
 *
 * I leave little comments after my function protypes to inidicate the progress
 * I have made with a particular function
 *
 * // fbu
 * means, "Finished, but untested"
 *
 * // tac
 * means, "Tested and complete"
 */

#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "City.h"

#define LESS_THAN -1
#define EQUAL 0
#define GREATER_THAN 1

typedef struct llNode{

    void *value;
    struct llNode *pNext;
}llNode;

typedef struct LinkedList{
	
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
}LinkedList;

void* newList(); // tac
LinkedList* newLinkedList(); // tac
void freeList();
void printList();

bool insertValue(void *listStruct, void *newValue); // tac
bool removeValue(void *listStruct, void *valueToRemove);

bool insertAtIndex(void *listStruct, void *newValue, int index);
bool removeAtIndex(void *listStruct, void *valueToRemove, int index);
bool insertInOrder(void *listStruct, void *newValue);

bool isEmpty(void *listStruct); // tac
llNode* valueToNode(void *value); // tac
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
    
    void *list = newList();

    if( NULL == list ){
        return NULL;
    }

    return (LinkedList*)list;
}

void freeList(){

}

void printList(void *listStruct){
    
    if( NULL == listStruct ){
        printf("\n\nWarning: LinkedList.h: printList(): void *listStruct was NULL\n\n");
        return;
    }
    
    LinkedList *list = (LinkedList*)listStruct;
    llNode* curNode = list->pHead;

    while( NULL != curNode ){
        
        printCity((City*)(curNode->value));
        curNode = curNode->pNext;
    }
    
}

bool insertValue(void *listStruct, void *newValue){
    
    // if void *listStruct was NULL
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: insertValue(): void *listStruct was NULL\n\n");
        return false;
    }
    
    LinkedList *list = (LinkedList*)listStruct;
    
    // creates a neww llNode from the received value
    // valueToNode will print a message of newValue is NULL
    llNode* newNode = valueToNode(newValue);
    
    // prints a warning message if the newly created node is NULL
    if( NULL == newNode ){
        printf("\n\n\tWarning: LinkedList.h: insertValue:  Failed to insert value: llNode* newNode was NULL");
        return false;
    }
    
    // If the list is empty
    if( NULL == list->pHead ){
        list->pHead = newNode;
        list->pTail = newNode;
        return true;
    }

    // If the list is not empty
    // Append the newNode to the tail
    list->pTail->pNext = newNode;
    list->pTail = newNode;
    list->length = (list->length) + 1;
}

bool removeValue(void *listStruct, void *valueToRemove){

}

bool insertInOrder(void *listStruct, void *newValue){

}

bool insertAtIndex(void *listStruct, void *newValue, int index){

}

bool removeAtIndex(void *listStruct, void *valueToRemove, int index){

}

int compareValues(void *firstValue, void *secondValue){
    return -2;
}

bool isEmpty(void* listStruct){
    
    if( NULL == listStruct){
        return true;
    }

    else{
        
        LinkedList* list = (LinkedList*)listStruct;

        if( 0 == list->length ){
            return true;
        }

        else{
            return false;
        }
    }
}

llNode* valueToNode(void* value){
    
    // received value was NULL
    if( NULL == value ){
        printf("\n\n\tWarning: LinkedList.h: valueToNode: void* value was NULL");
        return NULL;
    }

    llNode* newNode = (llNode*)malloc(sizeof(llNode));
    
    // failed to allocate memory for new node
    if( NULL == newNode ){
        printf("\n\n\tError: LinkedList.h: valueToNode: failed to allocate memory for void* value\n\n");
        exit(1);
    }

    newNode->value = value;
    newNode->pNext = NULL;
    return newNode;
}

#endif // _LinkedList_h_
















