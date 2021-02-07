#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "general.h"

BOOL IsInOrder(int *pArr, int size);
void SwapInIntArray(int *pArr, int first, int second);
void PrintArray(int* pArr, int size);

void SelectionSort(int* pArr, int size);
void BubbleSort(int* pArr, int size);
void InsertionSort(int* pArr, int size);
void QuickSort(int* pArr, int start, int end);


#endif // SORT_H_INCLUDED
