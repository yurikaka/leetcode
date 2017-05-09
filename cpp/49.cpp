//49. Group Anagrams
//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return:
//
//[
//["ate", "eat","tea"],
//["nat","tan"],
//["bat"]
//]
//Note: All inputs will be in lower-case.


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
#include <bitset>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<int>> m;
        vector<vector<string>> r;
        int l = strs.size();
        for (int i = 0; i < l; ++i){
            vector<int> letter(26,0);
            for (char j : strs[i])
                letter[j-'a']++;
            m[letter].push_back(i);
        }
        for (auto i : m){
            vector<string> rr;
            for (int j : i.second)
                rr.push_back(strs[j]);
            r.push_back(rr);
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
