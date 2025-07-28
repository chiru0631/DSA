// Dijkstra.cpp

// Dijkstra's algorithm  is used to find the shortest path from a source node to all other nodes in a directed graph with non-negative weights.

// we can also use it for undirected graphs by treating each undirected edge as two directed edges with the same weight.

/*
    PROBLEM STATEMENT:
    Given a directed graph with V vertices and E edges, where each edge has a weight,
    find the shortest path from a source vertex to the nth vertex using Dijkstra's algorithm.
*/

/*
    Approach:
    1. Create an adjacency list to represent the graph.
       vector<vector<pair<int, int>>> adj(V); // Adjacency list where each pair contains (destination, weight)

    2. create the adjacency list from the edges.
       for (const auto &edge : edges) {
           int u = edge[0];
           int v = edge[1];
           int w = edge[2];
           adj[u].push_back({v, w});
       }
    3. Create a priority queue to store the vertices based on their distance from the source.
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    4. Create a vector to store the shortest distances from the source vertex.
       vector<int> dist(V, INT_MAX);

    5. Create a parent vector to store the parent of each vertex in the shortest path.
       vector<int> parent(V+1, -1);

    6. Initialize the parent vector by itsself.
       for (int i = 0; i < V; i++) {
           parent[i] = i;
       }
    dist[1]=0; // Distance from source to itself is 0// its 1 based indexing
    7. Push the source vertex into the priority queue with distance 0.
       pq.push({0, 1}); // {distance, vertex}
    
    8. While the priority queue is not empty:
       while (!pq.empty()) {
           auto [d, node] = pq.top();
           pq.pop();

           // If the distance is greater than the current distance, skip it.
           if (d > dist[node]) continue;

           // Iterate through the neighbors of the current node.
           for (const auto &neighbor : adj[node]) {
               int nextNode = neighbor.first;
               int weight = neighbor.second;

               // If a shorter path to the neighbor is found, update the distance and parent.
               if (dist[node] + weight < dist[nextNode]) {
                   dist[nextNode] = dist[node] + weight;
                   parent[nextNode] = node; // Update parent
                   pq.push({dist[nextNode], nextNode});
               }
           }
       }

    9. If the distance to the nth vertex is still INT_MAX, it means it is unreachable, so set it to -1.
       if (dist[V] == INT_MAX) {
           return {-1};
       }

    10. create a vector to store the shortest path from the source to the nth vertex.
        vector<int> path;
        int node= n;// the destination node
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // Add the source node
        reverse(path.begin(), path.end()); // Reverse the path to get it from source to destination
        return path;
    }
*/

/*
    Time Complexity: O((V + E) log V)
    Space Complexity: O(V + E) for the adjacency list and O(V) for the distance and parent vectors.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>// for std::pair
#include <limits.h>// for INT_MAX
#include <algorithm> // for std::reverse
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>>& edges, int src){
    vector<vector<pair<int,int>>> adj(V+1); // Adjacency list where each pair contains (destination, weight)
    for(auto it: edges){
        int u= it[0];
        int v= it[1];
        int w= it[2];
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq; // Min-heap priority queue

    vector<int> dist(V+1, INT_MAX); // Distance vector initialized to INT_MAX
    vector<int> parent(V+1, -1); // Parent vector to store the path

    for(int i=0; i<=V; i++){
        parent[i]=i; // Initialize parent vector
    }
    dist[src]=0; // Distance from source to itself is 0
    pq.push({0, src}); // Push the source vertex into the priority queue with distance 0
    while(!pq.empty()){
        auto it= pq.top();
        pq.pop();
        //int d= it.first; // Current distance
        int node= it.second; // Current node

        for(auto it: adj[node]){
            int nextNode= it.first;
            int weight= it.second;
            if(dist[node] + weight < dist[nextNode]){ // If a shorter path is found
                dist[nextNode] = dist[node] + weight; // Update distance
                parent[nextNode] = node; // Update parent
                pq.push({dist[nextNode], nextNode}); // Push the updated node into the priority queue
            }
        }
    }

    if(dist[V] == INT_MAX){ // If the destination is unreachable
        return {-1}; // Return -1
    }

    vector<int> path; // Vector to store the shortest path
    int node = V; // Start from the destination node
    while(parent[node] != node){ // While the parent is not itself
        path.push_back(node); // Add the current node to the path
        node = parent[node]; // Move to the parent node
    }
    path.push_back(src); // Add the source node
    reverse(path.begin(), path.end()); // Reverse the path to get it from source to destination
    return path;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };
    int src = 1; // Source vertex

    vector<int> shortestPath = dijkstra(V, edges, src);
    
    cout << "Shortest path from source to destination: ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}