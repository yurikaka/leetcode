//40. Combination Sum II
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//        All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
//A solution set is:
//[
//[1, 7],
//[1, 2, 5],
//[2, 6],
//[1, 1, 6]
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
    set<vector<int>> cc(vector<int>& candidates, int target, int begin){
        int l = candidates.size();
        set<vector<int>> r,s;
        if (begin >= l)
            return r;
        for (int i = begin; i < l; ++i){
            if (candidates[i] > target)
                continue;
            if (candidates[i] == target){
                r.insert(vector<int>{target});
                continue;
            }
            if (candidates[i] < target){
                s = cc(candidates,target-candidates[i],i+1);
                for (auto j : s){
                    j.push_back(candidates[i]);
                    r.insert(j);
                }
            }
        }
        return r;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        set<vector<int>> s = cc(candidates, target, 0);
        vector<vector<int>> r;
        for (auto i : s)
            r.push_back(i);
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
