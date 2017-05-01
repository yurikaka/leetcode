//214. Shortest Palindrome
//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
//For example:
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string front, temp;
        int l = s.size();
        int i = 0, j = l-1, last = l-1;
        while (i < j){
            if (s[i] != s[j]){
                front.push_back(s[last]);
                i = 0;
                --last;
                j = last;
            }
            else {
                ++i;
                --j;
            }
        }
        return front + s;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}