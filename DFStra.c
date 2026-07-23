// dfs using adjacency matrix representation of graph
#include<stdio.h>

#define V 4

int graph[V][V]=
{
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int visited[V]={0}; //  this will keep track of the visited vertices during the DFS traversal. Initially, all vertices are marked as unvisited (0).

void DFS(int vertex)
{
    printf("%d ",vertex);

    visited[vertex]=1; // when we visit a vertex, we mark it as visited by setting the corresponding index in the visited array to 1.

    for(int i=0;i<V;i++)
    {
        if(graph[vertex][i]==1 && visited[i]==0) // checks for each vertex if there is an edge between the current vertex and the adjacent vertex (graph[vertex][i]==1) and if the adjacent vertex has not been visited yet (visited[i]==0). If both conditions are true, it means we have found an unvisited neighbor, and we recursively call DFS on that neighbor.
        {
            DFS(i); // calling DFS recursively on the unvisited neighbor to explore its neighbors as well.
        }
    }
}

int main()
{
    printf("DFS Traversal\n");

    DFS(0); // starting the DFS traversal from vertex 0

    return 0;
}