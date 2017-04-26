//228. Summary Ranges
//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].


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
            if (val < r[i].start - 1 && r[i].start != INT_MIN){
                r.insert(r.begin()+i,Interval(val,val));
                ++l;
                return;
            }
            if (val == r[i].start - 1 && r[i].start != INT_MIN){
                r[i].start = val;
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

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        SummaryRanges* vr = new SummaryRanges();
        for (auto i : nums)
            vr->addNum(i);
        vector<Interval> vi = vr->getIntervals();
        vector<string> vs;
        for (auto i : vi){
            string temp = "";
            if (i.end != i.start)
                temp = """" + to_string(i.start) + "->" + to_string(i.end) + """";
            else
                temp = to_string(i.start);
            vs.push_back(temp);
        }
        return vs;
    }
};

int main() {
    return 0;
}

