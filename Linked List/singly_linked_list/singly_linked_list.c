#include "singly_linked_list.h"

#define FALSE   0
#define TRUE    1

typedef int BOOL;

void* AllocateMemory(size_t size, const char* pcszErrMsg, BOOL bExit)
{
    void* pvMem;

    pvMem = malloc(size);
    if(NULL == pvMem){
        fprintf(stderr, "Cannot Allocate Memory!\n");
        fprintf(stderr, "%s\n", pcszErrMsg);
        if(TRUE == bExit)
            exit(1);
    }
    return pvMem;
}

SLLI* AddItemToEnd(SLLI* pHead, int toAdd)
{
    // prepare new SLLI item to store new data
    SLLI* pNewItem = AllocateMemory(sizeof(SLLI), "AddItemToEnd", TRUE);
    pNewItem->data = toAdd;
    pNewItem->pNext = NULL;

    // CASE 1-) Empty List
    if(NULL == pHead)
        return pNewItem;
    else{// CASE 2-) List has AT LEAST one item!
        //Find last item
        SLLI* pTemp = pHead;// iterator
        while(NULL != pTemp->pNext)
            pTemp = pTemp->pNext;
        // Add new item to the end of the list
        pTemp->pNext = pNewItem;
        // return first item's address
        return pHead;
    }
}

void PrintList(SLLI* pHead)
{
    while(NULL != pHead){
        printf("Item : %d\n", pHead->data);
        pHead = pHead->pNext;
    }
}

void PrintList_recursive(SLLI* pHead)
{
    if(NULL == pHead)
        return;
    printf("Item : %d\n", pHead->data);
    PrintList_recursive(pHead->pNext);
}

void PrintListReverse_recursive(SLLI* pHead)
{
    if(NULL == pHead)
        return;

    PrintListReverse_recursive(pHead->pNext);
    printf("Item : %d\n", pHead->data);
}

SLLI* Find(SLLI* pHead, int toFind)
{
    while(NULL == pHead){
        if(pHead->data == toFind)
             return pHead;// FOUND
        pHead = pHead->pNext;
    }
    return NULL;// NOT FOUND
}

SLLI* DeleteItem(SLLI* pHead, int toDel)
{
    SLLI* pTemp = pHead;
    SLLI* prev = NULL;

    while(NULL != pTemp && toDel != pTemp->data){
        prev = pTemp;
        pTemp = pTemp->pNext;
    }
    // CASE 1-) Empty List && NOT FOUND
    if(NULL != pTemp){
        // CASE 2-) Remove First item
        if(NULL == prev)
            pHead = pTemp->pNext;
        else // CASE 3-) Remove any other item!
            prev->pNext = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
    }
    return pHead;
}

SLLI* DeleteItem_recursive(SLLI* pItem, int toDel)
{
    if(NULL != pItem){
        if(toDel != pItem->data)
            pItem->pNext = DeleteItem_recursive(pItem->pNext, toDel);
        else{// FOUND toDel
            SLLI* toReturn = pItem->pNext;
            pItem->pNext = NULL;
            free(pItem);
            return toReturn;
        }
    }
    return pItem;
}
