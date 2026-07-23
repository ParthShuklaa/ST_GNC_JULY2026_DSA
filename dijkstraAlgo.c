//dijkstra algo for finding shortest distance 
#include<stdio.h>

#define V 4
#define INF 9999

int main()
{
    int graph[V][V]=
    {
        {0,4,2,0},
        {4,0,1,5},
        {2,1,0,3},
        {0,5,3,0}
    };

    int dist[V]={0,INF,INF,INF}; // all distances are initialized to infinity except for the source vertex (vertex 0) which is initialized to 0
    int visited[V]={0};

    for(int count=0;count<V;count++)
    {
        int min=INF;
        int u=-1;

        // Find minimum distance vertex
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && dist[i]<min) // if the vertex is not visited and its distance is less than the current minimum distance, we update the minimum distance and the vertex index
            {
                min=dist[i];
                u=i;
            }
        }

        visited[u]=1;

        // Update neighbours
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 &&
               !visited[v] &&
               dist[u]+graph[u][v]<dist[v]) // here we are checking if the vertex v is a neighbor of u (i.e., there is an edge between u and v), if v has not been visited yet, and if the distance to v through u is less than the current known distance to v. If all these conditions are met, we update the distance to v
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Shortest Distance from Vertex 0\n\n");

    for(int i=0;i<V;i++)
        printf("0 -> %d = %d\n",i,dist[i]);

    return 0;
}