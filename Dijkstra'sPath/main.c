#include "General.h"
#include "Dijkstra.h"

int main() {

    Graphs* pGraph;
    pGraph = InitializeGraph();

    AddEdgeToAdjMatrix(pGraph, 0, 1, 2);
    AddEdgeToAdjMatrix(pGraph, 0, 3, 1);
    AddEdgeToAdjMatrix(pGraph, 1, 3, 3);
    AddEdgeToAdjMatrix(pGraph, 1, 4, 10);
    AddEdgeToAdjMatrix(pGraph, 2, 0, 4);
    AddEdgeToAdjMatrix(pGraph, 2, 5, 5);
    AddEdgeToAdjMatrix(pGraph, 3, 2, 2);
    AddEdgeToAdjMatrix(pGraph, 3, 4, 2);
    AddEdgeToAdjMatrix(pGraph, 3, 5, 8);
    AddEdgeToAdjMatrix(pGraph, 3, 6, 4);
    AddEdgeToAdjMatrix(pGraph, 6, 5, 1);

    //Initialize arrays
    int* known = InitializeKnown();
    int* minCosts = InitializeMin_Costs();
    int* previousVertex = InitializePreviousVertex();

    printf("DIJKSTRA ALGORITHM\n");

    DijkstraShortestPath(pGraph, minCosts, known, previousVertex, V1);

    PrintMinCosts(minCosts, V1);
    printf("-----------------\n");
    PrintPreviousVertex(previousVertex);

    printf("-----------------\n");
    printf("PATHS\n");

    for (int i = 0; i < VERTEX_COUNT; ++i) {
        printf("Path to reach V%d is ", (i+1));
        PrintPath(previousVertex, i);
        printf("%d (min. cost)\n", minCosts[i]);
    }
    /*
    //printf("-----------------\n");
    printf("PRIM ALGORITHM\n");

    PrimAlgorithm(pGraph, minCosts, known, previousVertex, V1);

    PrintMinCosts(minCosts, V1);
    printf("-----------------\n");
    PrintPreviousVertex(previousVertex);

    printf("-----------------\n");
    printf("PATHS\n");

    for (int i = 0; i < VERTEX_COUNT; ++i) {
        printf("Path to reach V%d is ", (i+1));
        PrintPath(previousVertex, i);
        printf("%d (min. cost)\n", minCosts[i]);
    }
    return 0;
     */
}
