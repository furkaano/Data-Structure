#include "Queue.h"
#include "General.h"

// This is Queue.c file

Queue* PrepareQueue(int data)
{
    // Initialize data and next pointer
    Queue* newQueue;

    newQueue = AllocateMemory(sizeof(Queue), "Allocation for Queue", TRUE);
    newQueue->pNext = NULL;
    newQueue->data = data;
    return newQueue;
}

QueueMembers* CreateEmptyQueue()
{
    // Initialize front and back
    QueueMembers* newQueue;

    newQueue = AllocateMemory(sizeof(QueueMembers), "Allocation for QueueMembers", TRUE);
    newQueue->front = NULL;
    newQueue->back = NULL;
    return newQueue;
}

Queue* Put(QueueMembers* pQueue, int toAdd)
{
    // Create a new linked list
    Queue* newItem = PrepareQueue(toAdd);
    if(pQueue->back == NULL)
        pQueue->back = pQueue->front = newItem;
    //Add new node at the end of the list and change back
    pQueue->back->pNext = newItem;
    pQueue->back = newItem;

    return newItem;
}

Queue* Get(QueueMembers* pQueue)
{
    // remove node at the beginning of the list
    Queue* pIter = pQueue->front;
    pQueue->front = pQueue->front->pNext;
    free(pIter);
    return pIter;
}

void PrintQueue(QueueMembers* pQueue)
{
    Queue* pIter = pQueue->front;
    while(NULL != pIter){
        printf(" Item : %d\n", pIter->data);
        pIter = pIter->pNext;
    }
}
int PeekInt(QueueMembers* pQueue)
{
    return pQueue->front->data;
}