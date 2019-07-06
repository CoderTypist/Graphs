# Graphs


AVOIDING NEEDING TO HAVE IDENTICAL VERSIONS OF A FUNCTION FOR DIFFERENT DATA STRUCTURES


I realized that a lot of the functions that I would write for linked lists could be used by queues. I could copy paste the code and change every reference of "LinkedList" to "Queue". However, this presented an issue. I would need to have two different versions of the same function. One for linked lists and one for queues. For example, I would need to have a "printLinkedList()" and a "printQueue()". I saw this as unecessary since they both do the same thing: traverse through a list structure and print each value. I asked myself if there was a way to avoid having two versions of the same function. 


IMPLEMENTING THE USE OF VOID POINTERS TO CREATE FUNCTIONS THAT CAN BE USED BY DIFFERENT DATA STRUCTURES


Had I been coding in Java, I could have made it to where Queue extended LinkedList, but that wasn't an option since I was using C. The solution was to use void pointers. I would make a printList() function that received a void pointer. Since the linked list structure was the same as the queue structure, I could simply receive a void pointer and then cast the pointer to a LinkedList. Even if the void pointer was pointing to a queue, no problems would arise since they have the same attributes.


BEING ABLE TO STORE ANY DATA TYPE WITH MINIMUM MODIFICATION REQUIRED


I wanted to make my linked list versatile, so instead of storing a specific data type, I made it store void pointers. However, certain functions still need to be rewritten depending on the data type being used. Those functions are printValue(), freeValue(), and cloneValue().


FUNCTION POINTERS


Originally, I had a function called compareValues() that had to be rewritten based on the data type being stored in the list. Functions such as insertSorted() would make calls to compareValues(). However, I realized that since function overloading is not supported in C, that I could only have one compareValues() function. This meant that a program could only have a LinkedList of one type. If you made a LinkedList of ints, you could not have a LinkedList of Strings. This was because you could not have a compareValues() for ints and another compareValues() for Strings. To get around this issue, I made all linked lists have a function pointer as an attribute. That function would be used to compare values. By default, all linked lists will compare addresses until a new function is given to the linked list. 


CONVERTING LINKED LISTS TO ARRAYS


One of the pro's to using linked lists is that a value can be easily be removed once found. Another pro is that new values can simply be attached to the end of the list. This can be helpful when the nuber of elements to be added is unknown. This can become a hassle when using arrays since you wouldn't know how much memory to allocate before hand. However, linked lists also have their con's. Finding elements in a linked list can be costly since a linear search has to be used. However, when arrays are used, binary searches can be used. That is why I made functions that can turn linked lists to arrays. These functions allow us to reap the benefits of both linked lists and arrays. Let's say you were going to make a program that was going to have sorted data and was going to do a lot of searching. You could load your data into a linked list using the insertSorted() function and then convert the linked list to an array. This would let you use a binary search. 
