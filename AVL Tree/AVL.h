#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include "General.h"

typedef struct tagAVL{
    int data;
    struct tagAVL* left;
    struct tagAVL* right;
}AVL;

int Height(AVL* pNode);
void PrintTree(AVL* pRoot);

AVL* PrepareNode(int data);
AVL* AVL_AddNode(AVL* pRoot, int toAdd);
AVL* SingleRightRotation(AVL* pNode);
AVL* SingleLeftRotation(AVL* pNode);
AVL* DoubleLeftRightRotation(AVL* pNode);
AVL* DoubleRightLeftRotation(AVL* pNode);

#endif // AVL_H_INCLUDED
