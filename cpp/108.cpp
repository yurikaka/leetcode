//108. Convert Sorted Array to Binary Search Tree
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
#include <stack>

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
    TreeNode* so(vector<int>& nums, int pos, int len) {
        if (!len)
            return NULL;
        int left = (len-1)/2;
        TreeNode *root = new TreeNode(nums[pos+left]);
        root->left = so(nums,pos,left);
        root->right = so(nums,pos+left+1,len-left-1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return NULL;
        return so(nums, 0, l);
    }
};

int main() {
    return 0;
}

