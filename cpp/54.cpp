//54. Spiral Matrix
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//        Given the following matrix:
//
//[
//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].

#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (!m)
            return ans;
        int n = matrix[0].size();
        int cnt = m*n, x = 0, y = 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        ans.resize(cnt);
        int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, direct = 0;
        while (cnt--){
            ans[m*n-cnt-1] = matrix[y][x];
            if (cnt) {
                visit[y][x] = 1;
                x += dx[direct];
                y += dy[direct];
                while (x < 0 || x >= n || y < 0 || y >= m || visit[y][x]) {
                    x -= dx[direct];
                    y -= dy[direct];
                    direct = (direct + 1) % 4;
                    x += dx[direct];
                    y += dy[direct];
                }
            }
        }
        return ans;
    }
};

int main(){

}