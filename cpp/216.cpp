//216. Combination Sum III
//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//[[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//[[1,2,6], [1,3,5], [2,3,4]]


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
    set<vector<int>> cc(set<int> s, int k, int n, int m){
        set<int> s1;
        set<vector<int>> r,rr;
        if (k == 1){
            if (s.count(n)!=0 && n < m)
                r.insert(vector<int>{n});
            return r;
        }
        for (auto it = s.rbegin(); it != s.rend(); ++it){
            if (*it >= m)
                continue;
            if (*it >= n)
                continue;
            if (*it < n){
                s1 = s;
                s1.erase(*it);
                rr = cc(s1,k-1,n-*it,*it);
                for (auto i : rr){
                    i.push_back(*it);
                    r.insert(i);
                }
            }
        }
        return r;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // if (k >= 5)
        //     return combinationSum3(9-k, 45 -n);
        vector<vector<int>> r;
        int maxx = 0, mini = 0;
        for (int i = 1; i <= k; ++i) {
            mini += i;
            maxx += 10 - i;
        }
        if (n < mini || n > maxx)
            return r;
        set<int> s{1,2,3,4,5,6,7,8,9};
        set<vector<int>> ss = cc(s,k,n,10);
        for (auto i : ss)
            r.push_back(i);
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
