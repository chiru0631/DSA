//Tree Boundary Traversal

/*
    Problem Statement:
        Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

        Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. 
        You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

        Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

        Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, 
        traversed in reverse order. You must prefer the right child over the left child when traversing. 
        Do not include the root in this section if it was already included in the left boundary.
*/

/*
    Approach:
        so we will use inorder traversal to find the left boundary, leaf nodes, and right boundary.
        we will use stack to store the right boundary nodes in reverse order.

        we will be using 4 functions:
        1. leftBoundary: to traverse the left boundary of the tree.
        2. leafNodes: to traverse the leaf nodes of the tree.
        3. rightBoundary: to traverse the right boundary of the tree in reverse order.
        4. boundaryTraversal: to combine all three traversals and return the final boundary traversal.

        boundaryTraversal function will:
        1. create a vector to store the boundary traversal.
        2.check if the root is null, if yes return an empty vector.
        3. check if not is leaf node, if yes add it to the boundary vector.
           return {root->val};

        4. call leftBoundary function to traverse the left boundary.
        5. call leafNodes function to traverse the leaf nodes.
        6. call rightBoundary function to traverse the right boundary in reverse order.
        7. return the boundary vector.

        leftBoundary function will:
           1. create a node pointer current and initialize it with the root's left child.
              2. while current is not null:
                  - if current is not a leaf node, 
                    add current's value to the boundary vector.
                  - if current has a left child, move to the left child, else move to the right child.
            
        leafNodes function will:
            1. check if the current node is null, if yes return.
            2. if current is a leaf node, add its value to the boundary vector.

            3. check if current has a left child, if yes call leafNodes function on the left child.
            4. check if current has a right child, if yes call leafNodes function on the right child.
        
        rightBoundary function will:
            1. create a node pointer current and initialize it with the root's right child.
            2. create a stack to store the right boundary nodes.
            3. while current is not null:
                - if current is not a leaf node, push its value onto the stack.
                - if current has a right child, move to the right child, else move to the left child.
            4. pop all elements from the stack and add them to the boundary vector.

        check if the root is a leaf node.
         if(root->left == NULL && root->right == NULL) {
            return {root->val};
}




*/
/*
    Time Complexity: O(n), where n is the number of nodes in the binary tree.
    Space Complexity: O(h), where h is the height of the tree, for the recursion stack.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    // Utility to check if a node is a leaf
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }

    // Add left boundary (excluding leaves)
    void addLeftNodes(Node* root, vector<int>& result) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) result.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    // Add all leaf nodes (from left to right)
    void addLeafNodes(Node* root, vector<int>& result) {
        if (isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        if (root->left) addLeafNodes(root->left, result);
        if (root->right) addLeafNodes(root->right, result);
    }

    // Add right boundary (excluding leaves, in reverse)
    void addRightNodes(Node* root, vector<int>& result) {
        Node* cur = root->right;
        stack<int> st;
        while (cur) {
            if (!isLeaf(cur)) st.push(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    }

  public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> result;
        if (root == NULL) return result;

        if (!isLeaf(root)) result.push_back(root->data);  // Add root only if it's not a leaf
        addLeftNodes(root, result);
        addLeafNodes(root, result);
        addRightNodes(root, result);
        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    Solution sol;
    vector<int> boundary = sol.boundaryTraversal(root);

    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
