//377. Combination Sum IV
//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//        nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are:
//        (1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?


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
    map<int,int> m;
    int cc(vector<int>& nums, int target){
        if (m.count(target)!=0)
            return m[target];
        int r = 0;
        int l = nums.size();
        for (int i = 0; i < l; ++i){
            if (nums[i] > target)
                continue;
            if (nums[i] == target)
                ++r;
            if (nums[i] < target){
                r += cc(nums,target-nums[i]);
            }
        }
        m[target] = r;
        return r;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end(),greater<int>());
        m.clear();
        return cc(nums, target);
    }
};

int main() {
    Solution s;
    return 0;
}
