//451. Sort Characters By Frequency
//Given a string, sort it in decreasing order based on the frequency of characters.
//
//Example 1:
//
//Input:
//"tree"
//
//Output:
//"eert"
//
//Explanation:
//'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//Example 2:
//
//Input:
//"cccaaa"
//
//Output:
//"cccaaa"
//
//Explanation:
//        Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//Note that "cacaca" is incorrect, as the same characters must be together.
//Example 3:
//
//Input:
//"Aabb"
//
//Output:
//"bbAa"
//
//Explanation:
//"bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.


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

unordered_map<int,int> m;
bool cmp(int p, int q){
    return m[p] > m[q];
}
class Solution {
public:
    string frequencySort(string s) {
        m.clear();
        vector<int> r;
        for (auto i : s)
            m[i]++;
        for (auto i : m)
            r.push_back(i.first);
        sort(r.begin(),r.end(),cmp);
        string result;
        for (auto i : r)
            for (int j = 0; j < m[i]; ++j)
                result.push_back(i);
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

