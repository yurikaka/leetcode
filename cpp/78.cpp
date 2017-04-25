//78. Subsets
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//        If nums = [1,2,3], a solution is:
//
//[
//[3],
//[1],
//[2],
//[1,2,3],
//[1,3],
//[2,3],
//[1,2],
//[]
//]


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

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        if (nums.size() == 0)
            return result;
        vector<int> temp;
        temp.push_back(nums[0]);
        result.push_back(temp);
        for (int i = 1; i < nums.size(); ++i){
            vector<vector<int>> temp;
            for (auto r : result){
                r.push_back(nums[i]);
                temp.push_back(r);
            }
            result.insert(result.begin(),temp.begin(),temp.end());
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

