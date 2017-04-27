//327. Count of Range Sum
//Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
//
//Note:
//        A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
//Example:
//        Given nums = [-2, 5, -1], lower = -2, upper = 2,
//        Return 3.
//The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

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

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> s;
        int result = 0;
        long long sum = 0;
        s.insert(sum);
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            result += distance(s.lower_bound(sum-upper),s.upper_bound(sum-lower));
            s.insert(sum);
        }
        return result;
    }
};

int main() {
    return 0;
}

