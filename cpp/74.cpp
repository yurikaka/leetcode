//74. Search a 2D Matrix
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//        Consider the following matrix:
//
//[
//[1,   3,  5,  7],
//[10, 11, 16, 20],
//[23, 30, 34, 50]
//]
//Given target = 3, return true.


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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        int n = matrix[0].size();
        if (!n)
            return false;
        if (target < matrix[0][0])
            return false;
        for (int i = 0; i < m; ++i){
            if (target > matrix[i][n-1])
                continue;
            if (target < matrix[i][0])
                break;
            int l = 0, r = n - 1;
            while (l <= r){
                int m = (l+r)/2;
                if (target > matrix[i][m]) {
                    l = m+1;
                    continue;
                }
                if (target < matrix[i][m]) {
                    r = m-1;
                    continue;
                }
                else
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

