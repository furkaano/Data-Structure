#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int BOOL;

typedef struct SingleLinkedListItem{
   int data;
   struct SingleLinkedListItem* pNext;
}SLLI;

SLLI* AddItemToEnd(SLLI* pHead, int toAdd);
SLLI* Find(SLLI* pHead, int toFind);
SLLI* DeleteItem(SLLI* pHead, int toDel);
SLLI* DeleteItem_recursive(SLLI* pItem, int toDel);

void* AllocateMemory(size_t size, const char* pcszErrMsg, BOOL bExit);

void PrintList(SLLI* pHead);
void PrintList_recursive(SLLI* pHead);
void PrintListReverse_recursive(SLLI* pHead);


#endif // SINGLY_LINKED_LIST_H_INCLUDED
