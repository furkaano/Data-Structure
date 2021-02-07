#include <stdio.h>
#include "singly_linked_list.h"

int main()
{
    SLLI* pHead = NULL;
    //SLLI* pItem;

    int i;
    //int toFind;
    int toDel;

    for(i=0; i<10; ++i)
        pHead = AddItemToEnd(pHead, i+1);

    printf("Print List ITERATIVE\n");
    PrintList(pHead);
    printf("Print List RECURSIVE\n");
    PrintList_recursive(pHead);

    printf("Print List REVERSE RECURSIVE\n");
    PrintListReverse_recursive(pHead);

    /*
    toDel = 28;
    pHead = DeleteItem(pHead, toDel);
    printf("List after the deletion %d(NOT EXIST)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 1;
    pHead = DeleteItem(pHead, toDel);
    printf("List after the deletion %d(FIRST ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 10;
    pHead = DeleteItem(pHead, toDel);
    printf("List after the deletion %d(LAST ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 8;
    pHead = DeleteItem(pHead, toDel);
    printf("List after the deletion %d(MIDDLE ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 28;
    pHead = DeleteItem(NULL, toDel);
    printf("List after the deletion %d(IN AN EMPTY LIST)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");
    printf("-----------\n");
    */

    printf("------------------------\n");
    printf("***DELETING RECURSIVE***\n");
    printf("------------------------\n");
    toDel = 28;
    pHead = DeleteItem_recursive(pHead, toDel);
    printf("List after the deletion %d(NOT EXIST)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 1;
    pHead = DeleteItem_recursive(pHead, toDel);
    printf("List after the deletion %d(FIRST ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 10;
    pHead = DeleteItem_recursive(pHead, toDel);
    printf("List after the deletion %d(LAST ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 8;
    pHead = DeleteItem_recursive(pHead, toDel);
    printf("List after the deletion %d(MIDDLE ITEM)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");

    toDel = 28;
    pHead = DeleteItem_recursive(NULL, toDel);
    printf("List after the deletion %d(IN AN EMPTY LIST)\n", toDel);
    PrintList(pHead);
    printf("-----------\n");
    printf("-----------\n");
    /*
    toFind = 35;
    pItem = Find(pHead, toFind);
    if(NULL == pItem)
        printf("Item %d NOT FOUND in list\n", toFind);
    else
        printf("Item %d FOUND at address %p\n", toFind, pItem);


    toFind = 3;
    pItem = Find(pHead, toFind);
    if(NULL == pItem)
        printf("Item %d NOT FOUND in list\n", toFind);
    else
        printf("Item %d FOUND at address %p\n", toFind, pItem);

    toFind = 10;
    pItem = Find(pHead, toFind);
    if(NULL == pItem)
        printf("Item %d NOT FOUND in list\n", toFind);
    else
        printf("Item %d FOUND at address %p\n", toFind, pItem);

    toFind = 1;
    pItem = Find(pHead, toFind);
    if(NULL == pItem)
        printf("Item %d NOT FOUND in list\n", toFind);
    else
        printf("Item %d FOUND at address %p\n", toFind, pItem);

    */

    return 0;
}
