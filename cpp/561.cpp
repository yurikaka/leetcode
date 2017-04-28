//561. Array Partition I
//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1:
//Input: [1,4,3,2]
//
//Output: 4
//Explanation: n is 2, and the maximum sum of pairs is 4.
//Note:
//        n is a positive integer, which is in the range of [1, 10000].
//All the integers in the array will be in the range of [-10000, 10000].


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
#include <stack
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(),nums.end());
        int r = 0;
        for (int i = 0; i < l; i+=2)
            r += nums[i];
        return r;
    }
};

int main() {
    return 0;
}

