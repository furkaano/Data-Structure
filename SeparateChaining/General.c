#include "general.h"

void* AllocateMemory(size_t size, const char* pcszErrMsg, BOOL bExit)
{
    void* pvMem;

    pvMem = malloc(size);
    if (NULL == pvMem) {
        fprintf(stderr, "Cannot allocate memory for %s\n", pcszErrMsg);
        if (TRUE == bExit)
            exit(1);
    }

    return pvMem;
}
