//257. Binary Tree Paths
//Given a binary tree, return all root-to-leaf paths.
//
//For example, given the following binary tree:
//
//     1
//   /   \
//  2     3
//   \
//    5
//All root-to-leaf paths are:
//
//["1->2->5", "1->3"]


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
#include <math.h>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        if (!root->left && !root->right){
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> l = binaryTreePaths(root->left), r = binaryTreePaths(root->right);
        for (auto i : l)
            res.push_back(to_string(root->val) + "->" + i);
        for (auto i : r)
            res.push_back(to_string(root->val) + "->" + i);
        return res;
    }
};

int main() {
    return 0;
}

