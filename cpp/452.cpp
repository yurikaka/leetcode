//452. Minimum Number of Arrows to Burst Balloons
//There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
//
//An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
//
//Example:
//
//        Input:
//[[10,16], [2,8], [1,6], [7,12]]
//
//Output:
//2
//
//Explanation:
//        One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).


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

using namespace std;

bool cmp(pair<int, int> p, pair<int, int> q){
    return p.second < q.second || (p.second == q.second && p.first < q.first);
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int last = INT_MIN, r = 0;
        for (auto i : points){
            if (last >= i.first)
                continue;
            ++r;
            last = i.second;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
