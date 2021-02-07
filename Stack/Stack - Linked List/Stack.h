#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "General.h"
typedef struct tagStack{
    int data;
    struct tagStack* pNext;
}Stack;

Stack* CreateNode(int data);

BOOL IsEmpty(Stack* pHead);

Stack* Push(Stack* pHead, int data);
Stack* Pop(Stack* pHead, int* data);
Stack* SortStack(Stack* pHead);
int Peek(Stack* pHead);
void StackReverse(Stack** pHead, Stack** pHead_pNext);

void PrintStack(Stack* pHead);


#endif // STACK_H_INCLUDED
