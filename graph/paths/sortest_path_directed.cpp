//Sortest path in Directed Graph

/*
    Problem Statement:
    Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E,
    where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, 
    then return -1 for that vertex.
*/

/*
   Approach:
      1. Create an adjacency list to represent the graph.
         vector<vector<pair<int, int>>> adj(V);// Adjacency list where each pair contains (destination, weight)



      2. For each edge in the edges array, add the directed edge to the adjacency list.
         for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
         }

      //find topological sort of the graph
      3. Create a vector to store the topological order of the vertices.
         vector<int> topoOrder;

      4. create a stack to perform DFS and find the topological order.
         stack<int> st;
      
      5. Create a vector to keep track of visited vertices.
         vector<bool> visited(V, false);
      
      for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }
      
      create a vector to store the shortest distances from the source vertex.
      vector<int> dist(V, INT_MAX);
      dist[0] = 0; // Distance from source to itself is 0
      6. While the stack is not empty, pop the top vertex and update the distances of its neighbors.
         while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX) { // If the node is reachable
                for (const auto &neighbor : adj[node]) {
                    int nextNode = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[node] + weight < dist[nextNode]) {
                        dist[nextNode] = dist[node] + weight;
                    }
                }
            }
        }


      return dist;


      //toposort function
      void dfs(int node, vector<bool> &visited, stack<int> &st, const vector<vector<pair<int, int>>> &adj) {
          visited[node] = true;
          for (const auto &neighbor : adj[node]) {
              if (!visited[neighbor.first]) {
                  dfs(neighbor.first, visited, st, adj);
              }
          }
          st.push(node);
      }
*/

#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &st, const vector<vector<pair<int,int>>>& adj){
   visited[node]= true;
   for(auto it: adj[node] ){
      if(!visited[it.first]){
         dfs(it.first, visited, st, adj);
      }
   }
   st.push(node);
}

vector <int> solution(int V, vector<vector<int>>& edges){
   vector<vector<pair<int,int>>> adj(V);// Adjacency list where each pair contains (destination, weight)
   for(auto it:edges){
      int u= it[0];
      int v=it[1];
      int w=it[2];
      adj[u].push_back({v,w});

   }

   stack<int> st;
   vector<bool> visited(V, false);
   for(int i=0;i<V;i++){
      if(!visited[i]){
         dfs(i, visited, st, adj);
      }
   }
   vector<int> dist(V, INT_MAX);
   dist[0] = 0; // Distance from source to itself is 0
   while(!st.empty()){
      int node= st.top();
      st.pop();
      if(dist[node] != INT_MAX){ // If the node is reachable
         for(auto it: adj[node]){
            int nextNode = it.first;
            int weight = it.second;
            if(dist[node] + weight <dist[nextNode]){
               dist[nextNode] = dist[node] + weight;
            }
         }
      }
   }
   return dist;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {3, 4, 1}
    };

    vector<int> shortestPaths = solution(V, edges);
    
    cout << "Shortest paths from vertex 0:" << endl;
    for (int i = 0; i < V; i++) {
        if (shortestPaths[i] == INT_MAX) {
            cout << "Vertex " << i << ": -1" << endl; // Unreachable vertex
        } else {
            cout << "Vertex " << i << ": " << shortestPaths[i] << endl;
        }
    }

    return 0;
}