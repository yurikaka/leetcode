//99. Recover Binary Search Tree
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//        A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


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
    void rr(TreeNode *root, int i, int j){
        if (root->val == i)
            root->val = j;
        else if (root->val < j)
            rr(root->right,i,j);
        else if (root->val > j)
            rr(root->left,i,j);
    }
    pair<int,int> mm(TreeNode* root){
        pair<int,int> p{root->val,root->val}, q{root->val,root->val};
        if (root->left)
            p = mm(root->left);
        if (root->right)
            q = mm(root->right);
        return pair<int,int>(min(p.first,min(q.first,root->val)),max(p.second,max(q.second,root->val)));
    }
    void rt(TreeNode* root){
        if (!root)
            return;
        pair<int,int> p{root->val,root->val}, q{root->val,root->val};
        if (root->left)
            p = mm(root->left);
        if (root->right)
            q = mm(root->right);
        if (p.second > root->val && q.first < root->val){
            rr(root->left,p.second,q.first);
            rr(root->right,q.first,p.second);
        }
        else if (p.second > root->val){
            rr(root->left,p.second,root->val);
            root->val = p.second;
        }
        else if (q.first < root->val){
            rr(root->right,q.first,root->val);
            root->val = q.first;
        }
        else {
            rt(root->left);
            rt(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        rt(root);
    }
};

int main() {
    return 0;
}

