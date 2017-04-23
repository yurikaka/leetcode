//1. Two Sum
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//        Given nums = [2, 7, 11, 15], target = 9,
//
//        Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int>::iterator it;
        map<int,int> m;
        for (it = nums.begin(); it != nums.end(); ++it){
            if (m.find(*it) != m.end())
                return vector<int>{m[*it],it-nums.begin()};
            m[target-*it] = it - nums.begin();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}