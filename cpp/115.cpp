//115. Distinct Subsequences
//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example:
//S = "rabbbit", T = "rabbit"
//
//Return 3.


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

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.size(), l2 = t.size();
        if (l1 < l2)
            return 0;
        int dp[l1] = {0};
        int pre, tmp;
        for (int i = 0; i < l1; ++i){
            pre = 1;
            for (int j = 0; j < l2; ++j){
                tmp = dp[j];
                dp[j] += s[i] == t[j] ? pre : 0;
                pre = tmp;
            }
        }
        return dp[l2-1];
    }
};

int main() {
    Solution s;
    return 0;
}
