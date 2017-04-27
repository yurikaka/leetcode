//563. Binary Tree Tilt
//Given a binary tree, return the tilt of the whole tree.
//
//The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
//
//The tilt of the whole tree is defined as the sum of all nodes' tilt.
//
//Example:
//        Input:
//         1
//       /   \
//      2     3
//Output: 1
//Explanation:
//        Tilt of node 2 : 0
//Tilt of node 3 : 0
//Tilt of node 1 : |2-3| = 1
//Tilt of binary tree : 0 + 0 + 1 = 1
//Note:
//
//        The sum of node values in any subtree won't exceed the range of 32-bit integer.
//All the tilt values won't exceed the range of 32-bit integer.


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
    pair<pair<int,int>,int> ff(TreeNode *root){
        if (!root)
            return pair<pair<int,int>,int>({0,0},0);
        pair<pair<int,int>,int> p = ff(root->left), q = ff(root->right);
        int t = abs(p.second-q.second);
        return pair<pair<int,int>,int>({t,t+p.first.second+q.first.second},p.second+q.second+root->val);
    }
    int findTilt(TreeNode* root) {
        if (!root)
            return 0;
        pair<pair<int,int>,int> p = ff(root->left), q = ff(root->right);
        int t = abs(p.second-q.second);
        return t+p.first.second+q.first.second;
    }
};

int main() {
    return 0;
}

