#include "Stack.h"
#include "General.h"

Stack* CreateNode(int data)
{
    Stack* pTemp = AllocateMemory(sizeof(Stack), "Allocation for stack", EXIT_PROGRAM);
    pTemp->data = data;
    pTemp->pNext = NULL;
    return pTemp;
}
Stack* Push(Stack* pHead, int data)
{
    Stack* pTemp = CreateNode(data);
    pTemp->pNext = pHead;
    pHead = pTemp;
    return pHead;
}
Stack* Pop(Stack* pHead, int* data)
{
    Stack* pTemp = pHead;
    *data = pHead->data;
    pHead = pHead->pNext;
    free(pTemp);
    return pHead;
}
int Peek(Stack* pHead)
{
    if(TRUE == IsEmpty(pHead))
        return INT_MIN;
    return pHead->data;
}
void StackReverse(Stack** pHead, Stack** pHead_pNext)
{
    Stack* pTemp;
    if(*pHead_pNext != NULL){
        pTemp = (*pHead_pNext)->pNext;
        (*pHead_pNext)->pNext = *pHead;
        *pHead = *pHead_pNext;
        *pHead_pNext = pTemp;
        StackReverse(pHead, pHead_pNext);
    }
}
BOOL IsEmpty(Stack* pHead)
{
    if(TRUE == IsEmpty(pHead))
        return TRUE;
    return FALSE;
}
void PrintStack(Stack* pHead)
{
    Stack* Current;
    Current = pHead;
    if(Current != NULL)
    {
        printf("Stack: ");
        do
        {
            printf("%d " ,Current->data);
            Current = Current->pNext;
        }
        while (Current != NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
}
