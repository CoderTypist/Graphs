/*
 * author Christian Bargraser
 *
 * Stack "inherits" from LinkedList because it can use all of the functions that
 * LinkedList can. This is because functions in LinkedList.h expect "void*"
 * instead of "LinkedList*". 
 *
 *     Ex: Stack* s = newStack();
 *         removeAtIndex( s, 3 );
 *
 * Functions from Stack.h can be used with linked lists if pointers to LinkedLists
 * are casted to Stack pointers.
 *
 *     Ex: LinkedList* list = newLinkedList();
 *         push( (Stack*)list );
 */

#ifndef _Stack_h_
#define _Stack_h_

#include "LinkedList.h"

typedef struct Stack{
    
    struct llNode *pHead;
    struct llNode *pTail;
    int length;
    int (*compareValues) (void*, void*);
}Stack;

Stack* newStack();
bool freeStack(Stack* s);
void printStack(Stack* s);
bool push(Stack* s, void* newValue);
void* pop(Stack* s);

Stack* newStack(){
    
    void *list = newList();
    return (Stack*)list;
}

bool freeStack(Stack* s){

    return freeList(s);
}

void printStack(Stack* s){

    printList(s);
}

bool push(Stack* s, void* newValue){

    return insertValue(s, newValue);
}

void* pop(Stack *s){

    return removeAtIndex(s, (s->length)-1 );
}

#endif



