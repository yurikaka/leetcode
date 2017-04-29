//434. Number of Segments in a String
//Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
//
//Please note that the string does not contain any non-printable characters.
//
//Example:
//
//        Input: "Hello, my name is John"
//Output: 5


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
    int countSegments(string s) {
        if (!s.size())
            return 0;
        bool sp = (s[0] == ' ');
        int r = 0;
        if (!sp)
            ++r;
        for (char c : s){
            if (sp && c != ' '){
                sp = false;
                ++r;
            }
            if (!sp && c == ' ')
                sp = true;
        }
        return r;
    }
};

int main() {
    return 0;
}

