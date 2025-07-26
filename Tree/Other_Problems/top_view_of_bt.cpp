//Top View of Binary Tree

/*
    Problem Statement:
    You are given a binary tree, and your task is to return its top view. 
    The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

    Note: 

    Return the nodes from the leftmost node to the rightmost node.
    If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
*/

/*
    Approach:
        1. We will use a map to store the nodes at each horizontal distance from the root.
        map<int, int> topViewMap; // key: horizontal distance, value: node value
        //horizontal distance is defined as the distance from the root node, 
        //where left child decreases the distance by 1 and right child increases it by 1.


        2. create a vector to store the result.
        vector<int> result;

        3. if the root is null, return an empty vector.
        if (root == NULL) return result;

        4. create a queue to perform level order traversal of the tree.
        queue<pair<TreeNode*, int>> q; // pair of node and its horizontal distance
        q.push({root, 0}); // push the root node with horizontal distance 0

        5. while the queue is not empty, we will process each node:
            - take the front node from the queue and its horizontal distance.
            - if the horizontal distance is not already in the map, add it to the map with the node's value.
            - if the node has a left child, push it into the queue with horizontal distance -1.
            - if the node has a right child, push it into the queue with horizontal distance +1.
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int hd = it.second; // horizontal distance

            // If this horizontal distance is not already in the map, add it
            if (topViewMap.find(hd) == topViewMap.end()) {
                topViewMap[hd] = node->val;
            }

            // Push left child with horizontal distance -1
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            // Push right child with horizontal distance +1
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }
        // Now we need to prepare the result from the map.
        for (auto it : topViewMap) {
            result.push_back(it.second); // push the node value into the result vector
        }
        return result;
*/
/*
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of nodes in the binary tree. 
      We visit each node exactly once during the level order traversal.
    - Space Complexity: O(N), for storing the nodes in the queue and the map.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



vector<int> topview(TreeNode* root){
    map<int,int> topviewMap; //key: horizontal distance, value: node value
    vector<int> result;
    if(root == NULL) return result; // If root is null, return empty vector
    queue<pair<TreeNode*, int>>q; // pair of node and its horizontal distance
    q.push({root,0}); // Push root with horizontal distance 0

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node= it.first;
        int hd = it.second; // horizontal distance
        // If this horizontal distance is not already in the map, add it
        if(topviewMap.find(hd)== topviewMap.end()){
            topviewMap[hd] = node->val; // Add node value to the map
        }

        // Push left child with horizontal distance -1
        if(node->left){
            q.push({node->left, hd-1});
        }
        // Push right child with horizontal distance +1
        if(node->right){
            q.push({node->right, hd+1});
        }
    }
    // Now we need to prepare the result from the map.
    for(auto it: topviewMap){
        result.push_back(it.second); // push the node value into the result vector
    }
    return result;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<int> topView = topview(root);
    
    for (int val : topView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}   



