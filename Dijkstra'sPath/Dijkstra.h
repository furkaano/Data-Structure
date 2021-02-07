#ifndef DIJKSTRA_SPATH_DIJKSTRA_H
#define DIJKSTRA_SPATH_DIJKSTRA_H

#include "General.h"

#define VERTEX_COUNT    7
#define INF             INT_MAX
#define INVALID_VERTEX  -1
#define V1        0
#define V2        1
#define V3        2
#define V4        3
#define V5        4
#define V6        5
#define V7        6

#define KNOWN   TRUE
#define UNKNOWN FALSE

typedef int BOOL;

typedef struct tagGraphs{
    int vertex;
    int ** adjMatrix;
}Graphs;

Graphs* PrepareGraph(); // Function to allocate memory
Graphs* InitializeGraph(); // Function to initialize Graph, adjacent matrix in particular
void AddEdgeToAdjMatrix(Graphs* pGraph, int row, int column, int toAdd); // Function to add edge to the specified location

int* InitializeKnown();
int* InitializeMin_Costs();
int* InitializePreviousVertex();

void DijkstraShortestPath(Graphs* pGraph, int* minCosts, int* known, int* previousVertex, int start_vertex);
void PrimAlgorithm(Graphs* pGraph, int* minCosts, int* known, int* previousVertex, int start_vertex);
int FindSmallestUnknown(int* known, int* minCosts);

void PrintMinCosts(int* minCosts, int start_vertex);
void PrintPreviousVertex(int* previousVertex);
void PrintPath(int* previousVertex, int vertex);


#endif //DIJKSTRA_SPATH_DIJKSTRA_H
