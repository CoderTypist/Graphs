/*
 * author Christian Bargraser
 *
 * PriorityQueue "inherits" from LinkedList because it can use all of the functions that
 * LinkedList can. This is because functions in LinkedList.h expect "void*"
 * instead of "LinkedList*". 
 *
 *     Ex: PriorityQueue* pq = newPriorityQueue();
 *         removeAtIndex( pq, 3 );
 *
 * Functions from PriorityQueue.h can be used with linked lists if pointers to LinkedLists
 * are casted to PriorityQueue pointers.
 *
 *     Ex: LinkedList* list = newLinkedList();
 *         priorityDequeue( (PriorityQueue*)list );
 */ 

#ifndef _PriorityQueue_h_
#define _PriorityQueue_h_

#include "LinkedList.h"

typedef struct PriorityQueue{
    
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
    int (*compareValues) (void*, void*);
}PriorityQueue;

PriorityQueue* newPriorityQueue();
bool freePriorityQueue(PriorityQueue* pq);
void printPriorityQueue(PriorityQueue* pq);
bool priorityEnqueue(PriorityQueue* pq, void* newValue);
void* priorityDequeue(PriorityQueue* pq);

PriorityQueue* newPriorityQueue(){
    
    void *list = newList();
    return (PriorityQueue*)list;
}

bool freePriorityQueue(PriorityQueue* pq){

    return freeList(pq);
}

void printPriorityQueue(PriorityQueue* pq){

    printList(pq);
}

bool priorityEnqueue(PriorityQueue* pq, void* newValue){

    return insertSorted(pq, newValue);
}

void* priorityDequeue(PriorityQueue *pq){

    return removeAtIndex(pq, 0);
}

#endif



