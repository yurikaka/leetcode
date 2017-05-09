//486. Predict the Winner
//Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
//
//Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
//
//Example 1:
//Input: [1, 5, 2]
//Output: False
//Explanation: Initially, player 1 can choose between 1 and 2.
//If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
//So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
//Hence, player 1 will never be the winner and you need to return False.
//Example 2:
//Input: [1, 5, 233, 7]
//Output: True
//Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
//Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
//Note:
//1 <= length of the array <= 20.
//Any scores in the given array are non-negative integers and will not exceed 10,000,000.
//If the scores of both players are equal, then player 1 is still the winner.


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
    bool PredictTheWinner(vector<int>& nums) {
        int l = nums.size();
        int sum[l+1], s = 0, dp[l][l];
        sum[0] = 0;
        for (int i = 0; i < l; ++i){
            s += nums[i];
            sum[i+1]  = s;
        }
        for (int len = 1; len <= l; ++len)
            for (int left = 0; left + len - 1 < l; ++left){
                int right = left + len - 1;
                if (right == left)
                    dp[left][right] = nums[left];
                else if (right - left == 1)
                    dp[left][right] = max(nums[left],nums[right]);
                else {
                    int pl = nums[left] + sum[right+1] - sum[left+1] - dp[left+1][right];
                    int pr = nums[right] + sum[right] - sum[left] - dp[left][right-1];
                    dp[left][right] = max(pl,pr);
                }
            }
        return dp[0][l-1] >= sum[l]/2+sum[l]%2;
    }
};

int main() {
    Solution s;
    return 0;
}
