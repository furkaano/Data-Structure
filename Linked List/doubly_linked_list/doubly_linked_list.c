#include "doubly_linked_list.h"

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

DLLI* PrepareItem(int data)
{
    DLLI* newItem;
    newItem = AllocateMemory(sizeof(DLLI), "PrepareItem", TRUE);
    newItem->prev = NULL;
    newItem->data = data;
    newItem->next = NULL;

    return newItem;
}

DLLI* AddItemToEnd(DLLI* pHead, int toAdd)
{
    //Convert simple data to DLLI item!
    DLLI* pItem = PrepareItem(toAdd);
    if(NULL == pHead)// Empty List
        return pItem;
    else{//List has AT LEAST one item!
        DLLI* pTemp = pHead;
    while(NULL != pTemp->next)
        pTemp= pTemp->next;
    pTemp->next = pItem;
    pItem->prev = pTemp;
    return pHead;
    }
}
DLLI* AddItemOrdered(DLLI* pHead, int toAdd)
{
    DLLI* pItem= PrepareItem(toAdd);
    if(NULL == pHead)
        return pItem;
    if(pHead->data > toAdd){
        pItem->next = pHead;
        pHead->prev = pItem;
        return pItem;
    }
    DLLI* pTemp = pHead;
    while(NULL != pTemp->next && pTemp->next->data < toAdd)
        pTemp = pTemp->next;

    pItem->next = pTemp->next;
    pTemp->next = pItem;
    pItem->prev = pTemp;
        if(NULL != pItem->next)
            pItem->next->prev = pItem;
    return pHead;
}

DLLI* DeleteItem(DLLI* pHead, int toFind)
{
    DLLI* pTemp = pHead;

    while(NULL != pTemp && toFind != pTemp->data)
        pTemp = pTemp->next;
    // ITEM FOUND
    if(NULL != pTemp){
        // Set Links
        DLLI* nextItem = pTemp->next;
        DLLI* prevItem = pTemp->prev;
        if(nextItem)
            nextItem->prev = prevItem;
        if(prevItem)
            prevItem->next = nextItem;
        // First item will be removed
        if(pTemp == pHead)
            pHead = nextItem;
        //Delete item
        pTemp->next = NULL;
        pTemp->prev = NULL;
        free(pTemp);
    }
    return pHead;
}
void PrintList(DLLI* pHead)
{
    while(NULL != pHead){
        printf("Item : %d\n", pHead->data);
        pHead = pHead->next;
    }
}
void PrintList_Recursive(DLLI* pHead)
{
    if(NULL == pHead)
        return NULL;
          printf("Item : %d\n", pHead->data);
          PrintList_Recursive(pHead->next);
}

void PrintList_Reverse(DLLI* pHead)
{
    DLLI* pTemp = pHead;
    while(NULL != pTemp->next){
        pTemp = pTemp->next;
    }
    while(NULL != pTemp){
        printf("Item : %d\n", pTemp->data);
        pTemp = pTemp->prev;
    }
}
void PrintList_Reverse_Recursive(DLLI* pHead)
{
    if(NULL == pHead)
       return NULL;

    PrintList_Reverse_Recursive(pHead->next);
    printf("Item : %d\n", pHead->data);
}

