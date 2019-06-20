# Graphs

I wanted to implement Prim's algorithm, but realized that I would first need code for graphs, linked lists, and priority queues. I began by making code for a linked list. 


AVOIDING NEEDING TO HAVE IDENTICAL VERSIONS OF A FUNCTION FOR DIFFERENT DATA STRUCTURES


I realized that a lot of the functions that I would write for linked lists could be used by queues. I could copy paste the code and change every reference of "LinkedList" to "Queue". However, this present an issue. I would need to have two different versions of the same function. One for linked lists and one for queues. For example, I would need to have a "printLinkedList()" and a "printQueue()". I saw this as unecessary since they both do the same thing: traverse through a list structure and print each value. I asked myself if there was a way to avoid having two versions of the same function. 


IMPLEMENTING THE USE OF VOID POINTERS TO CREATE FUNCTIONS THAT CAN BE USED BY DIFFERENT DATA STRUCTURES


Had I been coding in Java, I could have made it to where Queue extended LinkedList, but that wasn't an option since I was using C. The solution was to use void pointers. I would make a printList() function that received a void pointer. Since the linked list structure was the same as the queue structure, I could simply receive a void pointer and then cast the pointer to a LinkedList. Even if the void pointer was pointing to a queue, no problems would arise since they have the same attributes. By using void pointers, it is possible to emulate inheritance.


BEING ABLE TO STORE ANY DATA TYPE WITH MINIMUM MODIFICATION REQUIRED


I wanted to make my linked list versatile, so instead of storing a specific data type, I made it store void pointers. However, certain functions still need to be rewritten depending on the data type being used. Those functions are the printList(), freeValue(), and compareValues(). removeValue() and insertSorted() both need to compare elements in the list. Instead of modifying those two functions everytime a new data type is being stored, all a person needs to do is change the compareValues() function.


CONVERTING LINKED LISTS TO ARRAYS


One of the pro's to using linked lists is that a value can be easily be removed once found. Another pro is that new values can simply be attached to the end of the list. This can be helpful when the nuber of elements to be added is unknown. This can become a hassle when using arrays since you wouldn't know how much memory to allocate before hand. However, linked lists also have their con's. Finding elements in a linked list can be costly since a linear search has to be used. However, when arrays are used, binary searches can be used. That is why I made functions that can turn linked lists to arrays. These functions allow us to reap the benefits of both linked lists and arrays. Let's say you were going to make a program that was going to have sorted data and was going to do a lot of searching. You could load your data into a linked list using the insertSorted() function and then convert the linked list to an array.
