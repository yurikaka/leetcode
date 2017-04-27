//224. Basic Calculator
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
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

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int l = s.size();
        int num = 0, signal = 1,result = 0;
        for (int i = 0; i < l; ++i){
            char c = s[i];
            if (isdigit(c)){
                num = num * 10 + c - '0';
            } else if (ispunct(c)){
                result += signal * num;
                num = 0;
                if (c == '+')
                    signal = 1;
                if (c == '-')
                    signal = -1;
                if (c == '('){
                    ops.push(signal);
                    nums.push(result);
                    signal = 1;
                    result = 0;
                }
                if (c == ')'){
                    result = result * ops.top() + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        return result + signal * num;
    }
};

int main() {
    return 0;
}

