#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;


typedef struct
{
    LinkedListNode* head;
} LinkedList;


void insertFirst(LinkedList* list, void* value);
LinkedListNode* removeFirst(LinkedList* list);

#endif