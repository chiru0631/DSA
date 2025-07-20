//significes level vise traversal

/*
    Data Structures used:
    - Queue- for level order traversal
    - Vector- to store the graph as an adjacency list
    - vector<bool>- to keep track of visited nodes
*/

/*
        Approach:
        1. we will be given a graph in the form of an adjacency list.
        2. take the no of vertices (node) from the given adjacency list.
        3. take the no of edges (link) from the given adjacency list.

        create a vector of vector to store visited nodes.
        vector<int> vistited(n,-1); // -1 means not visited

        MARK vector[0]=1;
        create a queue and push the first node into it.

        create a vector to store bfs traversal.
        vector<int> bfsTraversal;

        4. while the queue is not empty, pop the front node and print it.
        node= queue.front();
        queue.pop();

        push the node into bfsTraversal vector.

        5. iterate through the adjacency list of the node.
        for (auto it : graph[node]) {
            if (visited[it] == -1) {
                visited[it] = 1; // mark the node as visited
                queue.push(it); // push the node into the queue
            }
        }
        
        6. repeat step 4 and 5 until the queue is empty.
        7. print the bfsTraversal vector.
        for (auto it : bfsTraversal) {
            cout << it << " ";
        }
        cout << endl;

*/

/*
    time complexity: O(V + E) where V is the number of vertices and E is the number of edges
    space complexity: O(V) for the queue and visited vector
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> visited(n, -1); // -1 means not visited
    visited[0]=1; // mark the first node as visited

    queue<int> q;
    q.push(0); // push the first node into the queue

    vector<int> bfsTraversal; // to store bfs traversal
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfsTraversal.push_back(node); // push the node into bfsTraversal vector
        for(auto it:graph[node]){
            if(visited[it]==-1){ // if the node is not visited
                // mark the node as visited and push it into the queue
                visited[it]=1; // mark the node as visited
                q.push(it); // push the node into the queue
            }

        }
    }
    return bfsTraversal;
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

    vector<int> bfsResult = bfs(graph);

    // Output the BFS traversal
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}