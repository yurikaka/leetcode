//222. Count Complete Tree Nodes
//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


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


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode *l = root, *r = root;
        int lh = 0, rh = 0;
        while (l){
            ++lh;
            l = l->left;
        }
        while (r){
            ++rh;
            r = r->right;
        }
        if (l == r)
            return int(pow(2,lh))-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Solution s;
    return 0;
}

