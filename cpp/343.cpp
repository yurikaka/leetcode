//343. Integer Break
//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: You may assume that n is not less than 2 and not larger than 58.


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
    int integerBreak(int n) {
        int dp[n+1] = {0};
        dp[1] = 1;
        if (n == 2)
            return 1;
        dp[2] = 2;
        if (n == 3)
            return 2;
        dp[3] = 3;
        for (int i = 2; i < n+1; ++i)
            for (int j = 1; j < i; ++j){
                dp[i] = max(dp[i],dp[j]*dp[i-j]);
            }
        return dp[n];
    }
};

int main() {
    return 0;
}

