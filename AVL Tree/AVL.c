#include "AVL.h"
#include "General.h"
#include "math.h"

#define MAX(a,b)   ((a>b) ? a:b)

AVL* PrepareNode(int data)
{
    AVL* pRoot;

    pRoot = AllocateMemory(sizeof(AVL), "AddNode", EXIT_PROGRAM);
    pRoot->left = NULL;
    pRoot->right = NULL;
    pRoot->data = data;

    return pRoot;
}
int Height(AVL* pNode)
{
    if(NULL== pNode)
        return -1;
    return 1 + MAX(Height(pNode->left),Height(pNode->right));
}
void PrintTree(AVL* pRoot)
{
    if (NULL == pRoot)
        return;
    PrintTree(pRoot->right);
    printf("Data : %d\n", pRoot->data);
    PrintTree(pRoot->left);
}
AVL* AVL_AddNode(AVL* pRoot, int toAdd)
{
    // Case 0-) Empty AVL
    // Case 1-) Empty Location Found
    if(NULL == pRoot)
        return PrepareNode(toAdd);
    else {
        if (toAdd < pRoot->data)
            pRoot->left =AVL_AddNode(pRoot->left, toAdd);
        else
            pRoot->right =AVL_AddNode(pRoot->right, toAdd);
        //CHECK AVL CONDITION
        if(abs(Height(pRoot->left)-Height(pRoot->right))>1){

            //If we are here, this means AVL condition is BROKEN!
            if(toAdd>pRoot->data){
                if(toAdd> pRoot->right->data)
                    // RIGHT - RIGHT SINGLE ROTATION
                    return SingleRightRotation(pRoot);
                else
                    //RIGHT - LEFTT DOUBLE ROTATION
                    return DoubleRightLeftRotation(pRoot);
            }

            else{ //(toAdd<pRoot->data)
                if(toAdd<pRoot->left->data)
                    //LEFT - LEFT SINGLE ROTATION
                    return SingleLeftRotation(pRoot);
                else
                    //LEFT- RIGHT DOUBLE ROTATION
                    return DoubleLeftRightRotation(pRoot);

            }
        }
    }
    return pRoot;
}
AVL* SingleRightRotation(AVL* pNode)
{
    AVL* x=pNode;
    AVL* y=x->right;
//  BST* z= y->right;
//  BST* A= x->left;
    AVL* B= y->left;
//  BST* C= z->left;
//  BST* D= z->right;

    y->left=x;
    x->right= B;
    return y;
}
AVL* SingleLeftRotation(AVL* pNode)
{
    AVL* z = pNode;
    AVL* y = z->left;
//  BST* x= y->right;
//  BST* A= x->left;
//  BST* B= x->right;
    AVL* C = y->right;
//  BST* D= z->right;

    y->right = z;
    z->left = C;
    return y;
}
AVL* DoubleLeftRightRotation(AVL* pNode)
{
    AVL* z = pNode;
    AVL* x = z->left;

    z->left= SingleRightRotation(x /*pNode->left*/);
    return SingleLeftRotation(z /*pNode*/);
}
AVL* DoubleRightLeftRotation(AVL* pNode)
{
    AVL* x = pNode;
    AVL* z = x->right;
    x->right = SingleLeftRotation(z/*pNode->right*/);
    return SingleRightRotation(x/*pNode*/);
}
