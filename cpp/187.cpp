//187. Repeated DNA Sequences
//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//        Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//        Return:
//["AAAAACCCCC", "CCCCCAAAAA"].

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
    vector<string> findRepeatedDnaSequences(string s) {
        int hashmap[1048576] = {0};
        int hash = 0, l = s.size();
        vector<string> r;
        if (l < 11)
            return r;
        for (int i = 0; i < 9; ++i){
            hash = hash << 2 | (s[i] - 'A' + 1)%5;
        }
        for (int i = 9; i < l; ++i){
            hash =(hash << 2 | (s[i] - 'A' + 1)%5) & 0xfffff;
            if (hashmap[hash]++ == 1)
                r.push_back(s.substr(i-9,10));
        }
        return r;
    }
};

int main() {
    return 0;
}