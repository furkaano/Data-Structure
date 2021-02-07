#ifndef BREADFIRST_TOPOLOGICALSORT_GRAPHS_H_INCLUDED
#define BREADFIRST_TOPOLOGICALSORT_GRAPHS_H_INCLUDED

// This is Graph.h file

#include "Queue.h"

typedef int BOOL;
#define TRUE    1
#define FALSE   0

typedef struct tagGraphs{
    int vertex;
    int ** adjMatrix;
}Graphs;

Graphs* PrepareGraph(); // Function to allocate memory
Graphs* InitializeGraph(); // Function to initialize Graph, adjacent matrix in particular
void AddEdgeToAdjMatrix(Graphs* pGraph, int row, int column); // Function to add edge to the specified location
void PrintAdjMatrix(Graphs* pGraph); // Function to print Adjacent Matrix
void PrintArray(Graphs* pGraph, int* pArr); // Function to print Array

int* CalcInDegree(Graphs* pGraph, int* pArr); // Function to calculate in-degree array
int* UpdateArray(Graphs* pGraph, int* pArr); // Function to update in-degree of graph's member
int** UpdateAdjMatrix(Graphs* pGraph, QueueMembers* pQueue, int* pArr); // Function to update Adjacent Matrix
int BFSTopologicalSort(Graphs* pGraph); // Function to sort as a Topological with using BFS


#endif //BREADFIRST_TOPOLOGICALSORT_GRAPHS_H_INCLUDED
