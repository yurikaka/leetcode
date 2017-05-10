//372. Super Pow
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//Example1:
//
//        a = 2
//b = [3]
//
//Result: 8
//Example2:
//
//        a = 2
//b = [1,0]
//
//Result: 1024


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
#include <exception>
#include <math.h>

using namespace std;

#define MOD 1337

class Solution {
public:
    int ss(int a, int b){
        a %= MOD;
        int result = 1;
        for (int i = 0; i < b; ++i)
            result = result * a % MOD;
        return result;
    }
    int superPow(int a, vector<int>& b) {
        if (!b.size())
            return 1;
        int bb = b.back();
        b.pop_back();
        return ss(superPow(a,b),10)*ss(a,bb)%MOD;
    }
};

int main() {
    Solution s;
    return 0;
}
