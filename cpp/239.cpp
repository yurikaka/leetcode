//239. Sliding Window Maximum
//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//For example,
//        Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7
//Therefore, return the max sliding window as [3,3,5,5,6,7].
//
//Note:
//        You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
//
//Follow up:
//Could you solve it in linear time?

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

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> r;
        int l = nums.size();
        if (!l)
            return r;
        for (int i = 0; i < k; ++i){
            while (!q.empty() && q.back()<nums[i])
                q.pop_back();
            q.push_back(nums[i]);
        }
        r.push_back(q.front());
        int left = 0;
        for (int i = k; i < l; ++i){
            if (nums[left++] == q.front())
                q.pop_front();
            while (!q.empty() && q.back()<nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            r.push_back(q.front());
        }
        return r;
    }
};

int main() {

    return 0;
}
