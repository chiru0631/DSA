// Course 1 and 2 Topological Sorting

/*
    Problem Statment:
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    You are given an array prerequisites where prerequisites[i] = [ai, bi]
    indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.
*/

/*

    using Kahn's Algorithm (BFS) for Topological Sorting:
    Approach:
    1. Create a vector to store the in-degree of each node.
       - in-degree is the number of edges directed towards a node.
    2. Iterate through the prerequisites array and update the in-degree of each node.
       - for i=0 to n-1:
           for auto it: prerequisites[i]:
               in_degree[it]++;
    3. Create a queue to store the nodes with in-degree 0.
    4. Iterate through the in-degree vector and push the nodes with in-degree 0 into the queue.
       - for i=0 to n-1:
           if in_degree[i]==0:
               q.push(i);

    5. Create a vector to store the topological sort.
       vector<int> topo;
    6. While the queue is not empty:
        - Pop the front element from the queue and push it into the topological sort vector.
        - For each adjacent node of the popped node, decrease its in-degree by 1.
        - If the in-degree of the adjacent node becomes 0, push it into the queue.
        - Repeat until the queue is empty.
    7. If the size of the topological sort vector is not equal to n, return false (cycle exists).
       return true;
    

    Dry Run:
    Input: numCourses = 2, prerequisites = [[1, 0]]
    Output: true
    in-degree: [0, 1]
    Queue: [0]
    Topological Sort: []
    1. Push 0 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [0]
       - Decrease in-degree of 1 by 1.
       - in-degree: [0, 0]
       - Queue: [1]
    2. Push 1 into the queue, pop it and push it into the topological sort vector.
       - Topological Sort: [0, 1]
       - Decrease in-degree of 0 by 1.
       - in-degree: [0, 0]
       - Queue: []
    3. Return true since the size of the topological sort vector is equal to numCourses.
*/

/*
    Time Complexity: O(V + E) where V is the number of vertices (courses) and E is the number of edges (prerequisites)
    Space Complexity: O(V) for the in-degree vector and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canfinish(int numCourses,vector<vector<int>>& prerequisites){
    vector<int>indegree(numCourses,0);
    for(int i=0;i<numCourses;i++){
        for(auto it: prerequisites[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:prerequisites[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo.size()==numCourses;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    
    if (canfinish(numCourses, prerequisites)) {
        cout << "You can finish all courses." << endl;
    } else {
        cout << "You cannot finish all courses." << endl;
    }
    
    return 0;
}