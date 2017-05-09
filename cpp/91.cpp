//91. Decode Ways
//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//        Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.


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
    int numDecodings(string s) {
        int l = s.size();
        if (!l)
            return 0;
        vector<int> n(l,0);
        if (l == 1)
            return s[0] != '0';
        if (s[l-1] == '0'){
            if (s[l-2] != '1' && s[l-2] != '2')
                return 0;
            else{
                n[l-1] = 0;
                n[l-2] = 1;
            }
        }
        else {
            n[l-1] = 1;
            if ((s[l-1]-'0'<=6 && s[l-2] == '2' )|| s[l-2] == '1')
                n[l-2] = 2;
            else if (s[l-2] == '0')
                n[l-2] = 0;
            else
                n[l-2] = 1;
        }
        for (int i = l-3; i >= 0; --i){
            if (s[i] == '0')
                n[i] = 0;
            else if (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' <= 6))
                n[i] = n[i+1] + n[i+2];
            else
                n[i] = n[i+1];
        }
        return n[0];
    }
};

int main() {
    Solution s;
    return 0;
}
