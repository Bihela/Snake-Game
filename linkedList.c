#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

void insertFirst(LinkedList* list, void* value)
{
    struct LinkedListNode* newNode = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

LinkedListNode* removeFirst(LinkedList* list)
{
    LinkedListNode* retVal;
    struct LinkedListNode* temp = list->head;
    list->head = list->head->next;
    retVal = temp;
    return retVal;

}

