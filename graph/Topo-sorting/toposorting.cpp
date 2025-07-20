//Topological Sorting in C++ using DFS

/*
    topo sort exists on Directed Acyclic Graphs (DAGs) 

    definition:
    A topological sort of a directed graph is a linear ordering of its vertices such that for every directed edge u -> v, 
    vertex u comes before vertex v in the ordering.

    basically, it is a way of ordering the vertices of a directed graph such that for every directed edge u -> v,
    vertex u comes before vertex v in the ordering.
*/


/*
    Approach:
        1. create a vector to store the visited nodes.
        2. create a stack to store the topological sort.
        3. create a recursive function to perform DFS on the graph.
        for i=0 to n-1:
            - if the node is not visited, call the recursive dfs function.
        4. in the recursive function:
            - mark the node as visited.
            - for each adjacent node, if it is not visited, call the recursive function on it.
            - push the node into the stack after all its adjacent nodes are visited.
             for it in adj[node]:
                if not visited[it]:
                    dfs(it, visited, adj, st);
                st.push(node);
        
        5. after the loop, create a vector to store the topological sort.
        6. while the stack is not empty, pop the top element and push it into the vector.
            while st not empty:
                int node = st.top();
                st.pop();
                topo.push_back(node);
        7. return the vector.
*/

/*
    Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
    Space Complexity: O(V) for the visited vector and stack
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node,vector<int>& visited, vector<int> adj[],stack<int>& st){
    visited[node]=1;// mark the node as visited
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it, visited,adj,st);
        }
    }
    st.push(node);
}

vector<int> toposort(int n, vector<int> adj[]){
    vector<int> visited(n,0);
    stack<int> st;
    vector<int> topo;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }

    while(!st.empty()){
        int node=st.top();
        st.pop();
        topo.push_back(node);
    }
    return topo;
}

int main() {
    int n = 6; // Number of vertices
    vector<int> adj[6]; // Adjacency list representation of the graph

    // Example graph edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = toposort(n, adj);

    cout << "Topological Sort: ";
    for (int i : topo) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}