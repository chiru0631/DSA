//547. Number of Provinces

/*
Problem Statment:
    There are n cities. Some of them are connected, while some are not.
    If city a is connected directly with city b, and city b is connected directly with city c,
    then city a is connected indirectly with city c.
    A province is a group of directly or indirectly connected cities and no other cities outside of the group.
    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected,
    and isConnected[i][j] = 0 otherwise.
    Return the total number of provinces.
*/

/*
    we will be using DFS traversal to solve this problem.
    Approach:
    1. given a graph create an adjacency list from the isConnected matrix.
    for(i->v){
        for(j->v){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    2. create a variable count to keep track of the number of provinces.
    create a visited vector to keep track of visited nodes.
    3. iterate through all the nodes and call dfs function for each node.
    for(i->v){
        if(visited[i]==0){
            count++;
            dfs(i, adj, visited);
        }
    }

    return count;

    4. dfs function:
        1. mark the current node as visited.
        2. iterate through the adjacency list of current node.
        for(auto it : adj[node]){
            if(visited[it]==0){
                dfs(it, adj, visited); // recursively call dfs for the adjacent node
            }
        }
*/ 

/*Summary:
    time complexity: O(n^2) for creating the adjacency list and O(V + E) for dfs traversal
    space complexity: O(n) for the visited array and O(n) for the adjacency list
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node]=1;
    for(auto it: adj[node]){
        if(visited[it]==0){
            dfs(it,adj, visited);
        }
    }
}

int findProv(vector<vector<int>>& isConnected){
    int n=isConnected.size();
    vector<vector<int>>adj(n); // adjacency list representation of the graph
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i); // undirected graph
            }
        }
    }
    int cnt=0;
    vector<int> visited(n,0); // visited array to keep track of visited nodes
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            cnt++;
            dfs(i,adj,visited);
        }
    }

}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    int result = findProv(isConnected);
    cout << result << endl; // Output: 2
    return 0;
}

/*
    time complexity: O(n^2) for creating the adjacency list and O(V + E) for dfs traversal
    space complexity: O(n) for the visited array and O(n) for the adjacency list
*/