//134. Gas Station
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//        The solution is guaranteed to be unique.


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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, s = 0, current = 0, n = gas.size();
        while (s < n){
            rest += gas[current%n] - cost[current++%n];
            if (rest < 0){
                rest = 0;
                s = current;
            }
            else if (current%n == s%n)
                return s;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}
