//230. Kth Smallest Element in a BST
//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//        You may assume k is always valid, 1 ? k ? BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


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
    int count(TreeNode *root){
        if (!root)
            return 0;
        return 1+count(root->left)+count(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cl = count(root->left);
        if (cl == k-1)
            return root->val;
        if (cl > k-1)
            return kthSmallest(root->left,k);
        if (cl < k-1)
            return kthSmallest(root->right,k-cl-1);
    }
};

int main() {
    return 0;
}

