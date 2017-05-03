//139. Word Break
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
//
//For example, given
//s = "leetcode",
//        dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".
//
//UPDATE (2017/1/4):
//The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.


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
    map<int,bool> m;
    bool ww(string s, vector<string>& wordDict, int mini, int maxx){
        if (m.count(s.size()) != 0)
            return m[s.size()];
        int len = mini;
        while (len <= maxx && len <= s.size()){
            if (find(wordDict.begin(),wordDict.end(),s.substr(0,len))!=wordDict.end() && (ww(s.substr(len),wordDict,mini,maxx) || len == s.size())) {
                m[s.size()] = true;
                return true;
            }
            ++len;
        }
        m[s.size()] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        m.clear();
        int mini = INT_MAX, maxx = 0;
        for (auto i : wordDict){
            int l = i.size();
            mini = min(mini,l);
            maxx = max(maxx,l);
        }
        int len = mini;
        while (len <= maxx && len <= s.size()){
            if (find(wordDict.begin(),wordDict.end(),s.substr(0,len))!=wordDict.end() && (ww(s.substr(len),wordDict,mini,maxx) || len == s.size()))
                return true;
            ++len;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}
