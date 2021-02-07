#include "queue.h"

Queue* CreateQueue(int capacity)
{
    Queue* pQueue;

    pQueue = AllocateMemory(sizeof(Queue), "CreateQueue - 1", EXIT_PROGRAM);
    pQueue->pData = AllocateMemory(sizeof(DATATYPE) * capacity, "CreateQueue - 1", EXIT_PROGRAM);
    pQueue->capacity = capacity;
    pQueue->size = 0;
    pQueue->front = 0;
    pQueue->back = 0;
    return pQueue;
}
void DestroyQueue(Queue* pQueue)
{
    free(pQueue->pData);
    free(pQueue);
}
BOOL Put(Queue* pQueue, int toAdd)
{
    if(FALSE == IsFull(pQueue)){
        pQueue->pData[pQueue->back] = toAdd;
        pQueue->back++;
        pQueue->back = (pQueue->back % pQueue->capacity); // FOR CIRCULARITY
        pQueue->size++;
        return TRUE;
    }
    return FALSE;
}
BOOL Get(Queue* pQueue, DATATYPE* pReturn)
{
    if(FALSE == IsEmpty(pQueue)){
        *pReturn = pQueue->pData[pQueue->front];
        ++pQueue->front;
        pQueue->front = (pQueue->front % pQueue->capacity); // FOR CIRCULARITY
        pQueue->size--;
        return TRUE;
    }
    return FALSE;
}
BOOL Peek(Queue* pQueue, DATATYPE* pReturn)
{
    if(FALSE == IsEmpty(pQueue)){
        *pReturn = pQueue->pData[pQueue->front];
        return TRUE;
    }
    return FALSE;
}
BOOL IsEmpty(Queue* pQueue)
{
    return(pQueue->size == 0);
}
BOOL IsFull(Queue* pQueue)
{
    return(pQueue->size == pQueue->capacity);
}
