//100. Same Tree

/*
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

/*
    Approach:
        1. check if both trees are null, if yes return true.
         IF(p == NULL || q == NULL) return p == q;
        
        2. check if the values of the current nodes are equal, if not return false.
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {

    // If one of them is null, they are not the same
    if (p == NULL || q == NULL) return p == q;
    // Check if the current nodes have the same value and recursively check left and right subtrees
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Example usage
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (isSameTree(p, q)) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are not the same." << endl;
    }

    return 0;
}