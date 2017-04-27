//437. Path Sum III
//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
//Example:
//
//        root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. -3 -> 11


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
    int pr(TreeNode* root, int sum) {
        if (!root)
            return 0;
        if (root->val == sum)
            return 1 + pr(root->left,0) + pr(root->right,0);
        return pr(root->left,sum - root->val) + pr(root->right,sum - root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        int result = 0;
        result += pr(root->left,sum -root->val) + pr(root->right,sum-root->val);
        result += pathSum(root->left,sum) + pathSum(root->right,sum);
        if (sum == root->val)
            result++;
        return result;
    }
};

int main() {
    return 0;
}

