//474. Ones and Zeroes
//In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
//
//For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
//
//Note:
//        The given numbers of 0s and 1s will both not exceed 100
//The size of given string array won't exceed 600.
//Example 1:
//Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
//Output: 4
//
//Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
//Example 2:
//Input: Array = {"10", "0", "1"}, m = 1, n = 1
//Output: 2
//
//Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".


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

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0, sizeof(dp));
        for (auto s : strs){
            int p = 0, q = 0;
            for (auto t : s){
                if (t == '0')
                    ++p;
                else
                    ++q;
            }
            for (int i = m; i >= p; --i)
                for (int j = n; j >= q; --j)
                    dp[i][j] = max(dp[i][j],dp[i-p][j-q]+1);
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    return 0;
}
