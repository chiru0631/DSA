//226. Invert Binary Tree

/*
    Problem Statement:
        Given the root of a binary tree, invert the tree, and return its root.
*/
/*
    Approach:
        u need 2 functions:
        1. invertTree: This function will recursively invert the binary tree.
        2. main: This function will create a binary tree and call the invertTree function

        1. In the invertTree function:
            - If the root is null, return null.
            - Swap the left and right children of the root.
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;
            - Recursively call invertTree on the left and right children.
              invertTree(root->left);
              invertTree(root->right);
            - Return the root.

        

    Time Complexity: O(n), where n is the number of nodes in the binary tree.
    Space Complexity: O(h), where h is the height of the tree, for the recursion stack.


*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL; // Base case: if the node is null, return null
    // Swap the left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recursively invert the left and right subtrees
    invertTree(root->left);
    invertTree(root->right);
    return root; // Return the inverted tree
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // Invert the binary tree
    TreeNode* invertedRoot = invertTree(root);
    
    // Output the inverted tree (for demonstration purposes)
    cout << "Inverted Root: " << invertedRoot->val << endl; // Should print 1
    cout << "Left Child: " << invertedRoot->left->val << endl; // Should print 3
    cout << "Right Child: " << invertedRoot->right->val << endl; // Should print 2
    
    return 0;
}