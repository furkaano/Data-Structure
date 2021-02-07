#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "AVL.h"

#define DATA_SIZE   7

int main()
{
 //   int data[] = { 4, 6, 2, 5, 1, 3, 7 };
 //   int data[] = { 2, 6 , 4};
    int i;
    AVL* pRoot = NULL;

    for (i = 0; i < DATA_SIZE; ++i)
        //for (i = 2; i >= 0 /* DATA_SIZE*/; --i)
        //pRoot = AddNode(pRoot,i+1 /*data[i]*/);
        pRoot =AVL_AddNode(pRoot,i+1 /*data[i]*/);

    PrintTree(pRoot);

    printf("Height of this tree is %d\n", Height(pRoot));
    printf("Height of a NULL tree is %d\n", Height(NULL));
    return 0;
}
