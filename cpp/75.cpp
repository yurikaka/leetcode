//75. Sort Colors
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//        You are not suppose to use the library's sort function for this problem.


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
    void sortColors(vector<int>& nums) {
        int l = nums.size();
        int temp;
        for (int i = 0; i < l; ++i){
            for (int j = 0; j < l - i - 1; ++j){
                if (nums[j] > nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}

