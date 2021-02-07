#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct tagStack{
    int top;
    int capacity;
    int* pArr;
}Stack;

Stack* CreateStack(int capacity);

int IsFull(Stack* pStack);
int IsEmpty(Stack* pStack);

void Push(Stack* pStack, int data);
int Pop(Stack* pStack);
int Peek(Stack* pStack);



#endif // STACK_H_INCLUDED
