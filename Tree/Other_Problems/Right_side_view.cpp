//Binary Tree Right Side View

/*
    Problem Statment:
    Given the root of a binary tree, imagine yourself standing on the right side of it, 
    return the values of the nodes you can see ordered from top to bottom.
*/

/*
    Approach:
        1. we will perform recursive traversal of the tree.

        we will use reverse of preorder traversal to get the right side view of the tree.

        2. create a vector to store the result.
        vector<int> result;

        3. create a recursive function that takes the root node, current level, and result vector as parameters.
        void rightSideViewUtil(TreeNode* root, int level, vector<int>& result) {
            if (root == NULL) return;
            if (level == result.size()) {
                result.push_back(root->val);
            }
            rightSideViewUtil(root->right, level + 1, result);
            rightSideViewUtil(root->left, level + 1, result);
        }
    
        4. call the recursive function with the root node, level 0, and result vector.
        rightSideViewUtil(root, 0, result);

        return result;
    }

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void rightSideViewUtil(TreeNode* root, int level, vector<int>& result) {
    if (root == NULL) return;
    // If this is the first node of this level, add it to the result
    if (level == result.size()) {
        result.push_back(root->val);
    }
    // First traverse the right subtree, then the left subtree
    rightSideViewUtil(root->right, level + 1, result);
    rightSideViewUtil(root->left, level + 1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    rightSideViewUtil(root, 0, result);
    return result;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> rightView = rightSideView(root);
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
