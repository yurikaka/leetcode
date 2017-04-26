//241. Different Ways to Add Parentheses
//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
//
//Example 1
//Input: "2-1-1".
//
//((2-1)-1) = 0
//(2-(1-1)) = 2
//Output: [0, 2]
//
//
//Example 2
//Input: "2*3-4*5"
//
//(2*(3-(4*5))) = -34
//((2*3)-(4*5)) = -14
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10
//(((2*3)-4)*5) = 10
//Output: [-34, -14, -10, -10, 10]

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

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> r;
        for (int i = 0; i < input.size(); ++i){
            char c = input[i];
            if (ispunct(c)){
                for (auto m : diffWaysToCompute(input.substr(0,i)))
                    for (auto n : diffWaysToCompute(input.substr(i+!))){
                        if (c == '+')
                            r.push_back(m+n);
                        if (c == '-')
                            r.push_back(m-n);
                        if (c == '*')
                            r.push_back(m*n);
                    }
            }
        }
        if (!r.size())
            r.push_back(stoi(input));
        return r;
    }
};

int main() {
    return 0;
}

