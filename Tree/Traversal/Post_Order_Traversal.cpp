//Post Order Traversal of a Binary Tree

/*
    This is a recursive function that traverses the tree in postorder fashion.
    It first visits the left subtree, then the right subtree, and finally the root node.
    let root->Left->Right be the left child of the root node.
    The function prints the data of each node as it visits them.
*/

/*
    Approach:
        1. Check if the node is null, if it is, return.
        
        2. Recursively call the left child.
        3. Recursively call the right child.
        4. Print the root node.
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


void postorder(Node* root){
    if(root == NULL) return; // base case: if the node is null, return

    postorder(root->left); // recursively call the left child
    postorder(root->right); // recursively call the right child
    cout << root->data << " "; // print the root node

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Postorder Traversal: ";
    postorder(root); // should print 4 5 2 6 7 3 1
    cout << endl;

    return 0;
}