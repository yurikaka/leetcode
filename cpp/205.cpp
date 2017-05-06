//205. Isomorphic Strings
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
//        Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//        You may assume both s and t have the same length.

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
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m1, m2;
        int l = s.size();
        for (int i = 0; i < l; ++i){
            if (m1.count(s[i]) == 0){
                if (m2.count(t[i])!=0)
                    return false;
                m1[s[i]] = i;
                m2[t[i]] = i;
            }
            else if (m2.count(t[i])==0)
                return false;
            else if (m1[s[i]]!=m2[t[i]])
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}