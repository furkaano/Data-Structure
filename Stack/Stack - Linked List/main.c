#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Stack.h"

int main()
{
    Stack* pHead = NULL;
    int i;

    for(i=0; i<10; ++i)
        pHead = Push(pHead, i+1);
    printf("AFTER THE PUSH\n");
    PrintStack(pHead);
    for(i=5; i<10; ++i)
        pHead = Pop(pHead, &i+1);
    printf("AFTER THE POP\n");
    PrintStack(pHead);

    StackReverse(&pHead, &pHead->pNext);
    printf("AFTER THE REVERSE\n");
    PrintStack(pHead);
    return 0;
}
