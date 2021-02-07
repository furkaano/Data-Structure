#ifndef BREADFIRST_TOPOLOGICALSORT_QUEUE_H_INCLUDED
#define BREADFIRST_TOPOLOGICALSORT_QUEUE_H_INCLUDED

// This is Queue.h file

typedef struct tagQueue{
    struct tagQueue* pNext;
    int data;
}Queue;

typedef struct pQueue{
    struct tagQueue* front;
    struct tagQueue* back;
}QueueMembers;

Queue* PrepareQueue(int data); //  Function to create a new linked list node.
QueueMembers* CreateEmptyQueue(); // Function to create an empty queue.
Queue* Put(QueueMembers* pQueue, int toAdd); // Function to put int value in queue
Queue* Get(QueueMembers* pQueue); // Function to get value from queue
void PrintQueue(QueueMembers* pQueue);
int PeekInt(QueueMembers* pQueue);

#endif //BREADFIRST_TOPOLOGICALSORT_QUEUE_H
