//41. First Missing Positive
//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//        Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 1;
        for (int i = 0; i < l; ++i)
            while (nums[i] > 0 && nums[i] <= l && nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        for (int i = 0; i < l; ++i)
            if (nums[i] != i+1)
                return i+1;
        return l + 1;
    }
};

int main() {
    Solution s;
    return 0;
}
