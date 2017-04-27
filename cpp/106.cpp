//106. Construct Binary Tree from Inorder and Postorder Traversal
//Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* bt(vector<int>& inorder, vector<int>& postorder, int ib, int ie, int pb, int pe) {
        if (ib > ie || pb > pe)
            return NULL;
        int val = postorder[pe];
        int pos = find(inorder.begin()+ib,inorder.begin()+ie,val) - inorder.begin();
        TreeNode *root = new TreeNode(val);
        root->left = bt(inorder,postorder,ib,pos-1,pb,pb+pos-ib-1);
        root->right = bt(inorder,postorder,pos+1,ie,pe-ie+pos,pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bt(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};

int main() {
    return 0;
}

