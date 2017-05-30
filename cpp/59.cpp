//59. Spiral Matrix II
//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//        Given n = 3,
//
//        You should return the following matrix:
//[
//[ 1, 2, 3 ],
//[ 8, 9, 4 ],
//[ 7, 6, 5 ]
//]

#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (!n)
            return vector<vector<int>>{};
        int cnt = n * n, cur = cnt;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, direct = 0;
        int x = 0, y = 0;
        while (++cur <= cnt){
            ans[y][x] = cur;
            if (cur != cnt) {
                x += dx[direct];
                y += dy[direct];
                while (x < 0 || x >= n || y < 0 || y >= n || ans[y][x]) {
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