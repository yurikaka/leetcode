//560. Subarray Sum Equals K My SubmissionsBack To Contest
//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1,1,1], k = 2
//Output: 2
//Note:
//        The length of the array is in range [1, 20,000].
//The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <std/c++11.h>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int l = nums.size();
        long long sum = 0;
        for (int i = 0; i < l; ++i){
            sum = nums[i];
            if (sum == k)
                ++result;
            for (int j = i+1; j < l; ++j){
                sum += nums[j];
                if (sum == k)
                    ++result;
            }
        }
        return result;
    }
};