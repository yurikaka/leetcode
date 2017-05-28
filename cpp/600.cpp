//600. Non-negative Integers without Consecutive Ones
//        Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.
//
//Example 1:
//Input: 5
//Output: 5
//Explanation:
//        Here are the non-negative integers <= 5 with their corresponding binary representations:
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.

#include <bits/stdc++.h>

using namespace std;

long long M = 1000000007;

class Solution {
public:
    int findIntegers(int num) {
        if (num == 0)
            return 1;
        if (num == 1)
            return 2;
        if (num == 2)
            return 3;
        if (num == 3)
            return 3;
        int n = num;
        int c = 0;
        while (n){
            ++c;
            n >>= 1;
        }
        int nn = 1 << (c-1);
        n = num - nn;
        int dp[c-1][2];
        memset(dp,0,sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < c-1; ++i){
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }
        int ans = dp[c-2][0] + dp[c-2][1];
        if (n & 1 << (c-2)){
            memset(dp,0,sizeof(dp));
            dp[0][0] = dp[0][1] = 1;
            for (int i = 1; i < c-2; ++i){
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = dp[i-1][0];
            }
            ans += dp[c-3][0] + dp[c-3][1];
        }
        else {
            ans += findIntegers(n);
        }
        return ans;
    }
};

int main(){

}