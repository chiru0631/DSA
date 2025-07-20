/*
    Shortest Path in Undirected Graph


    Problem Statment:
    You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, 
    find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
    then return -1 for that vertex.
*/

/*
    Pattern used:
    1. Use a queue to perform BFS traversal.


    Approach:
    1. Create a vector to store the distance of each node from the source.
       - vector<int> dist(n, INT_MAX);
    2. Initialize the distance of the source node to 0.
       - dist[src] = 0;
    3. Create a queue and push the source node into it.
       - queue<int> q;
       - q.push(src);
    4. While the queue is not empty:
       - Pop the front element from the queue.
       - For each adjacent node of the popped node, if the distance to the adjacent node can be shortened,
         update its distance and push it into the queue.
         - for (auto it : adj[node]) {
              if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
              }
    5. If the distance to any node is still INT_MAX, it means it is unreachable, so set it to -1.
       - for (int i = 0; i < n; i++) {
           if (dist[i] == INT_MAX) {
               dist[i] = -1;
           }
       }
    6. Return the distance vector.
       return dist;


    Dry Run:
    Input: n = 5, edges = [[0, 1], [0, 2], [1, 3], [2, 3], [3, 4]], src = 0
    Output: [0, 1, 1, 2, 3] 

    1. Initialize distance vector: dist = [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    2. Push source node 0 into the queue: q = [0]   
    3. Pop 0 from the queue, update distances of adjacent nodes 1 and 2:
       - dist = [0, 1, 1, INT_MAX, INT_MAX]
       - q = [1, 2]
    4. Pop 1 from the queue, update distance of adjacent node 3:
         - dist = [0, 1, 1, 2, INT_MAX]
         - q = [2, 3]
    5. Pop 2 from the queue, update distance of adjacent node 3:
            - dist = [0, 1, 1, 2, INT_MAX]
            - q = [3]
    6. Pop 3 from the queue, update distance of adjacent node 4:
            - dist = [0, 1, 1, 2, 3]
            - q = [4]   
    7. Pop 4 from the queue, no adjacent nodes to update.
    8. Final distance vector: [0, 1, 1, 2, 3]

*/

/*
    time complexity: O(n + m) where n is the number of nodes and m is the number of edges
    space complexity: O(n) for the distance vector and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& adj, int src){
    vector<int>distance (n,INT_MAX);
    distance[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(distance[it]>distance[node]+1){
                distance[it]=distance[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    vector<vector<int>> adj(n);
    
    // Construct the adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); // Undirected graph
    }
    
    int src = 0;
    vector<int> result = shortestPath(n, adj, src);
    
    cout << "Shortest path from source " << src << ": ";
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
