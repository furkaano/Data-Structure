#include "General.h"
#include "Stack.h"

Stack* CreateStack(int capacity)
{
    Stack* pStack = AllocateMemory(sizeof(Stack), "Allocation for Stack", EXIT_PROGRAM);
    pStack->capacity = capacity;
    pStack->top = -1;
    pStack->pArr = AllocateMemory(pStack->capacity * sizeof(int), "Allocation for Array", EXIT_PROGRAM);
    return pStack;
}
void Push(Stack* pStack, int data)
{
    if(TRUE == IsFull(pStack))
        return;
    pStack->pArr[++pStack->top] = data;
    printf("%d pushed to stack\n", data);
}
int Pop(Stack* pStack)
{
    if(TRUE == IsEmpty(pStack))
        return INT_MIN;
    return pStack->pArr[pStack->top--];
}
int Peek(Stack* pStack)
{
    if (TRUE == IsEmpty(pStack))
        return INT_MIN;
    return pStack->pArr[pStack->top];
}
BOOL IsFull(Stack* pStack)
{
    if(pStack->top == pStack->capacity - 1)
        return TRUE;
    return FALSE;
}
BOOL IsEmpty(Stack* pStack)
{
    if(pStack->top == -1)
        return TRUE;
    return FALSE;
}
