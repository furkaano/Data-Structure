#include "Singly_Linked_List.h"
#include "general.h"

SLLI* AddItemToEnd(SLLI* pHead, int toAdd)
{
    // Prepare a new SLLI item to store new data
    SLLI* pNewItem = AllocateMemory(sizeof(SLLI), "AddItemToEnd", TRUE);
    pNewItem->data = toAdd;
    pNewItem->pNext = NULL;

    // CASE 1-) : Empty List
    if (NULL == pHead)
        return pNewItem;
    else { // CASE 2-) : List has AT LEAST one item!
        // Find last item
        SLLI* pTemp = pHead;
        while (NULL != pTemp->pNext)
            pTemp = pTemp->pNext;
        // Add new item to the end of the list
        pTemp->pNext = pNewItem;
        // return first item's address
        return pHead;
    }
}

SLLI* AddItemToFront(SLLI* pList, int toAdd)
{
    SLLI* pNewItem = AllocateMemory(sizeof(SLLI), "AddItemToFront", TRUE);
    pNewItem->data = toAdd;
    pNewItem->pNext = pList;
    return pNewItem;
}

void PrintList(SLLI* pHead)
{
    while(NULL != pHead) {
        printf("%d ", pHead->data);
        pHead = pHead->pNext;
    }
}

void PrintList_recursive(SLLI* pHead)
{
    if (NULL == pHead)
        return;

    printf("Item data : %d\n", pHead->data);
    PrintList_recursive(pHead->pNext);
}

void PrintListReverse_recursive(SLLI* pHead)
{
    if (NULL == pHead)
        return;

    PrintListReverse_recursive(pHead->pNext);
    printf("Item data : %d\n", pHead->data);
}

SLLI* Find(SLLI* pHead, int toFind)
{
    while (NULL != pHead) {
        if (pHead->data == toFind)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

SLLI* DeleteItem(SLLI* pHead, int toDel)
{
    SLLI* cur = pHead;
    SLLI* prev = NULL;

    while (NULL != cur && toDel != cur->data) {
        prev = cur;
        cur = cur->pNext;
    }
    // Case 0-) Empty list && NOT FOUND
    if (NULL != cur) {
        // Case 1-) Remove first item
        if (NULL == prev /*cur == pHead*/)
            pHead = cur->pNext;
        else // Case 2-) Remove any other item!
            prev->pNext = cur->pNext;
        cur->pNext = NULL;
        free(cur);
    }
    return pHead;
}

SLLI* DeleteItem_recursive(SLLI* pItem, int toDel)
{
    if (NULL != pItem) {
        if (toDel != pItem->data)
            pItem->pNext = DeleteItem_recursive(pItem->pNext, toDel);
        else { // FOUND toDel
            SLLI* toReturn = pItem->pNext;
            pItem->pNext = NULL;
            free(pItem);
            return toReturn;
        }
    }
    return pItem;
}

void DestroyList(SLLI* pHead)
{
    if (NULL != pHead) {
        DestroyList(pHead->pNext);
        pHead->pNext = NULL;
        free(pHead);
    }
}
