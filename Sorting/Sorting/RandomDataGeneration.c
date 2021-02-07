#include"RandomDataGeneration.h"

#define ALPHABET_LENGTH     26


/*void* AllocateMemory(int size, const char* pcszErrMsg, BOOL bExit)
{
    void *pvMem;

    pvMem = malloc(size);
    if(NULL == pvMem) {
        fprintf(stderr, "Cannot Allocate Memory!\n");
        fprintf(stderr, "%s\n", pcszErrMsg);
        if(TRUE == bExit)
            exit(1);
        else
            return NULL;
    }
    return pvMem;
}
*/
/* maxValue is INCLUSIVE!!! */
int GenerateRandomInteger(int maxValue)
{
    return (rand() % (maxValue + 1));
}
int* GenerateRandomIntArray(int arrSize, int maxValue){
    int i;
    int *pArr;

    pArr = AllocateMemory(sizeof(int) * arrSize, "GenerateRandomIntArray", TRUE);

    for(i=0; i < arrSize; ++i)
        pArr[i] = GenerateRandomInteger(maxValue);

    return pArr;
}
char GenerateRandomChar(BOOL upperCase){
     if(TRUE == upperCase)
        return ( (char)((int)'A' + (rand() % (ALPHABET_LENGTH))) );
     else
        return ( (char)((int)'a' + (rand() % (ALPHABET_LENGTH))) );
}
char* GenerateRandomString(BOOL upperCase, int maxLenght){
    int i;
    int size;
    char *pszStr;

    // String will have AT LEAST one character!!!
    size = GenerateRandomInteger(maxLenght) + 1;

    //Size + 1 for ending NULL!!!
    pszStr = AllocateMemory(sizeof(char) * (size + 1), "GenerateRandomString", EXIT_PROGRAM);

    for (i=0; i < size; ++i)
         pszStr[i] = GenerateRandomChar(upperCase);

    pszStr[size] = '\0';

    return pszStr;
}
