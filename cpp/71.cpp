//71. Simplify Path
//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//        path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//Did you consider the case where path = "/../"?
//                                       In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".


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
    string simplifyPath(string path) {
        int i = 1;
        string r;
        while (i < path.size()){
            auto n = path.find('/',i);
            if (n == i){
                ++i;
                continue;
            }
            if (n == string::npos)
                n = path.size();
            string c = path.substr(i,n-i);
            if (c == ".")
                i = n+1;
            else if (c == "..")
                if (r.size()){
                    int p = r.rfind('/');
                    r = r.substr(0,p);
                }
            else
                r += '/' + c;
        }
        if (!r.size())
            return "/";
        return r;
    }
};

int main() {
    Solution s;
    string a = "52345";
    cout << a.rfind('5',3);
    return 0;
}
