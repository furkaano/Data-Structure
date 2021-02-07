#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

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
Queue* Put(QueueMembers* pQueue, int toAdd);
Queue* Get(QueueMembers* pQueue);
QueueMembers* GetValue(QueueMembers* pQueue, int data);
int FindMinNode(QueueMembers* pQueue);
BOOL Peek(QueueMembers* pQueue);
void SortQueue(QueueMembers* pQueue, QueueMembers* pQueue2);
Queue* LinkQueue(QueueMembers* pQueue, QueueMembers* pQueue2, QueueMembers* pQueue3);


int PeekInt(QueueMembers* pQueue);
void PrintQueue(QueueMembers* pQueue);

#endif // QUEUE_H_INCLUDED
