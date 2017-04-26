//352. Data Stream as Disjoint Intervals
//Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//
//For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
//
//[1, 1]
//[1, 1], [3, 3]
//[1, 1], [3, 3], [7, 7]
//[1, 3], [7, 7]
//[1, 3], [6, 7]
//Follow up:
//What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?


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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<Interval> r;
    int l;
    SummaryRanges() {
        r.clear();
        l = 0;
    }

    void addNum(int val) {
        for (int i = 0; i < l; ++i){
            if (val < r[i].start - 1){
                r.insert(r.begin()+i,Interval(val,val));
                ++l;
                cout << "1" << endl;
                return;
            }
            if (val == r[i].start - 1){
                r[i].start = val;
                cout << "2" << endl;
                return;
            }
            if (val >= r[i].start && val <= r[i].end)
                return;
            if (val == r[i].end + 1){
                r[i].end = val;
                if (i < l-1 && r[i+1].start == val + 1){
                    r[i].end = r[i+1].end;
                    r.erase(r.begin()+i+1);
                    --l;
                }
                cout << "3" << endl;
                return;
            }
        }
        r.push_back(Interval(val,val));
        ++l;
    }

    vector<Interval> getIntervals() {
        return r;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main() {
    return 0;
}

