#include<stdio.h>
#include<vector>
using namespace std;

// Function to represent a graph as an adjacency list
int main(){
    int n, m; // n: number of vertices(NODES), m: number of edges(LINK)
    scanf("%d %d", &n, &m);
    
    vector<vector<int>> graph(n + 1); // using 1-based indexing for vertices
    
    for (int i = 0; i < m; i++) {
        int u, v; // edge from u to v
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u); // assuming undirected graph
    }
    
    // Output the adjacency list representation
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j : graph[i]) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}