// printing graph using adjacency matrix representation in C programming language

#include <stdio.h>
#include <stdlib.h>

#define V 4

struct Node //for representing a vertex in the adjacency list representation of a graph we need a structure to represent a node in the adjacency list representation of a graph. Each node will contain the vertex number and a pointer to the next node in the list.
{
    int vertex;
    struct Node *next;
};

struct Node* createNode(int vertex)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node)); //Dynamically allocating memory for a new node in the adjacency list representation of a graph
    newNode->vertex = vertex;
    newNode->next = NULL; // initial node has no next node, so we set the next pointer to NULL

    return newNode;
}

void addEdge(struct Node *graph[], int src, int dest) // used for adding an edge to the adjacency list representation of a graph
{
    struct Node *newNode; // taking a new node to add an edge in the adjacency list representation of a graph

    newNode = createNode(dest); // allocating memory for a new node and setting its vertex value to the destination vertex
    newNode->next = graph[src]; // this line is used to link the new node to the existing list of neighbors for the source vertex
    graph[src] = newNode; // here we are setting the head of the adjacency list for the source vertex to the new node, effectively adding the new edge to the graph

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void printGraph(struct Node *graph[], int vertices) // for printing the adjacency list representation of a graph
{
    for(int i = 0; i < vertices; i++)
    {
        struct Node *temp = graph[i];

        printf("%d -> ", i);

        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    struct Node *graph[V] = {NULL};

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);

    printGraph(graph,V);

    return 0;
}