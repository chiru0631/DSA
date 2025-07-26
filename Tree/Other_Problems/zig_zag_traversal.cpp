//Binary Tree Zigzag Level Order Traversal

/*
    Problem Statement:
        Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
        (i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
    Approach:
        1. we will use a queue to perform level order traversal.
        2. we need vector of vectors to store the result.
        3. we will use a boolean flag to determine the direction of traversal for each level.
            vector<vector<int>> result;
            check id root is null, if yes return empty vector.
        4. Initialize a queue and push the root node into it.
            queue<TreeNode*> q;
            q.push(root);
        5. create a boolean variable to track the direction of traversal.
            bool leftToRight = true;
        6. While the queue is not empty, we will process each level:
            - Get the size of the current level.
            - Create a temporary vector to store the current level's values.
            - For each node in the current level, pop it from the queue and add its value to the temporary vector.
            - If the leftToRight flag is false, reverse the temporary vector before adding it to the result.
            - Push the left and right children of the current node into the queue if they exist.
        while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!leftToRight) reverse(currentLevel.begin(), currentLevel.end());
            result.push_back(currentLevel);
            leftToRight = !leftToRight; // Toggle the direction for the next level
        }


*/

/*
    Time Complexity: O(n), where n is the number of nodes in the binary tree.
    Space Complexity: O(n), for storing the result and the queue.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagtraversal(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL) return result; // If root is null, return empty vector
    queue<TreeNode*> q;
    q.push(root); // Push the root node into the queue
    bool lefttoright= true; // Direction flag for zigzag traversal
    while(!q.empty()){
        int size= q.size();// Get the size of the current level
        vector<int> currentLevel; // Temporary vector to store current level's values
        for(int i=0;i<size;i++){
            TreeNode* node=q.front(); // Get the front node of the queue
            q.pop();
            currentLevel.push_back(node->val); // Add the node's value to the current level
            if(node->left) q.push(node->left); // Push left child into the queue
            if(node->right) q.push(node->right); // Push right child into the queue

        }
        if(!lefttoright) reverse(currentLevel.begin(), currentLevel.end()); // Reverse the current level if needed
        result.push_back(currentLevel); // Add the current level to the result
        lefttoright = !lefttoright; // Toggle the direction for the next level
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

    vector<vector<int>> result = zigzagtraversal(root);
    
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}   