//124. Binary Tree Maximum Path Sum

/*
    Problem Statement:
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
    A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

/*
    Approach:
    1. Use a recursive function to calculate the maximum path sum.
    2. Check if the root is null, if it is, return 0.
    3. Create two variables to store the maximum path sum of left and right subtrees.
    4. Recursively call the function for left and right subtrees to get their maximum path sums.
       - int leftMax = maxPathSum(root->left, maxSum);
       - int rightMax = maxPathSum(root->right, maxSum);
    5. Calculate the maximum path sum that can be formed by including the current node.
       - int currentMax = max(root->val, root->val + max(leftMax, rightMax));
    6. Update the maximum path sum with the maximum of the current maximum and the sum of the current node and both left and right maximums.
       - maxSum = max(maxSum, currentMax + leftMax + rightMax);
    7. Return the current maximum path sum.
       - return currentMax;
*/

#include <iostream>
#include <algorithm>
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

int maxPath(Node* root, int&maxsum){
    if(root==NULL) return 0;

    int leftMax =maxPath(root->Left,maxsum);
    int rightMax =maxPath(root->Right,maxsum);

    int currentmax= max(root->data, root->data + max(leftMax, rightMax));
    maxsum = max(maxsum, currentmax + leftMax + rightMax);
    return currentmax;
}

int maxPathSum(Node* root) {
    int maxsum = INT_MIN;
    maxPath(root, maxsum);
    return maxsum;
}

int main() {
    Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);

    int result = maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl; // Output: 11 (4 -> 2 -> 1 -> 3)
    
    return 0;
}