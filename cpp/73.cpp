//73. Set Matrix Zeroes
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int p = -1;
        bool found;
        for (int i = 0; i < m; ++i){
            found = false;
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == 0)
                    found = true;
            }
            if (found)
                p = i;
        }
        if (p != -1){
            for (int j = 0; j < n; ++j){
                found = false;
                for (int i = 0; i < m; ++i){
                    if (matrix[i][j] == 0)
                        found = true;
                }
                if (found)
                    matrix[p][j] = 0;
            }
            for (int i = 0; i < m; ++i){
                if (i == p)
                    continue;
                found = false;
                for (int j = 0; j < n; ++j){
                    if (matrix[i][j] == 0)
                        found = true;
                }
                if (found)
                    for (int j = 0; j < n; ++j)
                        matrix[i][j] = 0;
            }
            for (int j = 0; j < n; ++j)
                if (matrix[p][j] == 0)
                    for (int i = 0; i < m; ++i)
                        matrix[i][j] = 0;
            for (int j = 0 ; j < n; ++j)
                matrix[p][j] = 0;
            return;
        }
        for (int j = 0; j < n; ++j) {
            found = false;
            for (int i = 0; i < m; ++i)
                if (matrix[i][j] == 0)
                    found = true;
            if (found)
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
        }
    }
};
int main() {
    Solution s;

    return 0;
}

