//472. Concatenated Words
//Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
//
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
//
//Example:
//        Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Note:
//        The number of elements of the given array will not exceed 10,000
//The length sum of elements in the given array will not exceed 600,000.
//All the input string will only include lower case letters.
//The returned elements order does not matter.


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

using namespace std;

bool cmp(string p, string q){
    return p.size() < q.size();
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        vector<string> r;
        for (auto w : words){
            int l = w.size();
            int dp[l+1] = {0};
            dp[0] = 1;
            for (int i = 0 ; i < l; ++i){
                if (dp[i] == 0)
                    continue;
                for (int j = i+1; j <= l; ++j){
                    if (j-i < l && s.count(w.substr(i,j-i))!=0)
                        dp[j] = 1;
                }
                if (dp[l]){
                    r.push_back(w);
                    break;
                }
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> a{1,2,3,4,5};
    cout << find(a.begin(),a.begin()+2,5)-a.begin() << endl;
    return 0;
}
