#ifndef SEPARATECHAINING_SINGLY_LINKED_LIST_H
#define SEPARATECHAINING_SINGLY_LINKED_LIST_H

typedef struct SingleLinkedListItem {
    int data;
    struct SingleLinkedListItem* pNext;
}SLLI;


SLLI* AddItemToEnd(SLLI* pHead, int toAdd);
SLLI* AddItemToFront(SLLI* pList, int toAdd);
void PrintList(SLLI* pHead);
SLLI* Find(SLLI* pHead, int toFind);
SLLI* DeleteItem(SLLI* pHead, int toDel);
void DestroyList(SLLI* pHead);

void PrintList_recursive(SLLI* pHead);
void PrintListReverse_recursive(SLLI* pHead);

#endif //SEPARATECHAINING_SINGLY_LINKED_LIST_H
