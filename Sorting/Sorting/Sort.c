#include "Sort.h"

BOOL IsInOrder(int *pArr, int size)
{
   int i;

   for(i=0; i < size - 1; ++i)
       if(pArr[i] > pArr[i+1])
          return FALSE;
   return TRUE;
}

void SwapInIntArray(int *pArr, int first, int second)
{
    int temp;

    temp = pArr[first];
    pArr[first] = pArr[second];
    pArr[second] = temp;
}

void PrintArray(int* pArr, int size)
{
    int i;

    for(i=0; i<size; ++i)
        printf("Array[%d] ....: %d \n", i+1, pArr[i]);

}

void SelectionSort(int* pArr, int size)
{
    int i, j;
    int smallest_index, temp;

    for(i=0; i < size-1; ++i){
        smallest_index = i;
        for(j = i+1; j < size; ++j){
            if(pArr[smallest_index] < pArr[j])
                smallest_index = j;
        }// inner for - j
        SwapInIntArray(pArr, i, smallest_index);
    }// outer for - i
}

void BubbleSort(int* pArr, int size)
{
    int pass, i;
    int swapFlag;

    for(pass = 0; pass < size - 1; ++pass){
        swapFlag = FALSE;
        for(i=0; i < size - pass - 1; ++i){
            if(pArr[i] > pArr[i+1]){
            SwapInIntArray(pArr, i, i+1);
            swapFlag = TRUE;
            }// if
        }// inner for - i
        // If swap did not occur this means array is sorted
        // No need to continue
        if(FALSE == swapFlag)
            break;
    }// outer for - pass

}

void InsertionSort(int* pArr, int size)
{
    int i, j, curr;

    for(i=1; i < size; ++i){
        j = i - 1;
        curr = pArr[i];
        // Find the correct location
        while(pArr[j] > curr && j >= 0){
            pArr[j+1] = pArr[j];
            --j;
        }
        pArr[j+1] = curr;
    }
}

void QuickSort(int* pArr, int start, int end)
{
    int i, j;
    int pivot, middle, temp;

    if(start < end){

        i = start;
        j = end - 1;
        //middle = (start + end) / 2;
        pivot = pArr[end];

        for(;;) {
            while(pArr[i] < pivot)
                ++i;
            while(pivot <= pArr[j])
                --j;

            if(j <= i)
                break;

            temp = pArr[i];
            pArr[i] = pArr[j];
            pArr[j] = temp;
        }
        temp = pArr[end];
        pArr[end] = pArr[i];
        pArr[i] = temp;

        QuickSort(pArr, start, i - 1);
        QuickSort(pArr, i + 1, end);
    }
}
