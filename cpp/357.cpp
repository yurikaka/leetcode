//357. Count Numbers with Unique Digits
//Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//
//Example:
//        Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])


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
    int countNumbersWithUniqueDigits(int n) {
        if (!n)
            return 1;
        int r = 10;
        int rest = 9, exist = 9;
        while (n-- > 1 && rest > 0){
            exist = exist * rest;
            r += exist;
            --rest;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
