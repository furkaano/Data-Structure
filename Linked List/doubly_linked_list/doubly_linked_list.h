#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define  TRUE   1
#define  FALSE  0

typedef int BOOL;

typedef struct DoublyLinkedListItem{
   int data;
   struct DoublyLinkedListItem* next;
   struct DoublyLinkedListItem* prev;
}DLLI;

void* AllocateMemory(size_t size, const char* pcszErrMsg, BOOL bExit);

void PrintList(DLLI* pHead);
void PrintList_Recursive(DLLI* pHead);
void PrintList_Reverse(DLLI* pHead);
void PrintList_Reverse_Recursive(DLLI* pHead);

DLLI* PrepareItem(int data);
DLLI* AddItemToEnd(DLLI* pHead, int toAdd);
DLLI* AddItemOrdered(DLLI* pHead, int toAdd);
DLLI* DeleteItem(DLLI* pHead, int toFind);

#endif // DOUBLY_LINKED_LIST_H_INCLUDED
