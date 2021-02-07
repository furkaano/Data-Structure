#include <stdio.h>
#include "stdlib.h"

#include "Queue.h"
#include "General.h"
#include "Graph.h"

// This is Main.c file

int main() {
    Graphs* pGraph;
    pGraph = InitializeGraph();

    AddEdgeToAdjMatrix(pGraph, 0, 1);
    AddEdgeToAdjMatrix(pGraph, 0, 5);
    AddEdgeToAdjMatrix(pGraph, 1, 7);
    AddEdgeToAdjMatrix(pGraph, 3, 2);
    AddEdgeToAdjMatrix(pGraph, 3, 4);
    AddEdgeToAdjMatrix(pGraph, 3, 7);
    AddEdgeToAdjMatrix(pGraph, 3, 8);
    AddEdgeToAdjMatrix(pGraph, 4, 8);
    AddEdgeToAdjMatrix(pGraph, 6, 0);
    AddEdgeToAdjMatrix(pGraph, 6, 1);
    AddEdgeToAdjMatrix(pGraph, 6, 2);
    AddEdgeToAdjMatrix(pGraph, 3, 7);
    AddEdgeToAdjMatrix(pGraph, 8, 2);
    AddEdgeToAdjMatrix(pGraph, 8, 7);
    AddEdgeToAdjMatrix(pGraph, 9, 4);

    printf("First Adjacent Matrix\n");
    PrintAdjMatrix(pGraph);
    printf("\n-----------------------\n");
    BFSTopologicalSort(pGraph);
    return 0;
}
