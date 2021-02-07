#include "General.h"
#include "Queue.h"

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
BOOL Peek(QueueMembers* pQueue)
{
    // check node at the beginning of the list
    while(pQueue != NULL){
            pQueue->front = pQueue->front->pNext;
            return TRUE;
    }
    return FALSE;
}
void SortQueue(QueueMembers* pQueue, QueueMembers* pQueue2)
{
    // Find Min Value, put it to another queue
    // remove Min value of node which you put
    Queue* pIter = pQueue->front;
    while(NULL != pIter->pNext){
        Put(pQueue2, FindMinNode(pQueue));
        pIter = GetValue(pQueue, FindMinNode(pQueue));
    }
}
int FindMinNode(QueueMembers* pQueue)
{
    Queue* pIter = pQueue->front;
    int minValue = pIter->data;

    while(NULL != pIter->pNext){
        if(pIter->pNext->data < minValue)
            minValue = pIter->pNext->data;
        pIter = pIter->pNext;
    }
    return minValue;
}
QueueMembers* GetValue(QueueMembers* pQueue, int data)
{
    // Remove node with using given data
    Queue* pIter = pQueue->front;
    Queue* prev = NULL;

    while(NULL != pIter && pIter->data != data){
          prev = pIter;
          pIter = pIter->pNext;
    }
    // CASE 1-) Empty List && NOT FOUND
    if(NULL != pIter){
        // CASE 2-) Remove First item
        if(NULL == prev)
            pQueue->front = pIter->pNext;
        else // CASE 3-) Remove any other item!
            prev->pNext = pIter->pNext;
        pIter->pNext = NULL;
        free(pIter);
    }
    return pQueue;
}
Queue* LinkQueue(QueueMembers* pQueue, QueueMembers* pQueue2, QueueMembers* pQueue3)
{
    Queue* pIter1 = pQueue->front;
    Queue* pIter2 = pQueue2->front;

        while(NULL != pIter1->pNext && NULL != pIter2->pNext){
                if(FindMinNode(pQueue) < FindMinNode(pQueue2)){
                    Put(pQueue3, FindMinNode(pQueue));
                    pIter1 = GetValue(pQueue, FindMinNode(pQueue));
                }
                else{
                    Put(pQueue3, FindMinNode(pQueue2));
                    pIter2 = GetValue(pQueue2, FindMinNode(pQueue2));
                }
        }
        if(pIter1->pNext != NULL)
            while(NULL != pIter1->pNext){
                Put(pQueue3, FindMinNode(pQueue));
                pIter1 = GetValue(pQueue, FindMinNode(pQueue));
            }
        else
            while(NULL != pIter2->pNext){
                    Put(pQueue3, FindMinNode(pQueue2));
                    pIter2 = GetValue(pQueue2, FindMinNode(pQueue2));
            }
        return pQueue3->front;
}
int PeekInt(QueueMembers* pQueue)
{
    return pQueue->front->data;
}
void PrintQueue(QueueMembers* pQueue)
{
    Queue* pIter = pQueue->front;
    while(NULL != pIter){
        printf(" Item : %d\n", pIter->data);
        pIter = pIter->pNext;
    }
}
