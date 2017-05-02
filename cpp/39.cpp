//39. Combination Sum
//Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//        All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [2, 3, 6, 7] and target 7,
//A solution set is:
//[
//[7],
//[2, 2, 3]
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
#include <set>
#include <deque>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> cc(vector<int>& candidates, int target, int begin){
        int l = candidates.size();
        vector<vector<int>> r,s;
        if (begin >= l)
            return r;
        for (int i = begin; i < l; ++i){
            if (candidates[i] > target)
                continue;
            if (candidates[i] == target){
                r.push_back(vector<int>{target});
                continue;
            }
            if (candidates[i] < target){
                s = cc(candidates,target-candidates[i],i);
                for (auto j : s){
                    j.push_back(candidates[i]);
                    r.push_back(j);
                }
            }
        }
        return r;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        return cc(candidates, target, 0);
    }
};

int main() {
    Solution s;
    return 0;
}
