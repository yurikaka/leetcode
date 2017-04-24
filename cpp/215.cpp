//215. Kth Largest Element in an Array
//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//        Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note:
//        You may assume k is always valid, 1 ≤ k ≤ array's length.


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < nums.size() - i - 1; ++j)
                if (nums[j] > nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
        return nums[nums.size()-k];
    }
};
int main() {
    Solution s;

    return 0;
}

