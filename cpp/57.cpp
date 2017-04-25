//57. Insert Interval
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


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

bool cmp(Interval p, Interval q){
    return p.start < q.start;
}
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it;
        bool merge = false;
        for (it = intervals.begin(); it != intervals.end(); ++it){
            if (can(newInterval,*it)){
                merge = true;
                it->start = min(it->start,newInterval.start);
                it->end = max(it->end,newInterval.end);
                break;
            }
        }
        if (merge){
            for (auto t = it+1; t != intervals.end();){
                if (can(*t,*it)){
                    it->start = min(it->start,t->start);
                    it->end = max(it->end,t->end);
                    intervals.erase(t);
                    continue;
                }
                ++t;
            }
        }
        else {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end(), cmp);
        }
        return intervals;
    }
};

int main() {
    Solution s;
    return 0;
}

