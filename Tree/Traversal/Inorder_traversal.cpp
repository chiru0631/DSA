//Inorder Traversal
/*
    
    this follows the left-root-right order
    go to the extreme left node, then print the root, and finally go to the right node
    this is a recursive function that traverses the tree in inorder fashion


*/

/*
    Approach:
        1.check if the node is null, if it is, return.
        
        2. recursively call the left child.
        3. print the root node.
        4. recursively call the right child.
        5. return from the function.

*/

/*
    Time Complexity: O(n) where n is the number of nodes in the tree.
    Space Complexity: O(h) where h is the height of the tree due to recursion stack
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* Left;
    Node* Right;
    Node(int val){
        data = val;
        Left = NULL;
        Right = NULL;
    }
};

void inorder(Node* root){
    if(root==NULL) return; // base case: if the node is null, return
    inorder(root->Left); // recursively call the left child
    cout << root->data << " "; // print the root node
    inorder(root->Right); // recursively call the right child


}

int main() {
    Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);
    root->Right->Left = new Node(6);
    root->Right->Right = new Node(7);

    cout << "Inorder Traversal: ";
    inorder(root); // should print 4 2 5 1 6 3 7
    cout << endl;

    return 0;
}
