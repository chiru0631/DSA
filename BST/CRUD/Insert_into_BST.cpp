//701. Insert into a Binary Search Tree

/*
Problem Statement:
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, 
as long as the tree remains a BST after insertion. You can return any of them.
*/

/*
Approach:
1. If the root is null, create a new TreeNode with the given value and return it.
2. take the copy of the root node.
3. take a while loop to traverse the tree.
4. If the value to insert is less than the current node's value, move to the left subtree.
5. If the value to insert is greater than the current node's value, move to the right subtree.
6. If the left or right child is null, insert the new value there by creating a new TreeNode.
 while(true){
            if(cur->val<val){
                if(cur->right !=NULL) cur=cur->right;
                else{
                    cur->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }
        }
    7. Return the original root node.

    time complexity: O(h) where h is the height of the tree.
    space complexity: O(1) for the iterative approach.
*/

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    
    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left != NULL) {
                cur = cur->left;
            } else {
                cur->left = new TreeNode(val);
                break;
            }
        } else {
            if (cur->right != NULL) {
                cur = cur->right;
            } else {
                cur->right = new TreeNode(val);
                break;
            }
        }
    }
    
    return root; // Return the original root node
}
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int valToInsert = 5;
    root = insertIntoBST(root, valToInsert);

    // The tree now contains the value 5
    // You can add code to print or verify the tree structure if needed

    return 0;
}