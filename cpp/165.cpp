//165. Compare Version Numbers
//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//0.1 < 1.1 < 1.2 < 13.37

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto it1 = version1.begin();
        auto it2 = version2.begin();
        int v1,v2,x1,x2;
        while (true){
            x1 = 0;
            x2 = 0;
            if (it1 == version1.end()){
                if (it2 == version2.end())
                    return 0;
                else {
                    x1 = 1;
                }
            }
            if (it2 == version2.end())
                x2 = 0;
            v1 = 0;
            v2 = 0;
            if (x1 == 0) {
                while (*it1 != '.' && it1 != version1.end()) {
                    v1 = v1 * 10 + *it1 - '0';
                    ++it1;
                }
                if (*it1 == '.')
                    ++it1;
            }
            if (x2 == 0) {
                while (*it2 != '.' && it2 != version2.end()) {
                    v2 = v2 * 10 + *it2 - '0';
                    ++it2;
                }
                if (*it2 == '.')
                    ++it2;
            }
            if (v1 < v2)
                return -1;
            if (v1 > v2)
                return 1;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

