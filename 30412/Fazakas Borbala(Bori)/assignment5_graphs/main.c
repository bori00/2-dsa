#include <stdio.h>
#include "matrixGraph.h"
#include "listGraph.h"

int main() {
    FILE *inFile = fopen("../data.in", "r");
    mGraph myGraph = createMGraph_fromFile(inFile);
    printAdjMatrix(&myGraph, stdout);
    dfs(&myGraph, stdout, stdin);
    bfs(&myGraph, stdout, stdin);

    lGraph listGraph = createLGaph_fromAdjMatrix(&myGraph);
    printAdjLists(&listGraph, stdout);
    l_dfs(&listGraph, stdout, stdin);
    l_bfs(&listGraph, stdout, stdin);

    int source, dest;
    printf("which are the two endpoints of the longest path you are searching for?");
    scanf("%d %d", &source, &dest);
    list longestPath = findLongestPath(&listGraph, source, dest);
    printf("the longest path is: ");
    printAllList(&longestPath, stdout);

    mGraph newMatrixGraph = createMGaph_fromAdjList(&listGraph);
    printAdjMatrix(&newMatrixGraph, stdout);

    primsAlgorithm(&listGraph);

    dijkstraAlgorithm(&listGraph);

    BellmanFordAlgorithm(&listGraph);

    kruskalAlgorithm(&listGraph);

    vertexCoverApproximation(&listGraph);
    return 0;
}