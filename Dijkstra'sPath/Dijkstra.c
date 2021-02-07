#include "Dijkstra.h"
#include "General.h"

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
            newGraph->adjMatrix[i][j] = INF;

    return newGraph;
}
void AddEdgeToAdjMatrix(Graphs* pGraph, int row, int column, int toAdd)
{
    // Edge's location of matrix will be 1
    pGraph->adjMatrix[row][column] = toAdd;
}
int* InitializeKnown()
{
    int* known = AllocateMemory(sizeof(int) * VERTEX_COUNT , "Allocation for KnownArray",EXIT_PROGRAM);
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        known[i] = UNKNOWN;
    }
    return known;
}
int* InitializeMin_Costs()
{
    int * MinCosts = AllocateMemory(sizeof(int) *VERTEX_COUNT,"Allocation for MinCostArray", EXIT_PROGRAM);
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        MinCosts[i] = INF;
    }
    return MinCosts;
}
int* InitializePreviousVertex()
{
    int * PrevVertex = AllocateMemory(sizeof(int) * VERTEX_COUNT, "Allocation for PreviousVertexArray",EXIT_PROGRAM);
    for (int i = 0; i < VERTEX_COUNT; ++i) {
        PrevVertex[i] = INVALID_VERTEX;
    }
    return PrevVertex;
}
int FindSmallestUnknown(int* known, int* minCosts)
{
    int min_cost = INF;
    int min_cost_vertex = INVALID_VERTEX;

    for(int i=0; i < VERTEX_COUNT; ++i){
        if(UNKNOWN == known[i])
            if(minCosts[i] < min_cost){
                min_cost = minCosts[i];
                min_cost_vertex = i;
            }
    }
    return min_cost_vertex;
}
void DijkstraShortestPath(Graphs* pGraph, int* minCosts, int* known, int* previousVertex, int start_vertex)
{
    int min_cost_vertex;
    int cost;
    //Set start vertex' cost as 0(min)
    minCosts[start_vertex] = 0;
    // Find "min cost vertex" "among unknown ones"
    while(INVALID_VERTEX != (min_cost_vertex = FindSmallestUnknown(known, minCosts))){
        //Make known selected vertex
        known[min_cost_vertex] = KNOWN;
        //Check selected vertex' neighbours
        for(int i=0; i < VERTEX_COUNT; ++i){
            //Check unknown neighbours
            //INF != pGraph->adjMatrix[min_cost_vertex][i] : means "i" is a neighbour of min_cost_vertex
            if(INF != pGraph->adjMatrix[min_cost_vertex][i] && UNKNOWN == known[i]){
                //UNKNOWN neighbour's cost from selected vertex
                cost = pGraph->adjMatrix[min_cost_vertex][i];
                //if cost of neighbour can be lowered then set this new cost as the
                //current min cost of it (i.e neighbour's)
                if(minCosts[min_cost_vertex] + cost < minCosts[i]){
                    minCosts[i] = minCosts[min_cost_vertex] + cost;
                    previousVertex[i] = min_cost_vertex;
                }
            }// if
        }// for
    }// while
}
void PrimAlgorithm(Graphs* pGraph, int* minCosts, int* known, int* previousVertex, int start_vertex)
{
    int min_cost_vertex;
    int cost;
    //Set start vertex' cost as 0(min)
    minCosts[start_vertex] = 0;
    // Find "min cost vertex" "among unknown ones"
    while(INVALID_VERTEX != (min_cost_vertex = FindSmallestUnknown(known, minCosts))){
        //Make known selected vertex
        known[min_cost_vertex] = KNOWN;
        //Check selected vertex' neighbours
        for(int i=0; i < VERTEX_COUNT; ++i){
            //Check unknown neighbours
            //INF != pGraph[min_cost_vertex][i] : means "i" is a neighbour of min_cost_vertex
            if(INF != pGraph->adjMatrix[min_cost_vertex][i] && UNKNOWN == known[i]){
                //UNKNOWN neighbour's cost from selected vertex
                cost = pGraph->adjMatrix[min_cost_vertex][i];
                //if cost of neighbour can be lowered then set this new cost as the
                //current min cost of it (i.e neighbour's)
                if(cost < minCosts[i]){ // DIFFERENT FROM DIJKSTRA
                    minCosts[i] = cost; // DIFFERENT FROM DIJKSTRA
                    previousVertex[i] = min_cost_vertex;
                }
            }// if
        }// for
    }// while
}
void PrintMinCosts(int* minCosts, int start_vertex)
{
    for (int i = 0; i < VERTEX_COUNT; ++i)
        printf("V%d's min cost from %d is %d\n", (i + 1), start_vertex, minCosts[i]);
}
void PrintPreviousVertex(int* previousVertex)
{
    for (int i = 0; i < VERTEX_COUNT; ++i)
        printf("V%d's previous vertex is V%d\n", (i + 1), (previousVertex[i] + 1) );
}
void PrintPath(int* previousVertex, int vertex)
{
    if (INVALID_VERTEX != vertex) {
        PrintPath(previousVertex, previousVertex[vertex]);
        printf("V%d -> ", (vertex + 1));
    }
}
