#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200005

// Structure for adjacency list node
struct Node
{
    int vertex;
    struct Node *next;
};

// Queue implementation
int queue[MAX];
int front = 0;
int rear = -1;

// Create new graph node
struct Node* createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (Undirected Graph)
void addEdge(struct Node *graph[], int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph[src]; // this line is used to link the new node to the existing list of neighbors for the source vertex
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest]; // this is used to link the new node to the existing list of neighbors for the destination vertex
    graph[dest] = newNode;
}

// BFS Function that checks for valid path
bool validPath(int n, struct Node *graph[], int source, int destination)
{
    bool visited[MAX] = {false};

    front = 0;
    rear = -1;

    // Enqueue source so that we can start the BFS from it
    queue[++rear] = source;
    visited[source] = true;

    while (front <= rear)
    {
        int current = queue[front++];

        // Destination found
        if (current == destination)
            return true;

        struct Node *temp = graph[current];

        while (temp != NULL)
        {
            int neighbor = temp->vertex;

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue[++rear] = neighbor;
            }

            temp = temp->next;
        }
    }

    return false; //  when the queue is empty and we haven't found the destination, it means there is no valid path from source to destination
}
// here queue is used for tracking the vertices to be explored in the BFS traversal, and visited array is used to keep track of which vertices have already been explored to avoid cycles and redundant checks.
int main()
{
    int n = 6;

    // Graph
    struct Node *graph[MAX] = {NULL};

    // Add edges
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,3,5);
    addEdge(graph,5,4);
    addEdge(graph,4,3);
    addEdge(graph,2,3);

    int source = 0;
    int destination = 5;

    if(validPath(n,graph,source,destination))
        printf("Path Exists\n");
    else
        printf("No Path Exists\n");

    return 0;
}