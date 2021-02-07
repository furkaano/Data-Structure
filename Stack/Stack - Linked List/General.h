#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define EXIT_PROGRAM    TRUE

#define TRUE    1
#define FALSE   0

typedef int BOOL;

void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit);



#endif // GENERAL_H_INCLUDED
