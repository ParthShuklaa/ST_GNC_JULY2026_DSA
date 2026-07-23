//if i want to use a function for creating Adjacency matrix so i can do follow :
//Step 1: 

#include<stdio.h>

#define V 4 //. no of max vertices in the graph

void addEdge(int graph[V][V], int u, int v) // used for adding an edge to the adjacency matrix
{
    graph[u][v] = 1;
    graph[v][u] = 1;      // Undirected graph
}

void printGraph(int graph[V][V]) // used for printing the adjacency matrix
{
    printf("Adjacency Matrix\n\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

// now lets add a method to print neighbors of a vertex in the adjacency matrix
void printNeighbors(int graph[V][V], int vertex) // used for printing the neighbors of a given vertex in the adjacency matrix
{
    printf("Neighbors of vertex %d: ", vertex);

    for(int i=0;i<V;i++)
    {
        if(graph[vertex][i] == 1) // if there is an edge between the vertex and i, then i is a neighbor of the vertex
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main()
{
    int graph[V][V] = {0}; // here graph is initialized to 0, which means there are no edges between any vertices initially
   // printGraph(graph);

    addEdge(graph,0,1); // by calling graph with 0,1 we are adding an edge between vertex 0 and vertex 1 in the adjacency matrix
       // printGraph(graph);

    addEdge(graph,0,2);// so this equal to graph[0][1] = 1 and graph[1][0] = 1
       // printGraph(graph);

    addEdge(graph,1,2);// by calling method we are avoiding the manual work of adding edges in the adjacency matrix
        //printGraph(graph);

    addEdge(graph,1,3);

    printGraph(graph);
    //printig neighbors of vertex 1
    printNeighbors(graph, 1); // here we are calling the method to print neighbors of vertex 1 which is represented as 1 in the adjacency matrix and it will print the neighbors of vertex 1 which are 0,2,3 n passing 2 will give neighbors of vertex 2 which are 0,1 and passing 3 will give neighbors of vertex 3 which is 1 n so on 
    

    return 0;
}

