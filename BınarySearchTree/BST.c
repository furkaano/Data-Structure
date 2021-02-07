#include "stdio.h"
#include "stdlib.h"

#include "BST.h"
#include "General.h"

BST* PrepareNode(int data)
{
    BST* pNode;

    pNode = AllocateMemory(sizeof(BST), "AddNode", EXIT_PROGRAM);
    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL;
    return pNode;
}

BST* AddNode(BST* pRoot, int toAdd)
{
    // Case 0-) Empty BST
    // Case 1-) Empty location found
    if(NULL == pRoot)
        return PrepareNode(toAdd);
    else{
        if(toAdd < pRoot->data)
            pRoot->left = AddNode(pRoot->left, toAdd);
        else
            pRoot->right = AddNode(pRoot->right, toAdd);
    }
    return pRoot;
}
void PrintTree(BST* pRoot)
{
    if(NULL == pRoot)
        return;
//    LVR
    PrintTree(pRoot->left);
    printf("Data : %d\n", pRoot->data);
    PrintTree(pRoot->right);

////    LRV
//    PrintTree(pRoot->left);
//    PrintTree(pRoot->right);
//    printf("Data : %d\n", pRoot->data);

////    RVL
//    PrintTree(pRoot->right);
//    printf("Data : %d\n", pRoot->data);
//    PrintTree(pRoot->left);

////    RLV
//    PrintTree(pRoot->right);
//    PrintTree(pRoot->left);
//    printf("Data : %d\n", pRoot->data);

////    VLR
//    printf("Data : %d\n", pRoot->data);
//    PrintTree(pRoot->left);
//    PrintTree(pRoot->right);

////    VRL
//    printf("Data : %d\n", pRoot->data);
//    PrintTree(pRoot->right);
//    PrintTree(pRoot->left);
}
void PrintLevelOrder(BST* pRoot)
{
    int h = HeightOfTree(pRoot);
    int i;
    for(i=1; i <= h; i++){
        printf("\nLEVEL %d :", i);
        PrintGivenLevel(pRoot, i);
        printf("\n");
    }
}
void PrintGivenLevel(BST* pRoot, int level)
{
    if(pRoot == NULL)
        return;
    if(level == 1)
        printf("%d\t", pRoot->data);
    else{
        PrintGivenLevel(pRoot->left, level - 1);
        PrintGivenLevel(pRoot->right, level - 1);
    }
}
int HeightOfTree(BST* pRoot)
{
    if(pRoot != NULL){
        int LeftHight = HeightOfTree(pRoot->left);
        int RightHight = HeightOfTree(pRoot->right);

        if(LeftHight > RightHight)
            return(LeftHight + 1);
        else
            return(RightHight + 1);
    }
    return 0;
}
int HeightOfTree2(BST* pRoot)
{
    if(NULL == pRoot)
        return -1;
    return (1 + MAX(HeightOfTree2(pRoot->left), HeightOfTree2(pRoot->right)));
}
int DepthOfNodeIterative(BST* pRoot, int toFind)
{
    int counter = 0;
    if(pRoot->data != toFind){
        while(pRoot->data != toFind){
            if(toFind < pRoot->data)
                pRoot = pRoot->left;
            else
                pRoot = pRoot->right;
            counter++;
        }
    }
    return counter;
}
int DepthOfNodeRecursive(BST* pRoot, int toFind)
{
   if(NULL != pRoot){
       if(pRoot->data == toFind)
          return 0;
       else if(pRoot->data < toFind && pRoot->right != NULL)
          return 1 + DepthOfNodeRecursive(pRoot->right, toFind);
       else if(pRoot->data > toFind && pRoot->left != NULL)
          return 1 + DepthOfNodeRecursive(pRoot->left, toFind);
   }
   return -1;
}
BOOL IdenticalTrees(BST* pRoot1, BST* pRoot2)
{
    //CASE 1-) Both of them EMPTY
    if(pRoot1 == NULL && pRoot2 == NULL)
        return TRUE; // IDENTICAL
    //CASE 2-) One of them empty
    else if(pRoot1 != NULL && pRoot2 == NULL)
        return FALSE;
    else if(pRoot1 == NULL && pRoot2 != NULL)
        return FALSE;
    //CASE 3-) None of them empty , So compare
    else {
        if(pRoot1->data == pRoot2->data &&
           IdenticalTrees(pRoot1->left, pRoot2->left) &&
           IdenticalTrees(pRoot1->right, pRoot2->right))
            return TRUE;
        else
            return FALSE;
    }
}
BOOL Search(BST* pRoot, int toFind)
{
    while(pRoot->data != toFind){
        if(toFind < pRoot->data)
            pRoot = pRoot->left;
        else
            pRoot = pRoot->right;
    }

    if(pRoot->data == toFind)
        return TRUE;
    else
        return FALSE;
}
BOOL SearchRecursive(BST* pRoot, int toFind)
{
      if(pRoot->data == toFind)
            return TRUE;
      else if(pRoot->data < toFind && pRoot->right != NULL)
            return SearchRecursive(pRoot->right, toFind);
      else if(pRoot->data > toFind && pRoot->left != NULL)
            return SearchRecursive(pRoot->left, toFind);
      return FALSE;
}
BST* RemoveFromTree(BST* pRoot, int toDel)
{
    BST* pIter = pRoot;

    while(pIter != NULL && toDel != pIter->data){
        if(toDel < pIter->data)
            pIter = pIter->left;
        else
            pIter = pIter->right;
    }
    // ITEM FOUND
    if(pIter != NULL){
        if(pIter->right == NULL && pIter->left == NULL){// It is a leaf
            free(pIter);
            pIter = NULL;
        }
//      HAS ONE CHILD
        else if(pIter->left == NULL){// child is right side
            BST* pTemp = pIter;
            pIter = pIter->right;
            free(pTemp);
        }
        else if(pIter->right == NULL){// child is left side
            BST* pTemp = pIter;
            pIter = pIter->left;
            free(pTemp);
        }
//      HAS TWO CHILDREN
        else{
            BST* pTemp = FindMinValueOfTreeIterative(pIter->right);
            pIter->data = pTemp->data;
            RemoveFromTree(pTemp, toDel);
        }
    }
    return pRoot;
}
BST* FindMinValueOfTreeIterative(BST* pRoot)
{
    BST* pTemp = pRoot;
    while(NULL != pTemp->left)
        pTemp = pTemp->left;
    return pTemp;
}
BST* FindMinValueOfTreeRecursive(BST* pRoot)
{
    while(pRoot->left != NULL)
        return FindMinValueOfTreeRecursive(pRoot->left);
    return pRoot;
}
BST* FindMaxValueOfTreeIterative(BST* pRoot)
{
    BST* pTemp = pRoot;
    while(NULL != pTemp->right)
        pTemp = pTemp->right;
    return pTemp;
}
BST* FindMaxValueOfTreeRecursive(BST* pRoot)
{
    while(pRoot->right != NULL)
        return FindMaxValueOfTreeRecursive(pRoot->right);
    return pRoot;
}
int NumberOfHasNoChild(BST* pRoot)
{
    if(pRoot != NULL){
        if(pRoot->left == NULL && pRoot->right == NULL)
            return 1;
        else
            return NumberOfHasNoChild(pRoot->left) + NumberOfHasNoChild(pRoot->right);
    }
    return 0;
}
int NumberOfHasOneChild(BST* pRoot)
{
    if(pRoot != NULL){
        if((pRoot->left == NULL && pRoot->right != NULL) || (pRoot->left != NULL && pRoot->right == NULL))
            return 1 + NumberOfHasOneChild(pRoot->left) + NumberOfHasOneChild(pRoot->right);
        else
            return NumberOfHasOneChild(pRoot->left) + NumberOfHasOneChild(pRoot->right);
    }
    return 0;
}
int NumberOfHasTwoChild(BST* pRoot)
{
    if(pRoot != NULL){
        if(pRoot->left != NULL && pRoot->right != NULL)
            return 1 + NumberOfHasTwoChild(pRoot->left) + NumberOfHasTwoChild(pRoot->right);
        else
            return NumberOfHasTwoChild(pRoot->left) + NumberOfHasTwoChild(pRoot->right);
    }
    return 0;
}
void BSTtoDLL(BST* pRoot, BST** pHead)
{
    if(pRoot == NULL)
        return;
    // Right Subtree
    BSTtoDLL(pRoot->right, pHead);
    // Insert Node
    pRoot->right = *pHead;

    if(*pHead != NULL)
        (*pHead)->left = pRoot;
    *pHead = pRoot;
    // Left Subtree
    BSTtoDLL(pRoot->left, pHead);
}
void PrintDLL(BST* pRoot)
{
    while(pRoot != NULL){
        printf("%d-> ", pRoot->data);
        pRoot = pRoot->right;
    }
}

