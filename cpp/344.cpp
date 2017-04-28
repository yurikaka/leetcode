//344. Reverse String
//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//        Given s = "hello", return "olleh".


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
    string reverseString(string s) {
        string r;
        for (int i = s.size()-1; i > -1; --i){
            r.push_back(s[i]);
        }
        return r;
    }
};

int main() {
    return 0;
}

