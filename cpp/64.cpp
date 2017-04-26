//64. Minimum Path Sum
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.


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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size();
        if (!n)
            return 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                if (!i && j)
                    grid[i][j] += grid[i][j-1];
                if (i && !j)
                    grid[i][j] += grid[i-1][j];
                if (i && j)
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        return grid[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> a{{1,2,5},{3,2,1}};
    Solution s;
    cout << s.minPathSum(a);
    return 0;
}

