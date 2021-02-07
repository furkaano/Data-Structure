#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "General.h"

#define MAX(a,b)    ((a>b)?a:b)

typedef struct tagBST{
    int data;
    struct tagBST* left;
    struct tagBST* right;
}BST;

BST* PrepareNode(int data);
BST* AddNode(BST* pRoot, int toAdd);

void PrintDLL(BST* pRoot);
void PrintTree(BST* pRoot);
void PrintLevelOrder(BST* pRoot);
void PrintGivenLevel(BST* pRoot, int level);

int HeightOfTree(BST* pRoot);
int HeightOfTree2(BST* pRoot);
int DepthOfNodeIterative(BST* pRoot, int toFind);
int DepthOfNodeRecursive(BST* pRoot, int toFind);
int IdenticalTrees(BST* pRoot1, BST* pRoot2);

int NumberOfHasNoChild(BST* pRoot);
int NumberOfHasOneChild(BST* pRoot);
int NumberOfHasTwoChild(BST* pRoot);


BOOL Search(BST* pRoot, int toFind);
BOOL SearchRecursive(BST* pRoot, int toFind);
BST* FindMinValueOfTreeIterative(BST* pRoot);
BST* FindMinValueOfTreeRecursive(BST* pRoot);
BST* FindMaxValueOfTreeIterative(BST* pRoot);
BST* FindMaxValueOfTreeRecursive(BST* pRoot);
BST* RemoveFromTree(BST* pRoot, int toDel);
void BSTtoDLL(BST* pRoot, BST** pHead);


#endif // BST_H_INCLUDED
