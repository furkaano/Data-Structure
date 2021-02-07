#include "Graph.h"
#include "General.h"
#include "Queue.h"

// This is Graph.c file

Graphs* PrepareGraph()
{
    Graphs* pGraph = AllocateMemory(sizeof(Graphs), "Allocation for Graphs", EXIT_PROGRAM);
    pGraph->vertex = 10; // It is 10 because array it starts from 0 to 9
    //This is for two-dimensional matrix
    pGraph->adjMatrix = (int**)AllocateMemory(sizeof(int*) * pGraph->vertex, "Allocation for rows of matrix", EXIT_PROGRAM);
    for(int i = 0; i < pGraph->vertex; ++i)
        pGraph->adjMatrix[i] = (int*)AllocateMemory(sizeof(int) * pGraph->vertex, "Allocation for columns of matrix", EXIT_PROGRAM);

    return pGraph;
}
Graphs* InitializeGraph()
{
    // Every element of matrix will be 0
    Graphs* newGraph;
    newGraph = PrepareGraph();
    for (int i = 0; i < newGraph->vertex; ++i)
        for (int j = 0; j < newGraph->vertex; ++j)
            newGraph->adjMatrix[i][j] = 0;

    return newGraph;
}
void AddEdgeToAdjMatrix(Graphs* pGraph, int row, int column)
{
    // Edge's location of matrix will be 1
    pGraph->adjMatrix[row][column] = 1;
}
void PrintAdjMatrix(Graphs* pGraph)
{
    // This function prints Adjacent Matrix of Graph
    printf("Updated Adjacent Matrix\n");
    for (int i = 0; i < pGraph->vertex; ++i){
        for (int j = 0; j < pGraph->vertex; ++j) {
            printf("%d ", pGraph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void PrintArray(Graphs* pGraph, int* pArr)
{
    // This function prints in-degree array
    printf("Update in-degrees : ");
    for (int i = 0; i < pGraph->vertex; ++i) {
        printf("%d ", pArr[i]);
    }
}
int* UpdateArray(Graphs* pGraph, int* pArr)
{
    // This function updates in-degree of graph's member
    int i, j;
    for(i = 0; i < pGraph->vertex; ++i){
        if(pArr[i] != -1){
            pArr[i] = 0;
                for(j = 0; j < pGraph->vertex; ++j){
                    pArr[i] += pGraph->adjMatrix[j][i];
                }
        }
    }
    return pArr;
}
int** UpdateAdjMatrix(Graphs* pGraph, QueueMembers* pQueue, int* pArr)
{
    // This function updates matrix, it's like decreasing of degree
    int i, j;
    for(i = 0; i < pGraph->vertex; ++i){
        if(pArr[i] == 0){
            Put(pQueue, i);
            pArr[i] = -1;
            for(j = 0; j < pGraph->vertex; ++j){
                if(pGraph->adjMatrix[i][j] > 0)
                    --pGraph->adjMatrix[i][j];
            }
        }
    }
    return pGraph->adjMatrix;
}
int* CalcInDegree(Graphs* pGraph, int* pArr)
{
    // This array includes in-degree of graph's member
    pArr = AllocateMemory(sizeof(int) * pGraph->vertex, "Allocation for Array", EXIT_PROGRAM);
    int i, j;
    for (i = 0; i < pGraph->vertex; ++i) {
        pArr[i] = 0;
        for (j = 0; j < pGraph->vertex; ++j) {
            pArr[i] += pGraph->adjMatrix[j][i];
        }
        printf("%d ", pArr[i]);
    }
    return pArr;
}

int BFSTopologicalSort(Graphs* pGraph)
{
    QueueMembers* pQueue = CreateEmptyQueue();
    int* pArr = CalcInDegree(pGraph, pArr);
    printf("\n------\n");
    int counter = (pGraph->vertex * (-1)); // Total in-degree of array when implementation is over
    while(1){
        int flag = 0;
        for(int i = 0; i < pGraph->vertex; ++i){
            if(pArr[i] == -1)
                flag += pArr[i];
        }
        if(flag == counter) // Checking of implementation is over or not
            goto end;

        pGraph->adjMatrix = UpdateAdjMatrix(pGraph, pQueue, pArr);
        PrintAdjMatrix(pGraph);
        printf("\n------------\n");
        pArr = UpdateArray(pGraph, pArr);
        PrintArray(pGraph, pArr);
        printf("\n------------\n");
        PrintQueue(pQueue);
        }
    end:
        return 0;
}

