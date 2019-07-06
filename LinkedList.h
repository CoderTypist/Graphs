/*
 * author Christian Bargraser
 * 
 * Functions that need to be rewritten depending on the data type in the list:
 *
 * printValue()
 *     - used by printList()
 *     - used by printArray()
 * freeValue()
 *     - used by removeValue()
 *     - used by removeAtIndex()
 * cloneValue()
 *     - used by listToIndependentArray()
 *
 * // The LinkedList struct has a function pointer as an attribute
 * // The function passed in will be used by other functions
 * compareValues()
 *     - used by removeValue()
 *     - used by removeAtIndex()
 *     - used by insertSorted()
 * 
 * City.h is included for testing purposes.
 *
 */

#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "City.h"
#include "Comparisons.h"

// used by LinkedList->compareValues(), sortedContainsValues(), and binarySearch()
// #define EQUAL 0
// #define LESS_THAN 1
// #define GREATER_THAN 2

typedef struct llNode{

    void *value;
    struct llNode *pNext;
}llNode;

typedef struct LinkedList{
	
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
    int (*compareValues) (void*, void*);
}LinkedList;

// value functions
void* cloneValue(void *originalValue);
bool freeValue();
void printValue(void *value);
int compareAddresses(void *firstValue, void *secondValue);
llNode* valueToNode(void *value);

// list functions
void* newList();
void* cloneList(void *listStruct);
LinkedList* newLinkedList();
void filterList(void *listStruct, bool (*keep) (void*));
LinkedList* filteredCopy(void *listStruct, bool (*keep) (void*));
bool reverseList();
bool freeList(void *listStruct);
void printList(void *listStruct);
bool insertValue(void *listStruct, void *newValue);
bool removeValue(void *listStruct, void *valueToRemove);
bool insertAtIndex(void *listStruct, void *newValue, int index);
void* removeAtIndex(void *listStruct, int index);
bool insertSorted(void *listStruct, void *newValue);
bool isEmpty(void *listStruct);
void* containsValue(void *listStruct, void *lookingFor);        
void* sortedContainsValue(void *listStruct, void *lookingFor);

// array functions
void* listToDependentArray(void *listStruct);
void* listToIndpendentArray(void *listStruct);
bool freeDependentArray(void **arr);
bool freeIndependentArray(void **arr);
void* binarySearch(void **arr, int arrLength, void *lookingFor, int (*compareValues) (void*, void*) );
void printArray(void **arr);
int arrayLength(void **arr);

void* cloneValue(void *originalValue){
    
    if( NULL == originalValue ){
        printf("\n\n\tWarning: LinkedList.h: cloneValue(): void *originalValue was NULL\n\n");
        return NULL;
    }

    City *clone = newCity( ((City*)originalValue)->name, ((City*)originalValue)->stateCode);
    
    if( NULL == clone ){
        printf("\n\n\tWarning: LinkedList.h: cloneValue(): failed to create clone of originalValue\n\n");
        return NULL;
    }

    return clone;
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

void printValue(void *value){
    printCity((City*)(value));
}

// This is the default function used to compare values
// It is assigned to a LinkedLists.h compareValues attribute (which is a function pointer)
int compareAddresses(void *firstValue, void *secondValue){
    
    if( NULL == firstValue ){
        printf("\n\n\tWarning: LinkedList.h: compareAddresses(): void *firstValue was NULL");
        printf("\n\t\tcompareAddresses() is the default function used for comparisons\n\n");
        return -1;
    }

    if( NULL == secondValue ){
        printf("\n\n\tWarning: LinkedList.h: compareAddresses(): void *secondValue was NULL");
        printf("\n\t\tcompareAddresses() is the default function used for comparisons\n\n");
        return -1;
    }

    if( firstValue < secondValue ){
        return LESS_THAN;
    }

    else if( firstValue > secondValue ){
        return GREATER_THAN;
    }

    return EQUAL;
}

llNode* valueToNode(void* value){
    
    // received value was NULL
    if( NULL == value ){
        printf("\n\n\tWarning: LinkedList.h: valueToNode(): void* value was NULL\n\n");
        return NULL;
    }

    llNode* newNode = (llNode*)malloc(sizeof(llNode));
    
    // failed to allocate memory for new node
    if( NULL == newNode ){
        printf("\n\n\tError: LinkedList.h: valueToNode(): failed to allocate memory for llNode* newNode\n\n");
        exit(1);
    }

    newNode->value = value;
    newNode->pNext = NULL;
    return newNode;
}

void* newList(){

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    if( NULL == list ){
        printf("\n\n\tError: LinkedList.h: newList(): Could not allocate memory for new List\n\n");
        exit(1);
    }
    
    // sets initial values
    list->pHead = NULL;
    list->pTail = NULL;
    list->length = 0;
    list->compareValues = compareAddresses;

    return list;
}

void* cloneList(void *listStruct){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: cloneList(): void *listStruct was NULL\n\n");
    }

    LinkedList *receivedList = listStruct;
    llNode *curNode = receivedList->pHead;
    LinkedList *cloned = newLinkedList();

    while( NULL != curNode ){
        
        insertValue(cloned, cloneValue(curNode->value) );
        curNode = curNode->pNext;
    }

    return cloned;
}

LinkedList* newLinkedList(){
    
    void *list = newList();

    if( NULL == list ){
        return NULL;
    }

    return (LinkedList*)list;
}

void filterList(void *listStruct, bool (*keep) (void*)){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: filterList(): void *listStruct was NULL\n\n");
        return;
    }
    
    if( NULL == keep ){
        printf("\n\n\tWarning: LinkedList.h: filterList(): bool (*keep) (void*)) was NULL\n\n");
        return;
    }

    LinkedList *list = (LinkedList*)listStruct;

    // if the list is empty
    if( list->length == 0 ){
        return;
    }
    
    bool removedHead = true;

    // checks pHead
    while( true == removedHead ){
        
        // if pHead needs to be removed
        if( false == keep(list->pHead->value) ){
	
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
        }
        
        // if pHead was not removed
        else{

            // if the list was completely emptied
            if( NULL == list->pHead ){
                return;
            }

            removedHead = false;
        }
    }
    
    llNode *curNode = list->pHead->pNext;
    llNode *previous = list->pHead;

    int curElement = 2;
    while( NULL != curNode ){
        
        if( false == keep(curNode->value) ){
            
            llNode *hold = curNode;
            previous->pNext = curNode->pNext;
            
            // if the tail is being removed, the tail needs to be updated
            if( curElement == list->length ){
                list->pTail = previous;
            }

            freeValue(hold->value);
            free(hold);
            list->length = (list->length)-1;
        }
        
        previous = curNode;
        curNode = curNode->pNext;
        curElement++;
    }
}

LinkedList* filteredCopy(void *listStruct, bool (*keep) (void*) ){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: filteredCopy(): void *listStruct is NULL\n\n");
        return NULL;
    }

    if( NULL == keep ){
        printf("\n\n\tWarning: LinkedList.h: filteredCopy(): void *listStruct is NULL\n\n");
        return NULL;
    }

    LinkedList *copy = cloneList(listStruct);
    filterList(copy, keep);

    return copy;
}

bool reverseList(void *listStruct){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: reverseList(): void *listStruct is NULL\n\n");
        return false;
    }
    
    LinkedList *receivedList = listStruct;
    int length = receivedList->length;
    
    if( 1 == length || 0 == length ){
        return true;
    }
    
    void **arr = listToDependentArray(listStruct);
    llNode *curNode = receivedList->pHead;
    int i;

    for( i = 0; i < length; i++ ){
        
        curNode->value = arr[length-(i+1)];
        curNode = curNode->pNext;
    }
    
    freeDependentArray(arr);
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
        
        printValue(curNode->value);
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
        printf("\n\n\tWarning: LinkedList.h: removeValue(): void *listStruct was NULL\n\n");
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
    if( EQUAL == list->compareValues(valueToRemove, list->pHead->value) ){
        
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

    int curElement = 2;
    while( NULL != curNode ){
        
        if( EQUAL == list->compareValues(valueToRemove, curNode->value) ){
            
            llNode *hold = curNode;
            previous->pNext = curNode->pNext;
            
            // if the tail is being removed, the tail needs to be updated
            if( curElement == list->length ){
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
    
    printf("\n\n\tWarning: LinkedList.h: insertAtIndex(): Unexpectedly reached end of function: index == %d\n\n", index);

    return false;

}

void* removeAtIndex(void *listStruct, int index){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: removeAtIndex: void *listStruct was NULL\n\n");
        return NULL;
    }

    LinkedList *list = (LinkedList*)listStruct;
    int listLength = list->length;

    // out of bounds
    // handles case: 0 == listLength
    if( index < 0 || index >= listLength ){
        printf("\n\n\tWarning: LinkedList.h: removeAtIndex: index out of bounds: int index was %d: list length is %d\n\n", index, list->length);
        return NULL;
    }
    
    void *removedValue = NULL;

    // if removing the first element
    if( index == 0 ){
        
        removedValue = list->pHead->value;

        // if the list only has one element
        if( listLength == 1 ){
            
            // the llNode is freed, but the value is not
            free(list->pHead);
            list->pHead = NULL;
            list->pTail = NULL;
            list->length = 0;
            return removedValue;
        }

        // if the list has more than one element and the index is 0
        else{
            
            llNode *hold = list->pHead;
            list->pHead = list->pHead->pNext;
            free(hold);
            list->length = listLength-1;
            return removedValue;
        }
    }

    // if the list has more than one element and index is not 0
    else{
        
        // previous can be list->pHead because the above code3 checks for when index == 0
        llNode *previous = list->pHead;
        llNode *curNode = list->pHead->pNext;
        int curIndex = 1;

        while( curNode != NULL ){
            
            // index to be removed is reached
            if( curIndex == index ){
                
                previous->pNext = curNode->pNext;
                removedValue = curNode->value;
                free(curNode);
                break;
                // removedValue is returned below
            }

            curIndex++;
            previous = curNode;
            curNode = curNode->pNext;
        }

        // if the last element is being removed
        if( index == (listLength-1) ){
            
            // at this point, previous should be the node before the last node
            list->pTail = previous;
        }
        
        list->length = listLength-1;
        return removedValue;
    }
    
    // out of bounds was checked and empty list was checked
    // if the code reaches this point, there was an error removing the node
    printf("\n\n\tWarning: LinkedList.h: removeAtIndex(): Unexpectedly reached end of function: index == %d\n\n", index);

    return NULL;
}

bool insertSorted(void *listStruct, void *newValue){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: insertSorted(): void *listStruct was NULL\n\n");
        return false;
    }

    if( NULL == newValue ){
        printf("\n\n\tWarning: LinkedList.h: insertSorted(): void *newValue was NULL\n\n");
        return false;
    }

    LinkedList *list = (LinkedList*)listStruct;
    int listLength = list->length;
    llNode *newNode = valueToNode(newValue);

    // failed to create newNode
    if( NULL == newNode ){
        printf("\n\n\tWarning: LinkedList.h: insertSorted(): void *newNode was NULL\n\n");
        return false;
    }

    // if the list is empty
    if( 0 == listLength ){
        
        list->pHead = newNode;
        list->pTail = newNode;
        list->length = listLength+1;
        return true;
    }

    // if inserting at the beginning of the list
    if( LESS_THAN == list->compareValues(newValue, list->pHead->value) ){
        
        newNode->pNext = list->pHead;
        list->pHead = newNode;
        list->length = listLength+1;
        return true;
    }

    // the above if already handled inserting at the beginning of the list
    llNode *previous = list->pHead;
    llNode *curNode = list->pHead->pNext;
    int curIndex = 1;

    while( NULL != curNode ){
        
        // inserts newNode
        if( LESS_THAN == list->compareValues(newValue, curNode->value) ){
            
            previous->pNext = newNode;
            newNode->pNext = curNode;
            list->length = listLength+1;
            return true;
        }

        previous = curNode;
        curNode = curNode->pNext;
        curIndex++;
    }

    // if this point has been reached, it means that all values
    // in the list were less than newValue
    if( curIndex == listLength ){
        list->pTail->pNext = newNode;
        list->pTail = newNode;
        list->length = listLength+1;
        return true;
    }
    
    printf("\n\n\tWarning: LinkedList.h: insertSorted(): Unexpectedly reached end of function\n\n");
    return false;
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

/* 
 * This function will use a linear search
 * You would use this if you are using unsorted data or only needed to do one search
 *
 * If you plan on doing a lot of searching, it would be better to:
 *     1) Create a sorted list using the insertSorted() function
 *     2) Turn the list to an array using the listToDependentArray() 
 *        or listToIndependentArray() functions
 *     3) Use the binarySearch() function
 */
void* containsValue(void *listStruct, void *lookingFor){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: containsValue(): void *listStruct is NULL\n\n");
        return NULL;
    }
    
    if( NULL == lookingFor ){
        printf("\n\n\tWarning: LinkedList.h: containsValue(): void *lookingFor is NULL\n\n");
        return NULL;
    }

    LinkedList *receivedList = listStruct;
    llNode *curNode = receivedList->pHead;
    
    while( NULL != curNode ){
        
        if( EQUAL == receivedList->compareValues(curNode->value, lookingFor) ){
            return curNode->value;
        }

        curNode = curNode->pNext;
    }

    return NULL;
}

/*
 * The containsValue() function will check every node in the list.
 * This can be inefficient if the list being checked is sorted.
 * The sortedContainsValue() function will return once a value greater than
 * the one being looking for is found.
 */
void* sortedContainsValue(void *listStruct, void *lookingFor){

    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: sortedContainsValue(): void *listStruct is NULL\n\n");
    }

    if( NULL == lookingFor ){
        printf("\n\n\tWarning: LinkedList.h: sortedContainsValue(): void *lookingFor is NULL\n\n");
    }

    LinkedList *receivedList = listStruct;
    llNode *curNode = receivedList->pHead;
    int comparisonResult;

    while( NULL != curNode ){
        
        comparisonResult = receivedList->compareValues(curNode->value, lookingFor);
        
        // Return the value if it is found
        if( EQUAL == comparisonResult ){
            return curNode->value;
        }
        
        // All of the remaining values in the list should be greater than void *lookingFor
        else if( GREATER_THAN == comparisonResult ){
            return NULL;
        }

        // loop continues to iterate if comparisonResult == LESS_THAN
    
        curNode = curNode->pNext;
    }

    return NULL;
}

/*
 * WHAT IS MEANT BY "DEPENDENT ARRAY"?
 * The returned array will be dependent upon the the received list structure because the array will point
 * to the same values that the list points to. Modifying a value in the returned array will modify the
 * the value held by the list structure. 
 *
 * WHY WOULD I WANT A "DEPENDENT ARRAY"?
 * The purpose of creating an array that points to the same values as the LinkedList is to be able to use
 * a binary search. Data of unknown length can quickly be loaded into an LinkedList. If it is necessary to 
 * search through the data, the LinkedList can then be converted to an array by using this function.
 *
 * WHAT ARE THE LIMITATIONS OF THIS FUNCTION?
 * If you remove a node from the LinkedList, the change will not be applied to the array version of the list.
 * If a node is removed or added to the LinkedList, this function will have to be called again in order to
 * get an updated array.
 *
 * If the received list is of size 0, NULL is returned
 * Otherwise, a pointer (array) is returned
 */
void* listToDependentArray(void *listStruct){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: listToDependentArray(): void *listStruct was NULL\n\n");
        return NULL;
    }

    LinkedList *receivedList = listStruct;
    
    // received list was empty, NULL is returned
    if( 0 == receivedList->length ){
        return NULL;
    }
    
    int arrLength = receivedList->length;
    void **arr = (void**)malloc( (arrLength+1)*sizeof(void*) ); // 1 is added to make the last element NULL

    if( NULL == arr ){
        printf("\n\n\tError: LinkedList.h: listToDependentArray(): Could not allocate memory for void *arr\n\n");
        exit(1);
    }
    
    // copies the pointers from the LinkedList to the array
    llNode *curNode = receivedList->pHead;
    int i;
    for( i = 0; i < arrLength; i++ ){
        
        arr[i] = curNode->value;
        curNode = curNode->pNext;
    }
    arr[i] = NULL;

    return arr;
}

/* 
 * WHAT IS MEANT BY "INDEPENDENT ARRAY"?
 * The returned array will be indpendent of the received list structure because all of the value in the list
 * will be cloned/recreated and added to the array. Modifying a value in the array will not have any affect
 * on the values in the list. 
 *
 * If the received list is of size 0, NULL is returned
 * Otherwise, a pointer (array) is returned
 */
void* listToIndependentArray(void *listStruct){
    
    if( NULL == listStruct ){
        printf("\n\n\tWarning: LinkedList.h: listToIndependentArray(): void *listStruct was NULL\n\n");
        return NULL;
    }

    LinkedList *receivedList = listStruct;
    
    // received list was empty, NULL is returned
    if( 0 == receivedList->length ){
        return NULL;
    }
    
    int arrLength = receivedList->length;
    void **arr = (void**)malloc( (arrLength+1)*sizeof(void*) ); // 1 is added to make the last element NULL

    if( NULL == arr ){
        printf("\n\n\tError: LinkedList.h: listToIndependentArray(): Could not allocate memory for void *arr\n\n");
        exit(1);
    }
    
    // copies the pointers from the LinkedList to the array
    llNode *curNode = receivedList->pHead;
    int i;
    for( i = 0; i < arrLength; i++ ){
        
        arr[i] = cloneValue(curNode->value);
        curNode = curNode->pNext;
    }
    arr[i] = NULL;

    return arr;
}

bool freeDependentArray(void **arr){
    
    if( NULL == arr ){
        return false;
    }

    free(arr);
    return true;
}

bool freeIndependentArray(void **arr){
    
    if( NULL == arr ){
        return false;
    }

    void **startAddress = arr;
    void *curValue = arr[0];

    while( NULL != curValue ){
        freeValue(curValue);
        arr[0] = NULL;
        arr++;
        curValue = arr[0];
    }
    
    free(startAddress);

    return true;
}

/* 
 * ARRAY WAS CREATED FROM A LINKED LIST
 * If the array was created from a linked list using the listToDependentArray() or
 * listToIndendentArray() functions, the length of the array can be retrieved from the lists
 * length attribute. 
 *
 *     Ex: void *valueIWant = binarySearch(arr, listStructure->length, valueIAmLookingFor, myFunctionToCompareValues);
 *
 * LENGTH OF THE ARRAY IS UNKNOWN
 * If the length of the array is unknown or the length of the array is no longer in sync with 
 * the original list structure, you would need to call arrayLength()
 *
 *     Ex: void *valueIWant = binarySearch(arr, arrLength(arr), valueIAmLookingFor, myFunctionToCompareValues);
 */
void* binarySearch(void **arr, int arrLength, void *lookingFor, int (*compareValues) (void*, void*) ){
    
    if( NULL == arr ){
        printf("\n\n\tWarning: LinkedList.h: binarySearch(): void *listStruct was NULL\n\n");
        return NULL;
    }

    if( NULL == lookingFor ){
        printf("\n\n\tWarning: LinkedList.h: binarySearch(): void *lookingFor was NULL\n\n");
        return NULL;
    }
    
    if( NULL == arr[0] ){
        printf("\n\n\tWarning: LinkedList.h: binarySearch(): empty array: arr[0] is NULL\n\n");
        return NULL;
    }
    
    if( arrLength <= 0 ){
        printf("\n\n\tWarning: LinkedList.h: binarySearch(): parameter int arrLength is %d\n\n", arrLength);
        return NULL;
    }

    int left = 0;
    int right = arrLength-1;
    int middle = (left+right)/2;
    int comparisonResult;

    while( left <= right ){
        
        // printf("Comparing...\n");
        // printValue(arr[middle]);
        // printValue(lookingFor);
        // printf("\n");

        comparisonResult = compareValues( arr[middle], lookingFor);
        
        if( EQUAL == comparisonResult ){
            return arr[middle];
        }

        else if( LESS_THAN == comparisonResult ){
            left = middle+1;
        }

        else if( GREATER_THAN == comparisonResult ){
            right = middle-1;
        }
        
        else{
            printf("\n\n\tError: LinkedList.h: binarySearch(): local variable int comparisonResult is %d", comparisonResult);
            printf("\n\t\tcomparisonResult should be EQUAL (0), LESS_THAN (1), or GREATER_THAN (2)");
            printf("\n\t\tThis means that the compareValues() function was written incorrectly\n\n");
            return NULL;
        }

        middle = (left+right)/2;
    }

    // returns NULL if the void *lookingFor was not found
    return NULL;
}

void printArray(void **arr){
    
    if( NULL == arr ){
        printf("\n\n\tWarning: LinkedList.h: printArray(): void **arr was NULL\n\n");
    }

    void *curValue = arr[0];

    while( NULL != curValue ){
        printValue(curValue);
        arr++;
        curValue = arr[0];
    }
}

int arrayLength(void **arr){
    
    if( NULL == arr ){
        printf("\n\n\tWarning: LinkedList.h: arrayLength(): void **arr was NULL\n\n");
        return 0;
    }
    
    int numElements = 0;
    void *curValue = arr[0];

    while( NULL != curValue ){
        numElements++;
        arr++;
        curValue = arr[0];
    }

    return numElements;
}

#endif // _LinkedList_h_





