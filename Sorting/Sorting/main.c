#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "general.h"
#include "RandomDataGeneration.h"
#include "Sort.h"

#define ARR_SIZE    100

#define ARR_MAX_VALUE   10000
int main()
{
    int* pArr;

    srand(time(NULL));

    pArr = GenerateRandomIntArray(ARR_SIZE, ARR_MAX_VALUE);
    printf("******Random Array - BEFORE SORT******\n");

    PrintArray(pArr, ARR_SIZE);

    if(TRUE == IsInOrder(pArr, ARR_SIZE))
        printf("Random Array is SORTED :)");
    else
        printf("Random Array is NOT SORTED :(");

    // Sort Array
    //SelectionSort(pArr, ARR_SIZE);
    //BubbleSort(pArr, ARR_SIZE);
    //InsertionSort(pArr, ARR_SIZE);
    QuickSort(pArr, 0, ARR_SIZE - 1);

    printf("\n******Random Array - AFTER SORT******\n");

    PrintArray(pArr, ARR_SIZE);

    if(TRUE == IsInOrder(pArr, ARR_SIZE))
        printf("Random Array is SORTED :)");
    else
        printf("Random Array is NOT SORTED :(");
    return 0;
}
