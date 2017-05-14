//581. Shortest Unsorted Continuous Subarray My SubmissionsBack To Contest
//Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
//
//You need to find the shortest such subarray and output its length.
//
//Example 1:
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Note:
//        Then length of the input array is in range [1, 10,000].
//The input array may contain duplicates, so ascending order here means <=.

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
#include <math.h>

using namespace std;

long long M = 1000000007;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n;
        n = nums;
        sort(n.begin(),n.end());
        int l = nums.size();
        int r = l;
        for (int i = 0; i < l; ++i){
            if (nums[i] == n[i])
                --r;
            else
                break;
        }
        if (r == 0)
            return 0;
        for (int i = l-1; i > -1; --i){
            if (nums[i] == n[i])
                --r;
            else
                break;
        }
        return r;
    }
};

int main(){

}