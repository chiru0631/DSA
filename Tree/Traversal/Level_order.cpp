//Level Order Traversal of a Binary Tree

/*
    This is a iterative function that traverses the tree in level order fashion.
    It uses a queue to keep track of nodes at each level.
    The function prints the data of each node as it visits them.
*/

/*
    Approach:
        1. declare a queue to store the nodes at each level.
        2. create a vector of vectors to store the level order traversal.
        if the root is null, return an empty vector.
        3. push the root node into the queue.
        4. while the queue is not empty:
            - get the size of the queue (number of nodes at the current level).
            - create a vector to store the nodes at the current level.
            - for each node at the current level:
                - pop the front node from the queue.
                - push its data into the current level vector.
                - if it has a left child, push it into the queue.
                - if it has a right child, push it into the queue.
            - push the current level vector into the result vector.
*/

/*
    Time Complexity - O(n) where n is the number of nodes in the tree.
    Space Complexity - O(n) for the queue and the result vector.
    
*/

#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelorder(Node* root){
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int> currlevel;
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            currlevel.push_back(node->data);
            if(node->Left) q.push(node->Left);
            if(node->Right) q.push(node->Right);
        }
        result.push_back(currlevel);
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

    vector<vector<int>> result = levelorder(root);
    
    cout << "Level Order Traversal: " << endl;
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}