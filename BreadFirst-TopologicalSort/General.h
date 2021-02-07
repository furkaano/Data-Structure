#ifndef BREADFIRST_TOPOLOGICALSORT_GENERAL_H_INCLUDED
#define BREADFIRST_TOPOLOGICALSORT_GENERAL_H_INCLUDED

// This is General.h file

#include "stdio.h"
#include "stdlib.h"

#define EXIT_PROGRAM    TRUE

#define TRUE    1
#define FALSE   0

typedef int BOOL;

void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit);


#endif //BREADFIRST_TOPOLOGICALSORT_GENERAL_H_INCLUDED
