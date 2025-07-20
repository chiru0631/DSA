//Iterative Preorder Traversal of a Binary Tree

/*
    This is an iterative function that traverses the tree in preorder fashion.
    It uses a stack to keep track of nodes to visit.
    The function prints the data of each node as it visits them.
*/

/*
    Approach:
        1. Check if the root is null, if it is, return an empty vector.
        
        2. Create a stack to store nodes to visit.
        3. Push the root node into the stack.
        4. While the stack is not empty:
            - store the top node in a variable.
            - pop the top node from the stack.
            - push the data of the node into the result vector.
            - if the node has a right child, push it into the stack.
            - if the node has a left child, push it into the stack.
        5. Return the result vector.
*/


#include <iostream>
#include <vector>
#include <stack>
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

vector<int> preorder_iterative(Node* root){
    vector<int> result;
    if(root==NULL) return result;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node=st.top();
        st.pop();
        result.push_back(node->data);
        if(node->Right) st.push(node->Right); // push right child first so that left child is processed first
        if(node->Left) st.push(node->Left); // push left child into the stack
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);
    root->Right->Left = new Node(6);
    root->Right->Right = new Node(7);

    vector<int> result = preorder_iterative(root); // should return {1, 2, 4, 5, 3, 6, 7}
    
    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}