/*
    Problem Statment:
    Given a binary tree, an array where elements represent the bottom view of the binary tree from left to right.

    Note: If there are multiple bottom-most nodes for a horizontal distance from the root, 
    then the latter one in the level traversal is considered.
*/
/*
   Approach:
    1. we will use a map to store the nodes at each horizontal distance from the root.
    map<int, int> bottomViewMap; // key: horizontal distance, value: node value
    // horizontal distance is defined as the distance from the root node,
    // where left child decreases the distance by 1 and right child increases it by 1.

    2. create a vector to store the result.
    vector<int> result;

    3. if the root is null, return an empty vector.
    if (root == NULL) return result;

    4. create a queue to perform level order traversal of the tree.
    queue<pair<TreeNode*, int>> q; // pair of node and its horizontal distance

    5. push the root node into the queue with horizontal distance 0.
    q.push({root, 0}); // push the root node with horizontal distance 0

    6. while the queue is not empty, we will process each node:
       - take the front node from the queue and its horizontal distance.
       - update the map with the node's value at its horizontal distance.
       - if the node has a left child, push it into the queue with horizontal distance -1.
       - if the node has a right child, push it into the queue with horizontal distance +1.

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int hd = it.second; // horizontal distance

        // Update the map with the node's value at its horizontal distance
        bottomViewMap[hd] = node->val;

        // Push left child with horizontal distance -1
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        // Push right child with horizontal distance +1
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }
    
    7. Now we need to prepare the result from the map.
    for (auto it : bottomViewMap) {
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

#include<iostream>
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

vector<int> bottomView(TreeNode* root){
    map<int, int> bottomViewMap; // key: horizontal distance, value:node value
    vector<int> result;
    if(root == NULL) return result; // If root is null, return empty vector
    queue<pair<TreeNode*, int>> q; // pair of node and its horizontal distance
    q.push({root, 0}); // push the root node with horizontal distance 0

    while(!q.empty()){
        auto it= q.front();
        q.pop();
        TreeNode* node=it.first;
        int hd=it.second; // horizontal distance
        bottomViewMap[hd]=node->val; // Update the map with the node's value at its horizontal distance
        // Push left child with horizontal distance -1
        if(node->left){
            q.push({node->left, hd - 1});
        }
        // Push right child with horizontal distance +1
        if(node->right){
            q.push({node->right, hd + 1});
        }
    }

    for(auto it: bottomViewMap){
        result.push_back(it.second);
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
    
    vector<int> bottomViewResult = bottomView(root);
    
    for(int val : bottomViewResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
