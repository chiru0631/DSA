//543. Diameter of Binary Tree

/*
    Problem Statement:
    Given the root of a binary tree, return the length of the diameter of the tree.

    The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
    This path may or may not pass through the root.

    The length of a path between two nodes is represented by the number of edges between them.
*/

/*
    fucntions parameters:
    - Node* root: Pointer to the root of the binary tree.
    - int diameter: Reference variable to store the diameter of the tree.

    Approach:
    1. Use a recursive function to calculate the height of the tree.
    2. check if the root is null, if it is, return 0.
    3. create two variables to store the height of left and right subtrees.
    4. recursively call the function for left and right subtrees to get their heights.
       - lh = height(root->Left, diameter);
       - rh = height(root->Right, diameter);
    5. update the diameter with the maximum of the current diameter and the sum of left and right heights.
       - diameter = max(diameter, lh + rh);
    6. return the height of the current node.
       - return 1 + max(lh, rh);
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* Left;
    Node* Right;
    Node(int val) {
        data = val;
        Left = NULL;
        Right = NULL;
    }
};

int height(Node* root, int& diameter){
    if(root==NULL) return 0;

    int lh=height(root->Left, diameter);
    int rh=height(root->Right, diameter);

    diameter= max(diameter, lh+rh);
    // Return the height of the current node

    return 1+ max(lh,rh);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl; // Output: 3

    return 0;
}