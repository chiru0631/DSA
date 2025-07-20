/*
    Approach:
       the main idea is height(left) -height(right) <= 1

         1. check if the root is null, if it is, return true.
         2 create 2 variables to store left and right height.
            3. recursively call the function for left and right subtrees to get their heights.
         4. check if any one of the heights is -1, if it is, return -1.
         5. return the absolute difference between left and right heights.
        if(abs(lh - rh) > 1) return -1;
         6. return max(lh, rh) + 1;
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

int is_balanced(Node* root){
    if(root == NULL) return 0;
    int lh = is_balanced(root->Left);
    int rh = is_balanced(root->Right);
    if(lh==-1 || rh ==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh, rh) + 1;

}

int main() {
    Node* root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);
    root->Right->Left = new Node(6);
    root->Right->Right = new Node(7);

    int result = is_balanced(root);
    if(result != -1) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    
    return 0;
}