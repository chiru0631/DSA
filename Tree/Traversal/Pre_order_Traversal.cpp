// Pre Order Traversal of a Binary Tree

/*
    This is a recursive function that traverses the tree in inorder fashion.
    It first visits the left subtree, then the root node, and finally the right subtree.
    // root->Left->Right is the left child of the root node.
    The function prints the data of each node as it visits them.
*/

/*
    Approach:
        1. Check if the node is null, if it is, return.
        
        2. Print the root node.
        3. Recursively call the left child.
        4. Recursively call the right child.
        5. Return from the function.
*/

/*
    Time Complexity: O(n) where n is the number of nodes in the tree.
    Space Complexity: O(h) where h is the height of the tree due to recursion stack.
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return; // base case: if the node is null, return

    cout << root->data << " "; // print the root node
    preorder(root->left); // recursively call the left child
    preorder(root->right); // recursively call the right child
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder Traversal: ";
    preorder(root); // should print 1 2 4 5 3 6 7
    cout << endl;

    return 0;
}