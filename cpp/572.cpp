//572. Subtree of Another Tree My SubmissionsBack To Contest
//Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//Example 1:
//Given tree s:
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//Given tree t:
//   4
//  / \
// 1   2
//Return true, because t has the same structure and node values with a subtree of s.
//Example 2:
//Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
// /
// 0
//Given tree t:
//   4
//  / \
// 1   2
//Return false.

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
#include <set>
#include <deque>
#include <stack>
#include <bitset>

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
    bool check(TreeNode* s, TreeNode* t){
        if ((s && !t) || (!s && t))
            return false;
        if (!s && !t)
            return true;
        if (s->val != t->val)
            return false;
        else {
            return check(s->left,t->left)&&check(s->right,t->right);
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (check(s,t))
            return true;
        if (s->left && isSubtree(s->left,t))
            return true;
        if (s->right && isSubtree(s->right,t))
            return true;
        return false;
    }
};

int main() {
    return 0;
}