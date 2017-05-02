//32. Longest Valid Parentheses
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


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
    int longestValidParentheses(string s) {
        int l = s.size();
        stack<int> pos, sig;
        pos.push(-1);
        sig.push(0);
        int r = 0;
        for (int i = 0; i < l; ++i){
            if (s[i] ==')' && sig.top() == '('){
                sig.pop();
                pos.pop();
                if (i-pos.top() > r)
                    r = i-pos.top();
            }
            else {
                pos.push(i);
                sig.push(s[i]);
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")))((())()((");
    return 0;
}
