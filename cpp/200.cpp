//200. Number of Islands
//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer: 1
//
//Example 2:
//
//11000
//11000
//00100
//00011
//Answer: 3


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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size();
        if (!n)
            return 0;
        int reach[m][n];
        memset(reach,0, sizeof(reach));
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]-'0' && !reach[i][j]){
                    queue<pair<int,int>> q;
                    q.push(pair<int,int>{i,j});
                    result++;
                    while (q.size()){
                        pair<int,int> p = q.front();
                        q.pop();
                        if (reach[p.first][p.second])
                            continue;
                        reach[p.first][p.second] = 1;
                        if (p.first && !reach[p.first-1][p.second] && grid[p.first-1][p.second]-'0')
                            q.push(pair<int,int>(p.first-1,p.second));
                        if (p.first!=m-1 && !reach[p.first+1][p.second] && grid[p.first+1][p.second]-'0')
                            q.push(pair<int,int>(p.first+1,p.second));
                        if (p.second && !reach[p.first][p.second-1] && grid[p.first][p.second-1]-'0')
                            q.push(pair<int,int>(p.first,p.second-1));
                        if (p.second!=n-1 && !reach[p.first][p.second+1] && grid[p.first][p.second+1]-'0')
                            q.push(pair<int,int>(p.first,p.second+1));
                    }
                }
        return result;
    }
};

int main() {
    return 0;
}

