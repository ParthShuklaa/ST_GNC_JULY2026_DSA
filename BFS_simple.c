// BFS traversal for same matrix representation of graph using Queue 
#include<stdio.h>

#define V 4

int graph[V][V]=
{
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int visited[V]={0};

int queue[20]; // for bfs we are using Queue to store the vertices to be visited

int front=0;

int rear=-1;

void BFS(int start)
{
    queue[++rear]=start; // adding the starting vertex to the queue

    visited[start]=1; // keeping track of the visited vertices

    while(front<=rear) // ie while the queue is not empty
    {
        int current=queue[front++]; // so we will take the first vertex from the queue and mark it as visited and then we will add all its neighbors to the queue

        printf("%d ",current);

        for(int i=0;i<V;i++)
        {
            if(graph[current][i]==1 && visited[i]==0) // here we will check if the current vertex has a neighbor and if that neighbor has not been visited yet then we will add it to the queue and mark it as visited
            {
                visited[i]=1;

                queue[++rear]=i; // marking the neighbor as visited and adding it to the queue
            }
        }
    }
}

int main()
{
    printf("BFS Traversal\n");

    BFS(0);

    return 0;
}