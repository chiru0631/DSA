/*
    Max Height of Binary Tree
    or also called as max depth of binary tree
*/

/*
    Approach:
                            I can use recursion as well as level order traversal to find the height of the binary tree.
    
        Recursion:
            1. check if the root is null, if it is, return 0.
            2. create 2 variables left and right to store the height of left and right subtrees.
            3. call the function recursively for left and right children of the root.
                 lh = height(root->Left);
                 rh = height(root->Right);
            4. return the maximum of left and right height + 1.
            5. return max(lh, rh) + 1;
        
        Traversal:
            1. check if the root is null, if it is, return 0.
            2. create a queue to store nodes at each level.
            3. push the root into the queue and initialize height to 0.
            4. while the queue is not empty:
                - increment height by 1.
                - get the size of the queue.
                - for each node in the current level, pop it from the queue and push its children into the queue.
            5. return height.
*/

#include <iostream>
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

    int max_depth_recursive(Node* root) {
        if(root == NULL) return 0;
        int lhs=max_depth_recursive(root->Left);
        int rhs=max_depth_recursive(root->Right);
        return max(lhs, rhs) + 1;
    }

    int max_depth_iterative(Node* root){
        if(root == NULL) return 0;
        queue<Node*>q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            height++;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* current=q.front();
                q.pop();
                if(current->Left != NULL) {
                    q.push(current->Left);
                }
                if(current->Right != NULL) {
                    q.push(current->Right);
                }
            }
        }
        return height;
    }

    int main() {
        Node* root = new Node(1);
        root->Left = new Node(2);
        root->Right = new Node(3);
        root->Left->Left = new Node(4);
        root->Left->Right = new Node(5);
        root->Right->Left = new Node(6);
        root->Right->Right = new Node(7);

        cout << "Max Depth (Recursive): " << max_depth_recursive(root) << endl; // should print 3
        cout << "Max Depth (Iterative): " << max_depth_iterative(root) << endl; // should print 3

        return 0;
    }