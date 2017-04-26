//96. Unique Binary Search Trees
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//        Given n = 3, there are a total of 5 unique BST's.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3


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

class Solution {
public:
    int numTrees(int n) {
        if (n == 1)
            return 1;
        if (n == 0)
            return 1;
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n+1; ++i)
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i-j-1];
        return dp[n];
    }
};

int main() {
    return 0;
}

