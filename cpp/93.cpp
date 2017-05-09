//93. Restore IP Addresses
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


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
    vector<string> restoreIpAddresses(string s) {
        int l = s.size();
        vector<string> r;
        if (l > 12)
            return r;
        for (int i = l-9; i <= l-3; ++i){
            if (i < 1)
                continue;
            if (s[0] == '0' && i > 1)
                break;
            int w = stoi(s.substr(0,i));
            if (i > 3 || w > 255)
                break;
            for (int j = l-i-6; j <= l-i-2; ++j){
                if (j < 1)
                    continue;
                if (s[i] == '0' && j > 1)
                    break;
                int x = stoi(s.substr(i,j));
                if (j > 3 || x > 255)
                    break;
                for (int m = l-i-j-3; m <= l-i-j-1; ++m){
                    if (m < 1)
                        continue;
                    if (s[i+j] == '0' && m > 1)
                        break;
                    int y = stoi(s.substr(i+j,m));
                    if (m > 3 || y > 255)
                        break;
                    int n = l-i-j-m;
                    if (n < 1)
                        break;
                    if (s[i+j+m] == '0' && n > 1)
                        continue;
                    int z = stoi(s.substr(i+j+m));
                    if (z < 256)
                        r.push_back(to_string(w)+"."+to_string(x)+"."+to_string(y)+"."+to_string(z));
                }
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
