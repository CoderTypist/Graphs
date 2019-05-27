/*
 * author Christian Bargraser
 *
 * Queue "inherits" from LinkedList because it can use all of the functions that
 * LinkedList can. This is because functions in LinkedList.h expect "void*"
 * instead of "LinkedList*". 
 *
 *     Ex: Queue* q = newQueue();
 *         removeAtIndex( q, 3 );
 *
 * Functions from Queue.h can be used with linked lists if pointers to LinkedLists
 * are casted to Queue pointers.
 *
 *     Ex: LinkedList* list = newLinkedList();
 *         dequeue( (Queue*)list );
 */

#ifndef _Queue_h_
#define _Queue_h_

#include "LinkedList.h"

typedef struct Queue{
    
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
}Queue;

Queue* newQueue();
bool freeQueue(Queue* q);
void printQueue(Queue* q);
bool enqueue(Queue* q, void* newValue);
void* dequeue(Queue* q);

Queue* newQueue(){
    
    void *list = newList();

    if( NULL == list ){
        return NULL;
    }

    return (Queue*)list;
}

bool freeQueue(Queue* q){

    return freeList(q);
}

void printQueue(Queue* q){

    printList(q);
}

bool enqueue(Queue* q, void* newValue){

    return insertValue(q, newValue);
}

void* dequeue(Queue *q){

    return removeAtIndex(q, 0);
}

#endif














