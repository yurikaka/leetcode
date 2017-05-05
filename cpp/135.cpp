//135. Candy
//There are N children standing in a line. Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements:
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?


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

class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size(), r = 0;
        if (!l)
            return 0;
        vector<int> next;
        for (int i = 0; i < l; ++i)
            next.push_back(i);

        sort(next.begin(),next.end(),[&ratings](int p, int q){
            return ratings[p] < ratings[q];
        });
        vector<int> c(l,0);
        for (auto i : next){
            int cc = 1;
            if (i)
                if (ratings[i-1] < ratings[i])
                    cc = max(cc,c[i-1]+1);
            if (i!=l-1)
                if (ratings[i+1] < ratings[i])
                    cc = max(cc,c[i+1]+1);
            c[i] = cc;
            r+= cc;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
