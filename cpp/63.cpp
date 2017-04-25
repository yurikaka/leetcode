//63. Unique Paths II
//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//        There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//[0,0,0],
//[0,1,0],
//[0,0,0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.


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

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] || obstacleGrid[0][0])
            return 0;
        queue<pair<int,int>> q;
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[m-1][n-1] = 1;
        q.push(pair<int,int>(m-1,n-1));
        int reach[m][n];
        memset(reach,0,sizeof(reach));
        reach[m-1][n-1] = 1;
        while (q.size()){
            pair<int,int> p = q.front();
            q.pop();
            if (p.first && !obstacleGrid[p.first-1][p.second]){
                dp[p.first-1][p.second] += dp[p.first][p.second];
                if (!reach[p.first-1][p.second]) {
                    q.push(pair<int, int>(p.first - 1, p.second));
                    reach[p.first - 1][p.second] = 1;
                }
            }
            if (p.second && !obstacleGrid[p.first][p.second-1]){
                dp[p.first][p.second-1] += dp[p.first][p.second];
                if (!reach[p.first][p.second-1]) {
                    q.push(pair<int, int>(p.first, p.second - 1));
                    reach[p.first][p.second - 1] = 1;
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    return 0;
}

