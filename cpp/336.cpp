//336. Palindrome Pairs
//Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
//Example 1:
//Given words = ["bat", "tab", "cat"]
//Return [[0, 1], [1, 0]]
//The palindromes are ["battab", "tabbat"]
//Example 2:
//Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

#include <iostream>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool p(string s){
        int l = s.size();
        int i = 0, j = l-1;
        while (i<j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> m;
        vector<vector<int>> r;
        int l = words.size();
        for (int i = 0; i < l; ++i){
            string s = words[i];
            reverse(s.begin(),s.end());
            m[s] = i;
        }
        if (m.find("")!=m.end()){
            int n = m[""];
            for (int i = 0; i < l; ++i){
                if (i == n)
                    continue;
                if (p(words[i])){
//                    r.push_back(vector<int>{i,n});
                    r.push_back(vector<int>{n,i});
                }
            }
        }
        for (int i = 0; i < l; ++i){
            int ll = words[i].size();
            for (int j = 0; j < ll; ++j){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j,ll-j);
                if (m.find(left)!=m.end() && p(right) && m[left]!=i)
                    r.push_back(vector<int>{i,m[left]});
                if (m.find(right)!=m.end() && p(left) && m[right]!=i)
                    r.push_back(vector<int>{m[right],i});
            }
        }
        return r;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}