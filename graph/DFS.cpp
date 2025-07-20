//Depth first search (DFS) algorithm implementation in C++

/*
    Datastructure used : 
        recursion stack for DFS
        vector to store the graph as an adjacency list
        vector<int> visited to keep track of visited nodes
*/

/*
        Approach:
        given a graph in the form of an adjacency list.
        we will perform DFS traversal starting from the first node (0).

        dfs(0, graph, visited, dfsTraversal);
        1. mark the current node as visited.
        push the current node into the dfsTraversal vector.
        2. iterate through the adjacency list of the current node.
        for (auto it : graph[node]) {
            if (visited[it] == -1) { // if the node is not visited
                dfs(it, graph, visited, dfsTraversal);
            }
        }

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> dfs(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> visited(n, -1); // -1 means not visited
    vector<int> dfstraversalstack;
    dfstraversal(0, adj, visited, dfstraversalstack);
    return dfstraversalstack;
}

void dfstraversal(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfstraversalstack) {
    visited[node]=1; // mark the current node as visited
    dfstraversalstack.push_back(node); // push the current node into the dfsTraversal vector
    for(auto it : adj[node]){
        if(visited[it]==-1){
            dfstraversal(it, adj, visited, dfstraversalstack); // recursively call dfs for the adjacent node
        }
    }
}

int main() {
    int n, m; // n: number of vertices(NODES), m: number of edges(LINK)
    cin >> n >> m;
    
    vector<vector<int>> graph(n); // using 0-based indexing for vertices
    
    for (int i = 0; i < m; i++) {
        int u, v; // edge from u to v
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // assuming undirected graph
    }
    
    vector<int> dfsResult = dfs(graph);
    
    // Output the DFS traversal
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
