//65. Valid Number
//Validate if a given string is numeric.
//
//Some examples:
//"0" => true
//" 0.1 " => true
//"abc" => false
//"1 a" => false
//"2e10" => true
//Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.


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
    bool isNumber(string s) {
        bool sci = false, dot = false, neg = false;
        while (s.size()){
            if (s[0] == ' ')
                s.erase(s.begin());
            else
                break;
        }
        while (s.size()){
            if (s.back() == ' ')
                s.erase(s.end()-1);
            else
                break;
        }
        if (!s.size())
            return false;
        if (s[0] == '-' || s[0] == '+')
            s.erase(s.begin());
        for (int i = 0; i < s.size(); ++i){
            char c = s[i];
            if (!sci && c == 'e' && i != s.size() - 1) {
                if (i == 0)
                    return false;
                sci = true;
                if (!neg && (s[i+1] == '-' || s[i+1] == '+')) {
                    s[i + 1] = 'e';
                    sci = false;
                    neg = true;
                }
            }
            else if (!dot && !sci && c =='.') {
                if (!((i!=0 && isdigit(s[i-1])) || (i != s.size()-1 && isdigit(s[i+1]))))
                    return false;
                dot = true;
            }
            else if (!isdigit(c))
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
