//233. Number of Digit One
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
//For example:
//Given n = 13,
//        Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

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
    int countDigitOne(int n) {
        int result = 0, right = 1, zero = 1;
        while (n > 0){
            result += (n+8)/10*zero + (n%10 == 1)*right;
            right += n % 10 * zero;
            zero *= 10;
            n /= 10;
        }
        return result;
    }
};

int main() {
    return 0;
}