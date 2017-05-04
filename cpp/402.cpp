//402. Remove K Digits
//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//        The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.
//Example 1:
//
//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//Example 2:
//
//Input: num = "10200", k = 1
//Output: "200"
//Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//Example 3:
//
//Input: num = "10", k = 2
//Output: "0"
//Explanation: Remove all the digits from the number and it is left with nothing which is 0.


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
    string removeKdigits(string num, int k) {
        deque<char> s;
        string r;
        int l = num.size(), d = l-k, c = 0;
        for (int i = 0; i < l; ++i){
            char c= num[i];
            while (!s.empty() && k>0 && s.back()>c){
                s.pop_back();
                --k;
            }
            s.push_back(c);
        }
        for (int i = 0; i < d; ++i){
            r.push_back(s.front());
            s.pop_front();
        }
        while (r.size()){
            if (r[0] == '0')
                r.erase(r.begin());
            else
                break;
        }
        if (!r.size())
            r.push_back('0');
        return r;
    }
};
int main() {
    Solution s;
    return 0;
}
