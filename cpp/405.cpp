//405. Convert a Number to Hexadecimal
//Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
//
//Note:
//
//        All letters in hexadecimal (a-f) must be in lowercase.
//The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
//The given number is guaranteed to fit within the range of a 32-bit signed integer.
//You must not use any method provided by the library which converts/formats the number to hex directly.
//Example 1:
//
//Input:
//26
//
//Output:
//"1a"
//Example 2:
//
//Input:
//-1
//
//Output:
//"ffffffff"

#include <iostream>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        bitset<32> a(num);
        string r;
        for (int i = 31; i > -1; i -=4){
            int sum = 0;
            for (int j = 0; j < 4; ++j){
                sum = sum * 2 + a[i-j];
            }
            if (sum <= 9)
                r.push_back('0'+sum);
            else {
                char c;
                switch (sum){
                    case 10: c = 'a';
                        break;
                    case 11: c = 'b';
                        break;
                    case 12: c = 'c';
                        break;
                    case 13: c = 'd';
                        break;
                    case 14: c = 'e';
                        break;
                    case 15: c = 'f';
                }
                r.push_back(c);
            }
        }
        while (r.size()){
            if (r[0] == '0')
                r.erase(r.begin());
            else
                break;
        }
        if (!r.size())
            return "0";
        return r;
    }
};

int main() {
    return 0;
}