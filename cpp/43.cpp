//43. Multiply Strings
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
//
//Note:
//
//        The length of both num1 and num2 is < 110.
//Both num1 and num2 contains only digits 0-9.
//Both num1 and num2 does not contain any leading zero.
//You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int c = 0, s = 0, i, j;
        string result;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int product[220] = {0};
        for (i = 0; i < num1.size(); ++i){
            for (j = 0; j < num2.size(); ++j){
                s = c + (*(num1.begin()+i)-'0')*(*(num2.begin()+j)-'0') + product[i+j];
                c = s / 10;
                product[i+j] = s % 10;
            }
            s = product[i+j] + c;
            c = s / 10;
            product[i+j] = s % 10;
            product[i+j+1] += c;
        }
        cout << product[0] << "," << product[1] << "," << product[2] << "," << product[3] <<endl;
        bool zero = true;
        for (i = 219; i >= 0; --i){
            if (zero)
                if (product[i] != 0)
                    zero = false;
            if (!zero)
                result.push_back('0'+product[i]);
        }
        if (zero)
            result = "0";
        return result;
    }
};

int main() {
    Solution s;
    cout << s.multiply(string("13"),string("5"));
    return 0;
}

