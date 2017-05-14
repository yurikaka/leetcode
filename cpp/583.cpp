//583. Delete Operation for Two Strings My SubmissionsBack To Contest
//Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.
//
//Example 1:
//Input: "sea", "eat"
//Output: 2
//Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
//Note:
//        The length of given words won't exceed 500.
//Characters in given words can only be lower-case letters.

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

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        int c[l1+1][l2+1];

        for (int i = 0; i <= l1; ++i)
            for (int j = 0; j <= l2; ++j){
                if (i == 0 || j == 0)
                    c[i][j] = 0;
                else if (word1[i-1] == word2[j-1])
                    c[i][j] = c[i-1][j-1]+1;
                else
                    c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
        return l1+l2-2*c[l1][l2];
    }
};

int main(){

}