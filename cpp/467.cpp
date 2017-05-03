//467. Unique Substrings in Wraparound String
//Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.
//
//Note: p consists of only lowercase English letters and the size of p might be over 10000.
//
//Example 1:
//Input: "a"
//Output: 1
//
//Explanation: Only the substring "a" of string "a" is in the string s.
//Example 2:
//Input: "cac"
//Output: 2
//Explanation: There are two substrings "a", "c" of string "cac" in the string s.
//Example 3:
//Input: "zab"
//Output: 6
//Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.


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
    int findSubstringInWraproundString(string p) {
        vector<int> letter(26,0);
        int len = 0, r = 0;
        for (int i = 0; i < p.size(); ++i){
            if (i != 0 && (p[i-1]-'a'+1)%26 != p[i]-'a')
                len = 0;
            if (++len > letter[p[i]-'a']){
                r += len - letter[p[i]-'a'];
                letter[p[i]-'a'] = len;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
