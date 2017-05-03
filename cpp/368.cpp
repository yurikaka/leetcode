//368. Largest Divisible Subset
//Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
//
//If there are multiple solutions, return any subset is fine.
//
//Example 1:
//
//nums: [1,2,3]
//
//Result: [1,2] (of course, [1,3] will also be ok)
//Example 2:
//
//nums: [1,2,4,8]
//
//Result: [1,2,4,8]


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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> r;
        if (!nums.size())
            return r;
        sort(nums.begin(),nums.end(),greater<int>());
        int dp[nums.size()] = {0};
        dp[0] = 1;
        int next[nums.size()];
        memset(next,-1, sizeof(next));
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
                if (nums[j] % nums[i] == 0)
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        next[i] = j;
                    }
        }
        int maxx = 0, pos = -1;
        for (int i = 0; i < nums.size(); ++i)
            if (dp[i] > maxx){
                maxx = dp[i];
                pos = i;
            }
        while (pos != -1){
            r.push_back(nums[pos]);
            pos = next[pos];
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
