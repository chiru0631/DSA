//207. Course Schedule

// https://leetcode.com/problems/course-schedule/

/*
Problem Statement:
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    You are given an array prerequisites where prerequisites[i] = [ai, bi]
    indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

/*
    we have to use dfs traversal to solve this problem.
    you require 2 functions:
    1. dfs function to traverse the graph and check if there is a cycle in the graph.
    2. canFinish function to check if all courses can be finished.

*/

/*
    Approach:
         canFinish function:
        1. create a visited vector to keep track of visited nodes.
        2. given a graph convert the prerequisites into an adjacency list.
            vector<vector<int>> adj(numCourses);// adjacency list representation of the graph , numCourses is the number of courses
            for(auto it : prerequisites) {
                adj[it[1]].push_back(it[0]); // add the edge from bi to ai
            }
        3. create path vector to keep track of the path.
        4. iterate through all the courses and call dfs function for each course.
        5. if dfs returns true, then return false.
        6. if all courses are visited, then return true.
    

    dfs function:
        1. mark the current node as visited
        2. mark the path vector with 1
        3. iterate through the adjacency list of the current node.
        4. if the adjacent node is not visited, call dfs function for the adjacent node.
        5. else if path vector contains the adjacent node, then return true (cycle found).
        6. remark the path vector with 0 for the current node.
        7. return false if no cycle is found.

    time complexity: O(V + E) where V is the number of vertices and E is the number of edges
    space complexity: O(V) for the visited array and recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses); // adjacency list representation of the graph numCourses are the nodes

    for(auto it : prerequisites){
        adj[it[1]].push_back(it[0]); // add the edge from bi to ai
    }

    vector<int> visited(numCourses,0); // visited array to keep track of visited nodes
    vector<int> path(numCourses,0); // path array to keep track of the path
    for(int i=0; i<numCourses; i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, path)) return false; // if cycle is found
        }
    }

    return true; // all courses can be finished
}

bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
    visited[node]=1;
    path[node]=1;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it,adj, visited, path);

        }else if(path[it]){
            return true; // cycle found
        }

    }
    path[node]=0;
    return false;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}}; // to take course 1, you must take course 0 first
    bool result = canFinish(numCourses, prerequisites);
    cout << (result ? "True" : "False") << endl; // Output: True
    return 0;
}   

