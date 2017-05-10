//516. Longest Palindromic Subsequence
//Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//Input:
//
//"bbbab"
//Output:
//4
//One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input:
//
//"cbbd"
//Output:
//2
//One possible longest palindromic subsequence is "bb".


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
#include <exception>
#include <math.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.size();
        if (!l)
            return 0;
        int dp[l][l];
        memset(dp,0,sizeof(dp));
        for (int len = 0; len < l; ++len)
            for (int i = 0; i < l-len; ++i){
                int j = i + len;
                if (i == j)
                    dp[i][j] = 1;
                else if (i + 1 == j)
                    dp[i][j] = s[i] == s[j] ? 2 : 1;
                else {
                    int add = s[i] == s[j] ? 2 : 0;
                    dp[i][j] = max(max(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]+add);
                }
            }
        return dp[0][l-1];
    }
};

int main() {
    Solution s;
    return 0;
}
