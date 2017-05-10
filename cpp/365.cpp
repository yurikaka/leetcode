//365. Water and Jug Problem
//You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
//If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
//Operations allowed:
//
//Fill any of the jugs completely with water.
//Empty any of the jugs.
//Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//Example 1: (From the famous "Die Hard" example)
//
//Input: x = 3, y = 5, z = 4
//Output: True
//Example 2:
//
//Input: x = 2, y = 6, z = 5
//Output: False


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

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y < z)
            return false;
        if (x == z || y == z || x+y == z)
            return true;
        while (y){
            int q = x%y;
            x = y;
            y = q;
        }
        return z % x == 0;
    }
};

int main() {
    Solution s;
    return 0;
}
