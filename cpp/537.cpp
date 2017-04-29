//537. Complex Number Multiplication
//Given two strings representing two complex numbers.
//
//You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//
//Example 1:
//Input: "1+1i", "1+1i"
//Output: "0+2i"
//Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
//Example 2:
//Input: "1+-1i", "1+-1i"
//Output: "0+-2i"
//Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
//Note:
//
//        The input strings will not have extra blank.
//The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.


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
#include <stack>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string m, n, p, q;
        int i = a.find('+');
        for (int j = 0; j < i; ++j)
            m.push_back(a[j]);
        for (int j = i+1; j < a.size()-1; ++j)
            n.push_back(a[j]);
        i = b.find('+');
        for (int j = 0; j < i; ++j)
            p.push_back(b[j]);
        for (int j = i+1; j < b.size()-1; ++j)
            q.push_back(b[j]);
        int r1 = stoi(m)*stoi(p) - stoi(n)*stoi(q);
        int r2 = stoi(m)*stoi(q) + stoi(n)*stoi(p);
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution s;
    s.complexNumberMultiply("1+1i","1+1i");
    return 0;
}

