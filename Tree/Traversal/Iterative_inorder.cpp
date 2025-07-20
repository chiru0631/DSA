//Iterative Inorder Traversal of a Binary Tree

/*
    This is an iterative function that traverses the tree in inorder fashion.
    It uses a stack to keep track of nodes to visit.
    The function prints the data of each node as it visits them.
*/

/*
    Approach:
        1. Check if the root is null, if it is, return an empty vector.
        2. Create a stack to store nodes to visit.
        3. Create a current pointer and set it to the root.
        4. While the current pointer is not null or the stack is not empty:
            - If the current pointer is not null:
                - Push it into the stack.
                - Move the current pointer to its left child.
            - If the current pointer is null and the stack is not empty:
                - Pop the top node from the stack.
                - Push its data into the result vector.
                - Move the current pointer to its right child.
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

vector<int> inorder_iterative(Node* root) {
    vector<int> result;
    if (root == NULL) return result;

    stack<Node*> st;
    Node* current = root;

    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->Left; // move to the left child
        }
        current = st.top();
        st.pop();
        result.push_back(current->data); // process the node
        current = current->Right; // move to the right child
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

    vector<int> result = inorder_iterative(root); // should print 4 2 5 1 6 3 7
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
