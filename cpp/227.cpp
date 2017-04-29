//227. Basic Calculator II
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//Note: Do not use the eval built-in library function.


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
#include <stack>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        for (auto i = s.begin(); i != s.end();){
            if (*i == ' ')
                s.erase(i);
            else
                ++i;
        }
        int num = 0;
        int pos;
        for (pos = 0; pos < s.size(); ++pos){
            if (isdigit(s[pos]))
                num = num * 10 + s[pos] - '0';
            else
                break;
        }
        int val = num, prev = num;
        while (pos < s.size()){
            char c = s[pos];
            num  = 0;
            for (++pos; pos < s.size(); ++pos){
                if (isdigit(s[pos]))
                    num = num * 10 + s[pos] - '0';
                else
                    break;
            }
            if (c == '+') {
                val += num;
                prev = num;
            }
            if (c == '-') {
                val -= num;
                prev = -num;
            }
            if (c == '*') {
                val = val - prev + prev * num;
                prev *= num;
            }
            if (c == '/') {
                val = val - prev + prev / num;
                prev /= num;
            }
        }
        return val;
    }
};

int main() {
    Solution s;
    return 0;
}

