//556. Next Greater Element III
//Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
//
//Example 1:
//Input: 12
//Output: 21
//Example 2:
//Input: 21
//Output: -1


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
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (next_permutation(s.begin(),s.end())) {
            long long r = stoll(s);
            if (r > INT32_MAX)
                return -1;
            else
                return r;
        }
        else
            return -1;
    }
};

int main() {
    Solution s;
    return 0;
}
