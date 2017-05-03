//77. Combinations
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//        If n = 4 and k = 2, a solution is:
//
//[
//[2,4],
//[3,4],
//[2,3],
//[1,2],
//[1,3],
//[1,4],
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
    vector<vector<int>> cc(vector<int> v, int begin, int k){
        vector<vector<int>> r, rr;
        if (begin + k > v.size())
            return r;
        if (k == 1){
            for (int i = begin; i < v.size(); ++i)
                r.push_back(vector<int>{v[i]});
            return r;
        }
        for (int i = begin; i < v.size(); ++i){
            rr = cc(v,i+1,k-1);
            for (auto j : rr){
                j.push_back(v[i]);
                r.push_back(j);
            }
        }
        return r;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
            v.push_back(i);
        return cc(v,0,k);
    }
};

int main() {
    Solution s;
    return 0;
}
