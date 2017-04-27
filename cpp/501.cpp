//501. Find Mode in Binary Search Tree
//Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//Assume a BST is defined as follows:
//
//        The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.
//For example:
//Given BST [1,null,2,2],
//   1
//    \
//     2
//    /
//   2
//return [2].
//
//Note: If a tree has more than one mode, you can return them in any order.
//
//Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>
#include <memory.h>
#include <stack
#include <set>

using namespace std;

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> mode;
    int current_cnt = 0, current_val = 0, max_cnt = 0;
    void proc(int val){
        cout << val << endl;
        if (!current_cnt || val != current_val){
            current_val = val;
            current_cnt = 1;
        } else
            current_cnt++;
        if (current_cnt > max_cnt){
            mode.clear();
            mode.push_back(val);
            max_cnt = current_cnt;
        } else if (current_cnt == max_cnt){
            mode.push_back(val);
        }
    }
    void procr(TreeNode *root){
        if (!root)
            return;
        procr(root->left);
        proc(root->val);
        procr(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        mode.clear();
        current_cnt = 0;
        current_val = 0;
        max_cnt = 0;
        procr(root);
        return mode;
    }
};

int main() {
    return 0;
}

