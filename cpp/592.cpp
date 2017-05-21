//592. Fraction Addition and Subtraction My SubmissionsBack To Contest
//Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.
//
//Example 1:
//Input:"-1/2+1/2"
//Output: "0/1"
//Example 2:
//Input:"-1/2+1/2+1/3"
//Output: "1/3"
//Example 3:
//Input:"1/3-1/2"
//Output: "-1/6"
//Example 4:
//Input:"5/3+1/3"
//Output: "2/1"
//Note:
//        The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
//Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
//The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
//The number of given fractions will be in the range [1,10].
//The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

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
    string fractionAddition(string expression) {
        if (isdigit(expression[0]))
            expression = "+"+expression;
        int pos = 0,fenhao;
        char sig[2];
        sig[0] = expression[0];
        long long a1,b1,a2,b2;
        long long a, b, r;
        fenhao = expression.find('/',1);
        a1 = stoll(expression.substr(1,fenhao-1));
        pos = min(expression.find('+',fenhao+2),expression.find('-',fenhao+2));
        if (pos == string::npos)
            b1 = stoll(expression.substr(fenhao+1));
        else
            b1 = stoll(expression.substr(fenhao+1,pos-fenhao-1));
        while(pos != string::npos){
            sig[1] = expression[pos];
            fenhao = expression.find('/',pos+1);
            a2 = stoll(expression.substr(pos+1,fenhao-pos-1));
            pos = min(expression.find('+',fenhao+2),expression.find('-',fenhao+2));
            if (pos == string::npos)
                b2 = stoll(expression.substr(fenhao+1));
            else
                b2 = stoll(expression.substr(fenhao+1,pos-fenhao-1));
            a1 *= b2;
            if (sig[0] == '-')
                a1 = -a1;
            a2 *= b1;
            if (sig[1] == '-')
                a2 = - a2;
            a1 += a2;
            b1 *= b2;
            if (a1 < 0)
                sig[0] = '-';
            else
                sig[0] = '+';
            a1 =abs(a1);
            if (a1 == 0)
                b1 = 1;

            else {
                a = a1;
                b = b1;
                while (b){
                    r = a % b;
                    a = b;
                    b = r;
                }
                a1 /= a;
                b1 /= a;
            }
        }
        string rr;
        if (sig[0] == '-')
            rr.push_back('-');
        rr += to_string(a1) + "/" + to_string(b1);
        return rr;
    }
};

int main(){

}