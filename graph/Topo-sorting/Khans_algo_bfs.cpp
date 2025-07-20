// toposort using BFS (Kahn's Algorithm)

/*

    example:
    Input: n = 6, edges = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]
    Output: [5, 4, 2, 3, 1, 0]
    Approach
    1. Create a vector to store the in-degree of each node.
       - in-degree is the number of edges directed towards a node.
       - in-degree of example: [2, 2, 1, 1, 0, 0]

       for i=0 to n-1:
           for auto it: adj[i]:
               in_degree[it]++;
    2. Create a queue to store the nodes with in-degree 0.
    3. iterate through the in-degree vector and push the nodes with in-degree 0 into the queue.
       - for i=0 to n-1:
           if in_degree[i]==0:
               q.push(i);
    4. Create a vector to store the topological sort.
       vector<int> topo;
    5. While the queue is not empty:
        - pop the front element from the queue and push it into the topological sort vector.
        - for each adjacent node of the popped node, decrease its in-degree by 1.
        - if the in-degree of the adjacent node becomes 0, push it into the queue.
        - repeat until the queue is empty.
    6. Return the topological sort vector.


    dry run:
    Input: n = 6, edges = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]
    Output: [5, 4, 2, 3, 1, 0]
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
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> khansAlgorithm(int n, vector<vector<int>>& adj){
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> adj(n);
    
    // Example graph edges
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> topo = khansAlgorithm(n, adj);

    cout << "Topological Sort: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}