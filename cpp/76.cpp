//76. Minimum Window Substring
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//        S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//        If there is no such window in S that covers all characters in T, return the empty string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

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
    string minWindow(string s, string t) {
        int a[128] = {0};
        for (auto i : t)
            a[i]++;
        int left = 0, right = 0, l = INT_MAX, c = t.size(), head = 0;
        while (right < s.size()){
            if (a[s[right++]]-->0)
                c--;
            while (c == 0){
                if (right-left<l)
                    l = right - (head = left);
                if (a[s[left++]]++==0)
                    c++;
            }
        }
        return l == INT_MAX ? "" : s.substr(head,l);
    }
};

int main() {

    return 0;
}
