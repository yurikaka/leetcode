//62. Unique Paths
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//
//
//Above is a 3 x 7 grid. How many possible unique paths are there?
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
    int uniquePaths(int m, int n) {
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
            if (p.first){
                dp[p.first-1][p.second] += dp[p.first][p.second];
                if (!reach[p.first-1][p.second]) {
                    q.push(pair<int, int>(p.first - 1, p.second));
                    reach[p.first - 1][p.second] = 1;
                }
            }
            if (p.second){
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
    cout << s.uniquePaths(3,7) << endl;
    return 0;
}

