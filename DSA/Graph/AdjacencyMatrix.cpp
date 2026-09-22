#include <stdio.h>
#include <string.h>

// Adjacency Matrix For Graph Representation
#define MAX 100

int adjMatrix[MAX][MAX];
int numVertices = 0;

// Initialize Adjacency Matrix
void initMatrix(int graphType)
{
    for (int i = 0; i < MAX; i++)
    {
        if (graphType == 0) // Undirected
        {
            for (int j = 0; j < MAX; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
        else if (graphType == 1) // Directed
        {
            for (int j = 0; j < MAX; j++)
            {
                adjMatrix[i][j] = -1;
            }
        }
    }
}

// Add Edge To Graph
void addEdge(int src, int dest, int weight = 1)
{
    if (src >= MAX || dest >= MAX)
    {
        printf("Invalid vertex!\n");
        return;
    }
    adjMatrix[src][dest] = weight;
}

// Print Adjacency Matrix
void printMatrix()
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initMatrix(1);
    addEdge(0, 1, 5);
    addEdge(1, 2, 3);
    addEdge(2, 3, 7);
    addEdge(3, 4, 2);
    addEdge(4, 0, 9);

    numVertices = 6;
    printMatrix();
}
