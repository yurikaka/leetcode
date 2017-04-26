//95. Unique Binary Search Trees II
//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//        Given n = 3, your program should return all 5 unique BST's shown below.
//
//     1         3     3      2      1
//      \       /     /      / \      \
//       3     2     1      1   3      2
//      /     /       \                 \
//     2     1         2                 3

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

using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> tree(int start, int end){
        vector<TreeNode*> result;
        if (start > end){
            result.push_back(NULL);
            return result;
        }
        if (start == end){
            result.push_back(new TreeNode(start));
            return result;
        }
        vector<TreeNode*> l,r;
        for (int i = start; i <= end; ++i){
            l = tree(start,i-1);
            r = tree(i+1,end);
            for (auto m : l)
                for (auto n : r){
                    TreeNode *root = new TreeNode(i);
                    root->left = m;
                    root->right = n;
                    result.push_back(root);
                }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n){
            vector<TreeNode*> v;
            return v;
        }
        return tree(1,n);
    }
};

int main() {
    return 0;
}

