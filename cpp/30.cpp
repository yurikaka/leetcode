//30. Substring with Concatenation of All Words
//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).

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

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        map<string,int> m;
        multiset<int> set,s1;
        int j;
        int l = words.size();
        for (int i = 0; i < l; ++i) {
            if (m.count(words[i])!=0)
                set.insert(m[words[i]]);
            else {
                m[words[i]] = i;
                set.insert(i);
            }
        }
        int ll = s.size();
        int lll = words[0].size();
        ll -= l * lll;
        for (int i = 0; i <= ll; ++i){
            s1 = set;
            j = i;
            while (s1.size()){
                if (m.count(s.substr(j,lll))!=0 && s1.count(m[s.substr(j, lll)])!=0) {
                    s1.erase(s1.find(m[s.substr(j, lll)]));
                    j += lll;
                }
                else
                    break;
            }
            if (!s1.size())
                r.push_back(i);
        }
        return r;
    }
};

int main() {

    return 0;
}
