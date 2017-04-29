//338. Counting Bits
//Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example:
//        For num = 5 you should return [0,1,1,2,1,2].
//
//Follow up:
//
//It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
//Space complexity should be O(n).
//Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.


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
    vector<int> countBits(int num) {
        vector<int> r;
        r.push_back(0);
        if (num == 0)
            return r;
        r.push_back(1);
        if (num == 1)
            return r;
        r.push_back(1);
        if (num == 2)
            return r;
        int m = 4;
        for (int i = 3; i <= num; ++i){
            if (i == m){
                r.push_back(1);
                m *= 2;
            }
            else {
                r.push_back(r[i-m/2]+1);
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}

