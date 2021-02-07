#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "general.h"

typedef int DATATYPE;

typedef struct tagQueue{
    DATATYPE* pData;
    int capacity;
    int size;
    int front;
    int back;
}Queue;

Queue* CreateQueue(int capacity);
void DestroyQueue(Queue* pQueue);

BOOL Put(Queue*, int);
BOOL Get(Queue*, DATATYPE*);
BOOL Peek(Queue*, DATATYPE*);
BOOL IsEmpty(Queue*);
BOOL IsFull(Queue*);

#endif // QUEUE_H_INCLUDED
