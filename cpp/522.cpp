//522. Longest Uncommon Subsequence II
//Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
//
//Example 1:
//Input: "aba", "cdc", "eae"
//Output: 3
//Note:
//
//        All the given strings' lengths will not exceed 10.
//The length of the given list will be in the range of [2, 50].


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

bool cmp(string p, string q){
    return p.size() > q.size() || (p.size() == q.size() && p < q);
}

bool issub(string p, string q){
    int m = p.size(), n = q.size(), i = 0, j = 0;
    while (i < m && j < n){
        if (p[i] == q[j])
            i++;
        j++;
    }
    return i == p.size();
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        set<int> d;
        sort(strs.begin(),strs.end(),cmp);
        for (int i = 0; i < strs.size()-1; ++i){
            if (strs[i] == strs[i+1]){
                d.insert(i);
                d.insert(i+1);
            }
        }
        for (int i = 0; i < strs.size(); ++i){
            if (d.count(i) != 0)
                continue;
            if (i == 0)
                return strs[0].size();
            for (int j = 0; j < i; ++j){
                if (issub(strs[i],strs[j]))
                    break;
                if (j == i-1)
                    return strs[i].size();
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    return 0;
}
