#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Queue.h"

int main()
{
    QueueMembers* pQueue = CreateEmptyQueue();
//    QueueMembers* pQueue2 = CreateEmptyQueue();// Sorted Queue
    QueueMembers* pQueue3 = CreateEmptyQueue();
    QueueMembers* pQueue4 = CreateEmptyQueue();// Linked Queue with Queue and Queue3

    //int i;
    //for(i=0; i<10; ++i)
    // Putting first queue
        Put(pQueue, 10);
        Put(pQueue, 30);
        Put(pQueue, 40);
        Put(pQueue, 50);
        Put(pQueue, 15);
        Put(pQueue, 25);
        Put(pQueue, 18);
    // Putting Third Queue
        Put(pQueue3, 5);
        Put(pQueue3, 150);
        Put(pQueue3, 20);
        Put(pQueue3, 47);
        Put(pQueue3, 19);
        Put(pQueue3, 4);
        Put(pQueue3, 27);
        Put(pQueue3, 160);


    printf("*********QUEUE********\n");
    PrintQueue(pQueue);
    printf("*********QUEUE 3********\n");
    PrintQueue(pQueue3);

//    for(i=0; i<2; ++i){
//        if(pQueue->front != NULL)
//            printf("%d peeked from Queue :)\n", PeekInt(pQueue));
//        else
//            printf("PEEK : QUEUE IS EMPTY\n");
//
//        if(pQueue != NULL){
//            printf("=> %d obtained from Queue\n", PeekInt(pQueue));
//            Get(pQueue);
//        }else
//            printf("GET : QUEUE IS EMPTY\n");
//    }

//    printf("****QUEUE AFTER THE REMOVING*****\n");
//    PrintQueue(pQueue);

//    printf("****SORT QUEUE****\n");
//    SortQueue(pQueue, pQueue2);
//    PrintQueue(pQueue2);

    printf("****LINKED QUEUE****\n");
    pQueue4->front = LinkQueue(pQueue, pQueue3, pQueue4); // pQueue and pQueue3 Linked and return as a pQueue4
    PrintQueue(pQueue4);
    return 0;
}
