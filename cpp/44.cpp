//44. Wildcard Matching
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size(), l2 = p.size();
        if (!l1){
            if (!l2)
                return true;
            else {
                while (--l2 >= 0 )
                    if (p[l2] != '*')
                        return false;
                return true;
            }
        }
        if (!l2)
            return false;
        int r[l1][l2], m, n;
        memset(r,-1, sizeof(r));
        queue<pii> q;
        q.push({l1-1,l2-1});
        while (q.size()) {
            m = q.front().first;
            n = q.front().second;
            q.pop();
            // cout << m << "," << n << s[m] << "," << p[n]  << r[m][n]<<endl;
            if (r[m][n] != -1 && r[m][n] != 2)
                continue;
            r[m][n] = 1;
            if (s[m] == p[n] || p[n] == '?') {
                if (m && n)
                    q.push({m - 1, n - 1});
                while (!m && n && p[--n] == '*')
                    r[m][n] = 2;
            } else if (p[n] == '*') {
                if (m) {
                    q.push({m - 1, n});
                    if (n) {
                        q.push({m - 1, n - 1});
                    }
                }
                if (n)
                    q.push({m,n-1});
            }
            else {
                r[m][n] = 0;
            }
        }
        return r[0][0] == 1 || r[0][0] == 2;
    }
};

int main() {
    Solution s;
    return 0;
}
