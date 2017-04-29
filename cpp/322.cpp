//322. Coin Change
//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2:
//coins = [2], amount = 3
//return -1.
//
//Note:
//        You may assume that you have an infinite number of each kind of coin.


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
    unordered_map<int,int> m{{0,0}};
    int coinChange(vector<int>& coins, int amount) {
        if (!amount)
            return 0;
        sort(coins.begin(),coins.end());
        int r = amount + 1, t;
        for (auto i : coins) {
            if (i <= amount) {
                if (m.find(amount-i) == m.end())
                    t = coinChange(coins, amount - i) + 1;
                else
                    t = m[amount-i] + 1;
                if (t)
                    r = min(r, t);
            }
        }
        if (r != amount+1) {
            m[amount] = r;
            return r;
        }
        m[amount] = -1;
        return -1;
    }
};

int main() {
    Solution s;
    return 0;
}

