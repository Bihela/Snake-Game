#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

typedef struct DoubleLinkedListNode
{
	void* data;
	struct DoubleLinkedListNode* next;
	struct DoubleLinkedListNode* previous;
} DoubleLinkedListNode;


typedef struct
{
    DoubleLinkedListNode* head;
    DoubleLinkedListNode* tail;
} DoubleLinkedList;


void insertFirst(DoubleLinkedList* list, void* value);
DoubleLinkedListNode* removeFirst(DoubleLinkedList* list);
void testdll();
#endif