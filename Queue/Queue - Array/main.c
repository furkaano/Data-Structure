#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define QUEUE_SIZE  10

int main()
{
    Queue* pQueue;
    int i;
    DATATYPE data;

    pQueue = CreateQueue(QUEUE_SIZE);

    for(i=0; i < QUEUE_SIZE + 2; ++i){
        if(TRUE == Put(pQueue, i+1))
            printf("%d added to the queue :)\n", i+1);
        else
            printf("QUEUE IS FULL : %d could NOT be added to the queue :(\n", i+1);
        printf("BACK : %d\n", pQueue->back);
        printf("FRONT : %d\n", pQueue->front);
        printf("SIZE : %d\n", pQueue->size);
        }

    printf("\n*****QUEUE*****\n");
    for(i=0; i < QUEUE_SIZE; ++i)
        printf("%d.member is : %d\n", i+1, pQueue->pData[i]);
    printf("*****************\n");

    for(i=0; i < QUEUE_SIZE + 3; ++i){
        if(TRUE == Peek(pQueue, &data))
            printf("%d PEEKED :)\n", data);
        else
            printf("PEEK : QUEUE IS EMPTY !!!\n");

        if(TRUE == Get(pQueue, &data))
            printf("%d obtained from queue\n", data);
        else
            printf("GET : QUEUE IS EMPTY !!!\n");
        printf("BACK : %d\n", pQueue->back);
        printf("FRONT : %d\n", pQueue->front);
        printf("SIZE : %d\n", pQueue->size);
    }

    DestroyQueue(pQueue);
    return 0;
}
