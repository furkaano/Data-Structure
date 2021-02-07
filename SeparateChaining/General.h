#ifndef SEPARATECHAINING_GENERAL_H
#define SEPARATECHAINING_GENERAL_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE    1
#define FALSE    0

typedef int BOOL;

void* AllocateMemory(size_t size, const char* pcszErrMsg, BOOL bExit);

#endif //SEPARATECHAINING_GENERAL_H
