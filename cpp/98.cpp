//98. Validate Binary Search Tree
//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//        The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//Example 1:
//    2
//   / \
//  1   3
//Binary tree [2,1,3], return true.
//Example 2:
//    1
//   / \
//  2   3
//Binary tree [1,2,3], return false.


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
    pair<int,int> mm(TreeNode* root){
        if (!root->left && !root->right)
            return pair<int,int>(root->val,root->val);
        int l = root->val, r = root->val;
        pair<int,int> p;
        if (root->left){
            p = mm(root->left);
            if (p.first > p.second || p.second >= root->val)
                return pair<int,int>(2,1);
            l = p.first;
        }
        if (root->right){
            p = mm(root->right);
            if (p.first > p.second || p.first <= root->val)
                return pair<int,int>(2,1);
            r = p.second;
        }
        return pair<int,int>(l,r);
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        pair<int,int> p = mm(root);
        return p.first <= p.second;
    }
};

int main() {
    return 0;
}

