//275. H-Index II
//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?


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
    int hIndex(vector<int>& citations) {
        int result = 0;
        int h = 0;
        for (int i = citations.size()-1; i > -1; --i){
            ++h;
            if (citations[i] >= h)
                result = h;
            else
                return result;
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

