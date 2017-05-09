//273. Integer to English Words
//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
//For example,
//123 -> "One Hundred Twenty Three"
//12345 -> "Twelve Thousand Three Hundred Forty Five"
//1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


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
    vector<string> number{"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tens{"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string nn(int num){
        string r;
        int h = num / 100;
        if (h > 0)
            r += number[h] + " Hundred";
        int low = num % 100;
        if (low > 0 && low <= 19){
            if (h > 0)
                r += " ";
            r += number[low];
        }
        else {
            int ten = low / 10, one = low % 10;
            if (ten > 1){
                if (h > 0)
                    r += " ";
                r += tens[ten];
            }
            if (one > 0){
                if (h > 0 && ten <= 1)
                    r += " ";
                else if (ten > 1)
                    r += " ";
                r += number[one];
            }
        }
        return r;
    }
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        string r;
        int b = num / 1000000000;
        if (b > 0)
            r += nn(b) + " Billion";
        num %= 1000000000;
        int m = num / 1000000;
        if (m > 0){
            if (b > 0)
                r += " ";
            r += nn(m) + " Million";
        }
        num %= 1000000;
        int t = num / 1000;
        if (t > 0){
            if (r.size())
                r += " ";
            r += nn(t) + " Thousand";
        }
        num %= 1000;
        if (num > 0){
            if (r.size())
                r += " ";
            r += nn(num);
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
