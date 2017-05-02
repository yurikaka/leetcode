//209. Minimum Size Subarray Sum
//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
//        the subarray [4,3] has the minimal length under the problem constraint.
//More practice:
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

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

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, d = INT_MAX, h = 0, sum = 0;
        while (r < nums.size()){
            sum += nums[r++];
            while (sum >= s){
                if (r-l < d)
                    d = r - (h=l);
                sum -= nums[l++];
            }
        }
        return d == INT_MAX?0:d;
    }
};

int main() {

    return 0;
}
