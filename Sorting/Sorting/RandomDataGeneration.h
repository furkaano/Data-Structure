#ifndef RANDOMDATAGENERATION_H_INCLUDED
#define RANDOMDATAGENERATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "General.h"


void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit);

int GenerateRandomInteger(int maxValue);
int* GenerateRandomIntArray(int arrSize, int maxValue);

char GenerateRandomChar(BOOL upperCase);
char* GenerateRandomString(BOOL upperCase, int maxLenght);


#endif // RANDOMDATAGENERATION_H_INCLUDED
