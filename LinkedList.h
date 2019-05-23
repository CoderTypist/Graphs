/* 
 * Functions that need to be rewritten depending on the data type in the list:
 * compareValues()
 *     - used by removeValue()
 *     - used by removeAtIndex()
 * printList()
 * freeValue()
 *     - used by removeValue()
 *     - used by removeAtIndex()
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
 *
 */

#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "City.h"

#define EQUAL 0
#define LESS_THAN 1
#define GREATER_THAN 2

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
bool freeValue(); // tac
bool freeList(void *listStruct); // tac
void printList(void *listStruct); // tac

bool insertValue(void *listStruct, void *newValue); // tac
bool removeValue(void *listStruct, void *valueToRemove); // tac

bool insertAtIndex(void *listStruct, void *newValue, int index); // tac
void* removeAtIndex(void *listStruct, int index);
bool insertSorted(void *listStruct, void *newValue);

int compareValues(void *firstValue, void *secondValue); // tac
bool isEmpty(void *listStruct); // tac
llNode* valueToNode(void *value); // tac

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

bool freeValue(void *valueToFree){
    
    if( NULL == valueToFree ){
        printf("\n\n\tWarning: LinkedList.h: freeValue(): void *valueToFree was NULL\n\n");
        return false;
    }

    City *c = (City*)valueToFree;
    free(c);
    return true;
}

bool freeList(void *listStruct){
    
    if( NULL == listStruct ){
        return false;
    }

    LinkedList *list = (LinkedList*)listStruct;

    llNode *curNode = list->pHead;
    llNode *nextNode = NULL;

    while( NULL != curNode ){
        
        nextNode = curNode->pNext;

        freeValue(curNode->value);
        free(curNode);
        curNode = nextNode;
    }
    
    free(list);

    return true;
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
        list->length = (list->length)+1;
        return true;
    }

    // If the list is not empty
    // Append the newNode to the tail
    list->pTail->pNext = newNode;
    list->pTail = newNode;
    list->length = (list->length) + 1;
    return true;
}

bool removeValue(void *listStruct, void *valueToRemove){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: removeValue(): void *listsStruct was NULL\n\n");
        return false;
    }

    if( NULL == valueToRemove ){
        printf("\n\n\tWarning: LinkedList.h: removeValue(): void *valueToRemove was NULL\n\n");
        return false;
    }

    LinkedList *list = (LinkedList*)listStruct;

    // if the list is empty
    if( list->length == 0 ){
        return false;
    }

    // if the head is the child to remove
    if( EQUAL == compareValues(valueToRemove, list->pHead->value) ){
        
        if( list->length == 1 ){
            
            freeValue(list->pHead->value);
            free(list->pHead);
            list->pHead = NULL;
            list->pTail = NULL;
        }
        
        else{
            
            llNode *hold = list->pHead;
            list->pHead = list->pHead->pNext;
            freeValue(hold->value);
            free(hold);
        }

        // decrease the length of the list
        list->length = (list->length)-1;
        return true;
    }
    
    // we already checked to see if pHead was the node to remove
    llNode *curNode = list->pHead->pNext;
    llNode *previous = list->pHead;

    int curElement = 1;
    while( NULL != curNode ){
        
        if( EQUAL == compareValues(valueToRemove, curNode->value) ){
            
            llNode *hold = curNode;
            previous->pNext = curNode->pNext;
            
            // if the tail is being removed, the tail needs to be updated
            if( EQUAL == compareValues(valueToRemove, list->pTail->value) ){
                list->pTail = previous;
            }

            freeValue(hold->value);
            free(hold);
            list->length = (list->length)-1;
            return true;
        }
        
        previous = curNode;
        curNode = curNode->pNext;
        curElement++;
    }

    return false;
}

bool insertAtIndex(void *listStruct, void *newValue, int index){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: insertAtIndex: void *listStruct was NULL\n\n");
        return false;
    }

    if( NULL == newValue ){
        printf("\n\n\tWarning: LinkedList.h: insertAtIndex: void *newValue was NULL\n\n");
        return false;
    }

    LinkedList *list = (LinkedList*)listStruct;
    
    // if inserting at the index is the same as appending to the end of the list
    if( index == list->length ){
        return insertValue(listStruct, newValue);
    }

    // if the provided index is out of bounds ( except cases where index == list->length )
    // index should not equal the length of the list
    // The only case when index should equal the length of the list is when the list is empty
    if( index < 0 || ( index >= list->length && list->length != 0 ) ){
        printf("\n\n\tWarning: LinkedList.h: insertAtIndex: index out of bounds: int index was %d: list length is %d\n\n", index, list->length);
        return false;
    }

    llNode *newNode = valueToNode(newValue);
    
    // if inserting at the beginning of the list
    if( 0 == index ){
        
        newNode->pNext = list->pHead;
        list->pHead = newNode;

        // if the received list was empty
        // This case would be caught by the if above:
        // if ( index == list->length )
        if( 0 == list->length ){
            list->pTail = newNode;
        }
        
        // increase the size of the list
        list->length = (list->length)+1;

        return true;
    }
    
    // inserting at index 0 was already considered above
    // therefore, curIndex must start at 1
    int curIndex = 1;
    llNode *previous = list->pHead;
    llNode *curNode = list->pHead->pNext;
    
    while( NULL != curNode ){
        
        if( curIndex == index ){
            
            previous->pNext = newNode;
            newNode->pNext = curNode;

            // newNode will never be appended to the end of the list
            // Therefore, no check needs to be done to see if pTail
            // should be updated. This is because insertValue() was called
            // if index == list->length, in which case pTail would need to
            // be modified
            
            list->length = (list->length)+1;
            return true;
        }
        
        previous = curNode;
        curNode = curNode->pNext;
        curIndex++;
    }
    
    printf("\n\n\tWarning: LinkedList.h: insertAtIndex(): Unexpectedly reached end of function\n\n");

    return false;

}

void* removeAtIndex(void *listStruct, int index){
    
    return false;
}

bool insertSorted(void *listStruct, void *newValue){
    
    return false;
}

// returns LESS_THAN, EQUALS, GREATER_THAN, or ERROR
int compareValues(void *firstValue, void *secondValue){
    
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
















