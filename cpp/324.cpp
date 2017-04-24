//324. Wiggle Sort II
//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//Example:
//        (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
//(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//Note:
//        You may assume all input has valid answer.
//
//Follow Up:
//Can you do it in O(n) time and/or in-place with O(1) extra space?


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
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums.size()/2 + nums.size()%2;
        reverse(nums.begin(),nums.begin()+s);
        reverse(nums.begin()+s,nums.end());
        for (int i = s; i < nums.size(); ++i){
            int temp = nums[i];
            for (int j = i; j > (i-s)*2+1; --j)
                nums[j] = nums[j-1];
            nums[(i-s)*2+1] = temp;
        }
    }
};

int main() {
    Solution s;

    return 0;
}

