/*
Given a undirected Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.
*/

/*
    Approach:
    1. we will use bfs traversal to traverse the graph.
    2. we will use a visited vector to keep track of visited nodes.
    3. we will use a queue to perform bfs traversal. queue will be a pair of node and parent.
       - node is the current node we are visiting.
       - parent is the node from which we came to the current node.
    4. we will start from the first node (0) and mark it as visited.
    5. we will iterate through the adjacency list of the current node.
    6. if the adjacent node is not visited, we will mark it as visited and
         push it into the queue.
    7. if the adjacent node is already visited and it is not the parent of the current node, then we have found a cycle.
    8. if we reach the end of the queue and have not found any cycle, then we return false.


    time complexity: O(V + E) where V is the number of vertices and E is the number of edges
    space complexity: O(V) for the visited array and the queue


*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycle(int V, vector<vector<int>> &adjlist){
    vector<int>vis(V,0); // visited array to keep track of visited nodes
    queue<pair<int,int>> q;// first element is the node and second element is the parent of the node
    q.push({0, -1}); // start from the first node (0) with parent as -1
    vis[0]=1;
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it: adjlist[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it, node});
            }else if(it != parent){
                return true; // found a cycle
            }
            
        }
    }
    return false; // no cycle found
}

int main() {
    int V = 4; // V: number of vertices
    vector<vector<int>> adjlist={
        {1, 2}, // edges from vertex 0
        {0, 2}, // edges from vertex 1
        {0, 1, 3}, // edges from vertex 2
        {2} // edges from vertex 3
    };

    
    if (isCycle(V, adjlist)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }
    //output: Graph contains a cycle
    return 0;
}