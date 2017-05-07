//576. Out of Boundary Paths My SubmissionsBack To Contest
//There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
//
//Example 1:
//Input:m = 2, n = 2, N = 2, i = 0, j = 0
//Output: 6
//Explanation:
//
//        Example 2:
//Input:m = 1, n = 3, N = 3, i = 0, j = 1
//Output: 12
//Explanation:
//
//        Note:
//Once you move the ball out of boundary, you cannot move it back.
//The length and height of the grid is in range [1,50].
//N is in range [0,50].

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
#include <math.h>

using namespace std;

long long M = 1000000007;

class Solution {
public:
    map< pair<int,pair<int,int>> ,int > mm;
    int findPaths(int m, int n, int N, int i, int j) {
        if (mm.count(pair<int,pair<int,int>>(N,pair<int,int>(i,j)))!=0)
            return mm[pair<int,pair<int,int>>(N,pair<int,int>(i,j))];
        int mini = min(min(i,j),min(m-i-1,n-j-1)) + 1;
        if (N < mini)
            return 0;
        if (N == mini) {
            mm[pair<int,pair<int,int>>(N,pair<int,int>(i,j))] = (i + 1 == mini) + (j + 1 == mini) + (m - i == mini) + (n - j == mini);
            return (i + 1 == mini) + (j + 1 == mini) + (m - i == mini) + (n - j == mini);
        }
        else {
            long long r = 0;
            if (i)
                r += findPaths(m, n, N - 1, i - 1, j);
            else
                ++r;
            r %= M;
            if (j)
                r += findPaths(m,n,N-1,i,j-1);
            else
                ++r;
            r %= M;
            if (i != m-1)
                r += findPaths(m,n,N-1,i+1,j);
            else
                ++r;
            r %= M;
            if (j != n-1)
                r += findPaths(m,n,N-1,i,j+1);
            else
                ++r;
            r %= M;
            mm[pair<int,pair<int,int>>(N,pair<int,int>(i,j))] = int(r);
            return int(r);
        }
    }
};

int main() {
    return 0;
}