#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <limits.h>
using namespace std;

int findMinVertex(int *weights,bool *&visited,int nodes)
{
    int minVertex = -1;
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false && (minVertex==-1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **graph,int nodes,int n_edges)
{
    //data structure to be used
    int  *parent = new int[nodes];
    bool *visited = new bool[nodes];
    int *weights = new int[nodes];

    for(int i=0;i<nodes;i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    //suppose start vertex = 0;
    parent[0] = -1;
    weights[0] = 0;

    for(int i=0;i<nodes;i++)
    {
        //find min vertex
        int minVertex = findMinVertex(weights,visited, nodes);
        visited[minVertex] = true;
        //explore unvisited neighbours
        for(int j=0;j<nodes;j++)
        {
            if(graph[minVertex][j]!=0 && visited[j]==false)
            {
                if(graph[minVertex][j] < weights[j])
                {
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }

    }

    for(int i=1;i<nodes;i++)//skipping the source
    {
        if(parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}
int main()
{
    //storing wighted graph in matrix
    int nodes,n_edges;
    cin >> nodes >> n_edges;

    int **graph = new int*[nodes];
    for(int i=0;i<nodes;i++)
    {
        graph[i] = new int[nodes];
        for(int j=0;j<nodes;j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<n_edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }
    

    cout << "the PRIM'S MST of the following graph is : " << endl;
    prims(graph,nodes,n_edges);
}