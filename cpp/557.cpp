//557. Reverse Words in a String III
//Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
//Example 1:
//Input: "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Note: In the string, each word is separated by single space and there will not be any extra space in the string.


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
    string reverseWords(string s) {
        string r;
        int b = 0;
        while (b < s.size()){
            auto sp = find(s.begin()+b,s.end(),' ');
            if (sp == s.end()){
                for (int i = s.size()-1; i >= b; --i)
                    r.push_back(s[i]);
                return r;
            } else {
                for (int i = sp - s.begin() - 1; i >= b; --i)
                    r.push_back(s[i]);
                r.push_back(' ');
                b = sp -s.begin() +1;
            }
        }
        return r;
    }
};

int main() {
    return 0;
}

