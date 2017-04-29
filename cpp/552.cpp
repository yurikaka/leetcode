//552. Student Attendance Record II
//Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.
//
//A student attendance record is a string that only contains the following three characters:
//
//'A' : Absent.
//'L' : Late.
//'P' : Present.
//A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
//Example 1:
//Input: n = 2
//Output: 8
//Explanation:
//        There are 8 records with length 2 will be regarded as rewardable:
//"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//Only "AA" won't be regarded as rewardable owing to more than one absent times.
//Note: The value of n won't exceed 100,000.


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
    long long M = 1000000007;
    int checkRecord(int n) {
        long long a0l0 = 1, a1l0 = 0, a0l1 = 0, a1l1 = 0, a0l2 = 0, a1l2 = 0;
        for (int i = 0; i <= n; ++i){
            long long _a0l0 = (a0l0 + a0l1 + a0l2)%M;
            long long _a1l0 = (_a0l0 + a1l0 + a1l1 + a1l2)%M;
            a1l2 = a1l1;
            a0l2 = a0l1;
            a1l1 = a1l0;
            a0l1 = a0l0;
            a0l0 = _a0l0;
            a1l0 = _a1l0;
        }
        return int(a1l0);
    }
};

int main() {
    Solution s;
    return 0;
}

