#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Stack.h"

int main()
{
    Stack* pStack = CreateStack(100);

    Push(pStack, 20);
    Push(pStack, 30);
    Push(pStack, 10);

    printf("%d popped from stack\n", Pop(pStack));
    return 0;
}
