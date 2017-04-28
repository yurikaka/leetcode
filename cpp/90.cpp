//90. Subsets II
//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//        If nums = [1,2,2], a solution is:
//
//[
//[2],
//[1],
//[1,2,2],
//[2,2],
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
#include <stack>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<vector<int>> r;
        vector<vector<int>> rr;
        int l = nums.size();
        if (!l){
            rr.push_back(vector<int>{});
            return rr;
        }
        r.insert(vector<int>{});
        sort(nums.begin(),nums.end());
        r.insert(vector<int>{nums[0]});
        for (int i = 1; i < l; ++i){
            auto r1 = r;
            for (auto j : r1){
                j.push_back(nums[i]);
                r.insert(j);
            }
        }
        for (auto i : r){
            rr.push_back(i);
        }
        return rr;
    }
};

int main() {
    return 0;
}

