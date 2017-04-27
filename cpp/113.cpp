//113. Path Sum II
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//[
//[5,4,11,2],
//[5,8,4,5]
//]


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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root)
            return result;
        if (!root->left && !root->right){
            if (sum == root->val)
                result.push_back(vector<int>{root->val});
            return result;
        }
        vector<vector<int>> l ,r;
        l = pathSum(root->left,sum-root->val);
        r = pathSum(root->right,sum-root->val);
        for (auto i: l){
            i.insert(i.begin(),root->val);
            result.push_back(i);
        }
        for (auto i: r){
            i.insert(i.begin(),root->val);
            result.push_back(i);
        }
        return result;
    }
};

int main() {
    return 0;
}

