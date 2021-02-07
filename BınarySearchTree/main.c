#include <stdio.h>
#include <stdlib.h>

#include "BST.h"
#include "General.h"

#define DATA_SIZE   9

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int data2[] = {4, 6, 2, 3, 5, 5, 1, 0, 3, 7, 8};
    int i;
    int toFind;
    //int toDel;
    BST* pRoot = NULL;
    BST* pRoot2 = NULL;

    for(i=0; i < DATA_SIZE; ++i){
        pRoot = AddNode(pRoot, data[i]);
        pRoot2 = AddNode(pRoot2, data2[i]);
    }
    printf("****FIRST TREE****\n");
    PrintTree(pRoot);

    printf("****SECOND TREE****\n");
    PrintTree(pRoot2);

    printf("****FIRST TREE****\n");
    printf("---------------\n");
    printf("HEIGHT OF TREE : %d\n", HeightOfTree(pRoot));
    printf("---------------\n");
    toFind = 7;
    printf("DEPTH OF THE %d NODE IS : %d(ITERATIVE)\n", toFind, DepthOfNodeIterative(pRoot, toFind));
    printf("---------------\n");
    printf("DEPTH OF THE %d NODE IS : %d(RECURSIVE)\n", toFind, DepthOfNodeRecursive(pRoot, toFind));
    printf("---------------\n");
    printf("NUMBER OF HAS NO CHILD : %d\n", NumberOfHasNoChild(pRoot));
    printf("---------------\n");
    printf("NUMBER OF HAS ONE CHILD : %d\n", NumberOfHasOneChild(pRoot));
    printf("---------------\n");
    printf("NUMBER OF HAS TWO CHILD : %d\n", NumberOfHasTwoChild(pRoot));
    printf("---------------\n");

    printf("***********************************************\n");

    printf("****SECOND TREE****\n");
    printf("---------------\n");
    printf("HEIGHT OF TREE : %d\n", HeightOfTree(pRoot2));
    printf("---------------\n");
    toFind = 0;
    printf("DEPTH OF THE %d NODE IS : %d(ITERATIVE)\n", toFind, DepthOfNodeIterative(pRoot2, toFind));
    printf("---------------\n");
    printf("DEPTH OF THE %d NODE IS : %d(RECURSIVE)\n", toFind, DepthOfNodeRecursive(pRoot2, toFind));
    printf("---------------\n");
    printf("NUMBER OF HAS NO CHILD : %d\n", NumberOfHasNoChild(pRoot2));
    printf("---------------\n");
    printf("NUMBER OF HAS ONE CHILD : %d\n", NumberOfHasOneChild(pRoot2));
    printf("---------------\n");
    printf("NUMBER OF HAS TWO CHILD : %d\n", NumberOfHasTwoChild(pRoot2));
    printf("---------------\n");

    toFind = 8;
    printf("SEARCH ITERATIVE\n");
    if(TRUE == Search(pRoot, toFind))
        printf("%d is found on the first tree\n", toFind);
    else
        printf("%d is NOT found on the first tree !!!\n", toFind);
    printf("SEARCH RECURSIVE\n");
    if(TRUE == SearchRecursive(pRoot, toFind))
        printf("%d is found on the first tree\n", toFind);
    else
        printf("%d is NOT found on the first tree !!!\n", toFind);
    printf("---------------\n");
    printf("FIND ITERATIVE\n");
    printf("Min Value Of First Tree : %d\n", FindMinValueOfTreeIterative(pRoot)->data);
    printf("Max Value Of First Tree : %d\n", FindMaxValueOfTreeIterative(pRoot)->data);
    printf("FIND RECURSIVE\n");
    printf("Min Value Of First Tree : %d\n", FindMinValueOfTreeRecursive(pRoot)->data);
    printf("Max Value Of First Tree : %d\n", FindMaxValueOfTreeRecursive(pRoot)->data);
    printf("---------------\n");
    if(TRUE == IdenticalTrees(pRoot, pRoot2))
        printf("Both trees are identical\n");
    else
        printf("Both trees are NOT identical!!!\n");

//    toDel = 5;
//    pRoot = RemoveFromTree(pRoot, toDel);
//    printf("\nAfter deletion of %d\n", toDel);
//    PrintTree(pRoot);
//    return 0;

    printf("---------------\n");
    printf("****ROW TO ROW FIRST TREE****\n");
    PrintLevelOrder(pRoot);
    printf("---------------\n");
    printf("****ROW TO ROW SECOND TREE****\n");
    PrintLevelOrder(pRoot2);

    // This is for DLL
    // LEFT means PREV and RIGHT means NEXT
    BST* pHead = NULL;
    BSTtoDLL(pRoot2, &pHead);
    printf("\n****AFTER THE CONVERTING TO DOUBLY LINKED LIST****\n");
    PrintDLL(pHead);

    return 0;
}
