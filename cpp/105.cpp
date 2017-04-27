//105. Construct Binary Tree from Preorder and Inorder Traversal
//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//        You may assume that duplicates do not exist in the tree.


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
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int pb, int pe, int ib, int ie) {
        if (pb > pe || ib > ie)
            return NULL;
        int val = preorder[pb];
        TreeNode *root = new TreeNode(val);
        int pos = find(inorder.begin()+ib,inorder.begin()+ie,val) - inorder.begin();
        root->left = bt(preorder,inorder,pb+1,pb+pos-ib,ib,pos-1);
        root->right = bt(preorder,inorder,pe-ie+pos+1,pe,pos+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

int main() {
    return 0;
}

