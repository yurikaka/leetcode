//56. Merge Intervals
//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//        Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].


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


// * Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool can(Interval p, Interval q){
        if (p.start <= q.start && p.end >= q.start)
            return true;
        else if (p.start <= q.end && p.end >= q.end)
            return true;
        else if (p.start >= q.start && p.end <= q.end)
            return true;
        else
            return false;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        for (auto i : intervals){
            bool merge = false;
            for (auto j = result.begin(); j != result.end(); ++j)
                if (can(i,*j)){
                    merge = true;
                    j->start = min(i.start,j->start);
                    j->end = max(i.end,j->end);
                    for (auto k = j+1; k != result.end();){
                        if (can(*j,*k)){
                            j->start = min(k->start,j->start);
                            j->end = max(k->end,j->end);
                            result.erase(k);
                            continue;
                        }
                        ++k;
                    }
                    break;
                }
            if (!merge)
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

