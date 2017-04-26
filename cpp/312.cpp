//312. Burst Balloons
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//        (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//Example:
//
//        Given [3, 1, 5, 8]
//
//Return 167
//
//nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


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
    int maxCoins(vector<int>& nums) {
        int l = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[l+2][l+2];
        memset(dp,0, sizeof(dp));
        for (int i = 1; i < l+1; ++i)
            for (int j = 1; j < l - i + 2; ++j){
                int left = j, right = left + i - 1;
                for (int k = left; k < right + 1; ++k)
                    dp[left][right] = max(dp[left][right],nums[left-1]*nums[k]*nums[right+1]+dp[left][k-1]+dp[k+1][right]);
            }
        return dp[1][l];
    }
};

int main() {
    return 0;
}

