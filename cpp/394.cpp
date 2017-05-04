//394. Decode String
//Given an encoded string, return it's decoded string.
//
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//Examples:
//
//        s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".


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
    string decodeString(string s) {
        if (s.find('[') == string::npos)
            return s;
        int i = 0;
        string rr;
        while (i < s.size()){
            if (isdigit(s[i])) {
                int l = s.find('[', i);
                int k = stoi(s.substr(i, l - i));
                int ss = 1, r;
                for (int j = l + 1;; ++j) {
                    if (s[j] == '[')
                        ++ss;
                    if (s[j] == ']')
                        --ss;
                    if (!ss) {
                        r = j;
                        break;
                    }
                }
//            int r = s.find(']',l+1);
                string a = decodeString(s.substr(l + 1, r - l - 1));
                for (int j = 0; j < k; ++j)
                    rr += a;
                i = r + 1;
            }
            int n = i+1;
            for (;n<s.size();++n)
                if (isdigit(s[n]))
                    break;
            rr += s.substr(i,n-i);
            i = n;
        }
        return rr;
    }
};

int main() {
    Solution s;
    string a = "52345";
    cout << a.rfind('5',3);
    return 0;
}
