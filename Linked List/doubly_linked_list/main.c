#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

#define MAX   10

int main()
{
    DLLI* pHead = NULL;
    //int i;
    int toFind;

    pHead = AddItemOrdered(pHead, 400);
    pHead = AddItemOrdered(pHead, 40);
    pHead = AddItemOrdered(pHead, 4);
    pHead = AddItemOrdered(pHead, 450);
    pHead = AddItemOrdered(pHead, 50);

    printf("PRINT ITERATIVE\n");
    PrintList(pHead);
    printf("-------------\n");
    printf("PRINT RECURSIVE\n");
    PrintList_Recursive(pHead);
    printf("-------------\n");
    printf("PRINT REVERSE\n");
    PrintList_Reverse(pHead);
    printf("-------------\n");
    printf("PRINT REVERSE RECURSIVE\n");
    PrintList_Reverse_Recursive(pHead);

    toFind = 4;
    pHead = DeleteItem(pHead, toFind);
    printf("After deletion of %d\n", toFind);
    PrintList(pHead);
    printf("---------\n");

    toFind = 450;
    pHead = DeleteItem(pHead, toFind);
    printf("After deletion of %d\n", toFind);
    PrintList(pHead);
    printf("---------\n");

    toFind = 50;
    pHead = DeleteItem(pHead, toFind);
    printf("After deletion of %d\n", toFind);
    PrintList(pHead);
    printf("---------\n");

    toFind = 10;
    pHead = DeleteItem(pHead, toFind);
    printf("After deletion of %d\n", toFind);
    PrintList(pHead);
    printf("---------\n");

    toFind = 111;
    pHead = DeleteItem(NULL, toFind);
    printf("After deletion of %d\n", toFind);
    PrintList(pHead);
    printf("---------\n");

    return 0;
}
