#include "General.h"

void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit)
{
    void* pvMem;

    pvMem = malloc(size);
    if(NULL == pvMem){
        fprintf(stderr, "Cannot allocate memory!\n");
        fprintf(stderr, "%s\n", pcszErrMsg);
        if(TRUE == bExit)
            exit(1);
        else
            return NULL;
    }
    return pvMem;
}
