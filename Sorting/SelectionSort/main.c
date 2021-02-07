#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE    10

void SelectionSort(int arr[] , int size);

void SelectionSort(int arr[] , int size)
{
    int i,j;
    int min, temp;

    for(i=0; i<size; i++){
        min = i;
        for(j=1; j<size; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = arr[i];
            }
        }
    }
}
int main()
{

    return 0;
}
