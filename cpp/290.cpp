//290. Word Pattern
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//        pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//Notes:
//        You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

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
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> m;
        unordered_map<string,char> mm;
        int l = pattern.size();
        int pos = 0, next;
        str.push_back(' ');
        for (int i = 0; i < l; ++i){
            if (pos >= str.size())
                return false;
            next = str.find(' ',pos);
            if (next == string::npos)
                return false;
            char c = pattern[i];
            string cc = str.substr(pos,next-pos);
            if (m.count(c)==0){
                if (mm.count(cc)!=0)
                    return false;
                m[c] = cc;
                mm[cc] = c;
            }
            else {
                if (m[c] != cc)
                    return false;
            }
            pos = next + 1;
        }
        return pos == str.size();
    }
};

int main() {
    return 0;
}