//100. Same Tree

/*
    Problem Statement:
        Given the roots of two binary trees p and q, write a function to check if they are the same or not.

        Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/

/*
    Approach:
        1. Check if both trees are null, if they are return q==p.
        2. return (p->data == q->data) && check_identical(p->Left, q->Left) && check_identical(p->Right, q->Right);


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

bool identical(Node* p,Node* q){
    if(p==NULL || q==NULL) return p==q;
    return (p->data == q->data) && identical(p->Left, q->Left) && identical(p->Right, q->Right);

}

int main() {
    Node* p = new Node(1);
    p->Left = new Node(2);
    p->Right = new Node(3);

    Node* q = new Node(1);
    q->Left = new Node(2);
    q->Right = new Node(3);

    if (identical(p, q)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}