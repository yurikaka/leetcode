//140. Word Break II
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//        dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is ["cats and dog", "cat sand dog"].
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
    map<int,vector<string>> m;
    vector<string> ww(string s, unordered_set<string>& dict, int mini, int maxx){
        if (m.count(s.size()))
            return m[s.size()];
        vector<string> r,rr;
        if (dict.count(s) != 0)
            r.push_back(s);
        int l = s.size(), len = mini;
        while (len <= l && len <= maxx){
            if (dict.count(s.substr(0,len))){
                rr = ww(s.substr(len),dict,mini,maxx);
                for (auto i : rr)
                    r.push_back(s.substr(0,len)+" "+i);
            }
            ++len;
        }
        m[l] = r;
        return r;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        m.clear();
        unordered_set<string> dict;
        vector<string> r,rr;
        for (auto  i : wordDict)
            dict.insert(i);
        if (dict.count(s) != 0)
            r.push_back(s);
        int mini = INT_MAX, maxx = 0;
        for (auto i : wordDict){
            int l = i.size();
            mini = min(mini,l);
            maxx = max(maxx,l);
        }
        int l = s.size(), len = mini;
        while (len <= l && len <= maxx){
            if (dict.count(s.substr(0,len))){
                rr = ww(s.substr(len),dict,mini,maxx);
                for (auto i : rr)
                    r.push_back(s.substr(0,len)+" "+i);
            }
            ++len;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
