//318. Maximum Product of Word Lengths
//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
//Example 1:
//Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//Return 16
//The two words can be "abcw", "xtfn".
//
//Example 2:
//Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//Return 4
//The two words can be "ab", "cd".
//
//Example 3:
//Given ["a", "aa", "aaa", "aaaa"]
//Return 0
//No such pair of words.

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
    int maxProduct(vector<string>& words) {
        int l = words.size();
        if (!l)
            return 0;
        int letter[l] = {0};
        for (int i = 0; i < l; ++i)
            for (auto c : words[i])
                letter[i] |= 1 << (c-'a');
        int r = 0;
        for (int i = 0; i < l; i ++)
            for (int j = i + 1; j < l; ++j)
                if ((letter[i] & letter[j]) == 0)
                    r = max(r,words[i].size()*words[j].size());
        return r;
    }
};

int main() {
    return 0;
}