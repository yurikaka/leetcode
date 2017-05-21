//593. Valid Square My SubmissionsBack To Contest
//Given the coordinates of four points in 2D space, return whether the four points could construct a square.
//
//The coordinate (x,y) of a point is represented by an integer array with two integers.
//
//Example:
//        Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: True
//Note:
//
//        All the input integers are in the range [-10000, 10000].
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
//Input points have no order.

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

int dist(vector<int> p, vector<int> q){
    return (p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
}

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> n{p1,p2,p3,p4};
        vector<int> d;
        for (int i = 0; i < 4; ++i)
            for (int j = i+1; j < 4; ++j)
                d.push_back(dist(n[i],n[j]));
        sort(d.begin(),d.end());
        int l1 = d[0], l2 = d[5];
        if (l2 == 2* l1 && d[1] == l1 && d[2] == l1 && d[3] == l1 && d[4] == l2 && l1 != 0)
            return true;
        return false;
    }
};

int main(){
    
}