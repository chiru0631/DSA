//987. Vertical Order Traversal of a Binary Tree

/*
    Problem Statment:
        Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

        For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
        and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

        The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column 
        index starting from the leftmost column and ending on the rightmost column. 
        There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

        Return the vertical order traversal of the binary tree.

*/

/*
    we will use a map to store the nodes at each column index,
    map<int, map<int, multiset<int>>> nodes;// first int is column index, second int is row index, multiset<int> 
    is the values of nodes at that position.
    we will use a queue to perform level order traversal of the tree.
    queue<pair<TreeNode*, pair<int, int>>> q; // pair of node and its position (row, col)
    Approach:

        1. create a map to store the nodes at each column index.
          map<int, map<int, multiset<int>>> nodes; // first int is column index, second int is row index, 
          multiset<int> is the values of nodes at that position.

        2. create a queue to perform level order traversal of the tree.
            queue<pair<TreeNode*, pair<int, int>>> q; // pair of node and its position (row, col)

        3. push the root node into the queue with its position (0, 0).
            q.push({root, {0, 0}});

        4. while the queue is not empty, we will process each node:
            take the front node from the queue and its position (row, col).
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;
            // Add the node's value to the map at its column and row index.
            nodes[col][row].insert(node->val);
            // If the node has a left child, push it into the queue with its position (row + 1, col - 1).
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            // If the node has a right child, push it into the queue with its position (row + 1, col + 1).
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }

        }

        // Now we need to prepare the result from the map.
        vector<vector<int>> result;
        for (auto p: nodes){
            vector<int> column;
            for(auto q: p.second){
                // For each row in the column, add all values to the column vector.
                column.insert(column.end(), q.second.begin(), q.second.end());}
        }
        result.push_back(column);
}

        return result;
*/


#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>>q;
    if(root == NULL) return {}; // If root is null, return empty vector
    q.push({root,{0,0}}); // Push root with its position (0,0)

    while(!q.empty()){
        auto it= q.front(); // Get the front node and its position
        q.pop();
        TreeNode* node =it.first;
        int row= it.second.first;
        int col= it.second.second;
        nodes[col][row].insert(node->val); // Insert the node's value into the map at its column and row index

        if(node->left){
            q.push({node->left,{row+1,col-1}}); // Push left child with its position (row+1, col-1)

        }
        if(node->right){
            q.push({node->right,{row+1,col+1}}); // Push right child with its position (row+1, col+1)
        }
    }
    // Prepare the result from the map
    vector<vector<int>> result;
    for(auto p: nodes){
        vector<int> column;
        for(auto q: p.second){
            // For each row in the column, add all values to the column vector.
            column.insert(column.end(), q.second.begin(), q.second.end());
        }
        result.push_back(column);
    }
    return result; // Return the final result
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = verticalOrder(root);
    
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
