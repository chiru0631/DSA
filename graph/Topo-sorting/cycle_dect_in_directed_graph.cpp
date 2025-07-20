//cycle detection in directed graph using DFS

/*
    cycle detection in directed graph using khan's algorithm
    Approach:
    1. create a vector to store the in-degree of each node.
    2. iterate through the adjacency list and update the in-degree of each node.
       for i=0 to n-1:
           for auto it: adj[i]:
               in_degree[it]++;
    3. create a queue to store the nodes with in-degree 0.
    4. iterate through the in-degree vector and push the nodes with in-degree 0 into the queue.
       for i=0 to n-1:
           if in_degree[i]==0:
               q.push(i);
    5. create a vector to store the topological sort.
       vector<int> topo;
    6. while the queue is not empty:
        - pop the front element from the queue and push it into the topological sort vector.
        - for each adjacent node of the popped node, decrease its in-degree by 1.
        - if the in-degree of the adjacent node becomes 0, push it into the queue.
        - repeat until the queue is empty.
    7. if the size of the topological sort vector is not equal to n, return true (cycle exists).
       return false;
    

    dry run:
    Input: n = 6, edges = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]
    Output: true
    in-degree: [2, 2, 1, 1, 0, 0]
    Queue: [5, 4]
    Topological Sort: []

    1. Push 5 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5]
       - Decrease in-degree of 2 and 0 by 1.
       - in-degree: [1, 2, 0, 1, 0, 0]
       - Queue: [4, 2]
    2. Push 4 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5, 4]
         - Decrease in-degree of 0 and 1 by 1.
         - in-degree: [0, 1, 0, 1, 0, 0]
         - Queue: [2, 0]
    3. Push 2 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5, 4, 2]
       - Decrease in-degree of 3 by 1.
       - in-degree: [0, 1, 0, 0, 0, 0]
       - Queue: [0, 3]
    4. Push 0 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5, 4, 2, 0]
         - Decrease in-degree of 1 by 1.
         - in-degree: [0, 0, 0, 0, 0, 0]
         - Queue: [3, 1]
    5. Push 3 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5, 4, 2, 0, 3]
       - Decrease in-degree of 1 by 1.
         - in-degree: [0, 0, 0, 0, 0, 0]
         - Queue: [1]
    6. Push 1 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [5, 4, 2, 0, 3, 1]
       - Decrease in-degree of 0 by 1.
       - in-degree: [0, 0, 0, 0, 0, 0]
       - Queue: []
    7. Return the topological sort vector: [5, 4, 2, 0, 3, 1]
    8. Since the topological sort vector contains all the nodes, return false (no cycle exists).
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isCycle(int n,vector <int> adj[]) {
    vector<int> indegree(n, 0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    // If the topological sort size is not equal to n, cycle exists
    return topo.size() != n;
}

int main() {
    int n = 6;
    vector<int> adj[6]; // Adjacency list representation of the graph
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    if (isCycle(n, adj)) {
        cout << "Cycle exists in the directed graph." << endl;
    } else {
        cout << "No cycle exists in the directed graph." << endl;
    }
    
    return 0;
}