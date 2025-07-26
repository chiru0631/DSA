//Serialize and Deserialize Binary Tree

/*
    Problem Statement:
        Serialization is the process of converting a data structure or object into a 
        sequence of bits so that it can be stored in a file or memory buffer, 
        or transmitted across a network connection link to be reconstructed later 
        in the same or another computer environment.

        Design an algorithm to serialize and deserialize a binary tree. 
        There is no restriction on how your serialization/deserialization algorithm should work. 
        You just need to ensure that a binary tree can be serialized to a string and this string can be 
        deserialized to the original tree structure.
*/

/*
    Approach:
        we need to create 4 functions:
        1. serialize: This function will convert the binary tree into a string.
        2. deserialize: This function will convert the string back into the binary tree.
        3. serializeUtil: This function will be a helper function for the serialize function.
        4. deserializeUtil: This function will be a helper function for the deserialize function.

        1. In the serialize function:
            - Create a string to store the serialized tree.
              string result;
            - Call the serializeUtil function with the root node and the string.
               serializeUtil(root, result);
            - Return the serialized string.

        2. serializeUtil function:
            - If the node is null, append "null," to the string and return.
               if (node == NULL) {
                   result += "null,";
                   return;
               }
            - Append the node's value to the string followed by a comma.
               result += to_string(node->val) + ",";
            - Recursively call serializeUtil for the left and right children of the node.
            - serializeUtil(node->left, result);
            - serializeUtil(node->right, result);

        3. In the deserialize function:
            - Create a queue to store the values from the serialized string.
              queue<string> q;
            - Split the serialized string by commas and push the values into the queue.
              stringstream ss(serialized);
              string token;
              while (getline(ss, token, ',')) {
                  q.push(token);
              }
            - Call the deserializeUtil function with the queue.
              return deserializeUtil(q);

        4. deserializeUtil function:
            - If the queue is empty, return null.
              if (q.empty()) return NULL;
            - Get the front value from the queue and pop it.
              string val = q.front();
              q.pop();
            - If the value is "null", return null.
              if (val == "null") return NULL;
            - Create a new node with the value and recursively call deserializeUtil for the left and right children.
              TreeNode* node = new TreeNode(stoi(val));
              node->left = deserializeUtil(q);
              node->right = deserializeUtil(q);
            - Return the node.
*/

#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serializeUtil(TreeNode* node, string& result) {
    if (node == NULL) {
        result += "null,";
        return;
    }
    result += to_string(node->val) + ",";
    serializeUtil(node->left, result);
    serializeUtil(node->right, result);
}
TreeNode* deserializeUtil(queue<string>& q) {
    if (q.empty()) return NULL;
    string val = q.front();
    q.pop();
    if (val == "null") return NULL;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeUtil(q);
    node->right = deserializeUtil(q);
    return node;
}
string serialize(TreeNode* root) {
    string result;
    serializeUtil(root, result);
    return result;
}
TreeNode* deserialize(string serialized) {
    queue<string> q;
    stringstream ss(serialized);
    string token;
    while (getline(ss, token, ',')) {
        q.push(token);
    }
    return deserializeUtil(q);
}
int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = deserialize(serialized);
    string deserializedSerialized = serialize(deserializedRoot);
    cout << "Deserialized and Serialized again: " << deserializedSerialized << endl;

    return 0;
}