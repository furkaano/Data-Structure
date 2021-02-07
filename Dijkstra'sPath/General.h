#ifndef DIJKSTRA_SPATH_GENERAL_H
#define DIJKSTRA_SPATH_GENERAL_H

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define EXIT_PROGRAM    TRUE

#define TRUE    1
#define FALSE   0

typedef int BOOL;

void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit);

#endif //DIJKSTRA_SPATH_GENERAL_H
