//541. Reverse String II
//Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//Example:
//        Input: s = "abcdefg", k = 2
//Output: "bacdfeg"
//Restrictions:
//        The string consists of lower English letters only.
//Length of the given string and k will in the range [1, 10000]


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
    string reverseStr(string s, int k) {
        string r;
        int b = 0;
        while (b < s.size()){
            if (b + k - 1 < s.size()){
                for (int i = b+k-1; i >=b; --i)
                    r.push_back(s[i]);
                b += k;
            } else {
                for (int i = s.size()-1; i >= b; --i)
                    r.push_back(s[i]);
                return r;
            }
            for (int i = b; i < b+k && i < s.size(); ++i)
                r.push_back(s[i]);
            b += k;
        }
        return r;
    }
};

int main() {
    return 0;
}

