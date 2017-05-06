//393. UTF-8 Validation
//A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
//
//For 1-byte character, the first bit is a 0, followed by its unicode code.
//For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
//This is how the UTF-8 encoding would work:
//
//        Char. number range  |        UTF-8 octet sequence
//        (hexadecimal)    |              (binary)
//--------------------+---------------------------------------------
//0000 0000-0000 007F | 0xxxxxxx
//0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
//Given an array of integers representing the data, return whether it is a valid utf-8 encoding.
//
//Note:
//        The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
//
//Example 1:
//
//data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
//
//Return true.
//It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
//Example 2:
//
//data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
//
//Return false.
//The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
//The next byte is a continuation byte which starts with 10 and that's correct.
//But the second continuation byte does not start with 10, so it is invalid.

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
    bool validUtf8(vector<int>& data) {
        int l = data.size();
        vector<bitset<8>> b;
        for (int i = 0; i < l; ++i)
            b.push_back(bitset<8>(data[i] & 0xff));
        if (l == 1){
            return !b[0][7];
        }
        int i = 0;
        while (i < l){
            int z = -1;
            for (int j = 7; j > -1; --j)
                if (b[i][j] == 0){
                    z = j;
                    break;
                }
            if (z == -1)
                return false;
            z = 7 - z;
            if (z == 0){
                ++i;
                continue;
            }
            else if (z == 1 || z > 4)
                return false;
            if (i+z-1>=l)
                return false;
            for (int j = 1; j <= z-1; ++j){
                if (b[i+j][7] != 1 || b[i+j][6] != 0)
                    return false;
            }
            i += z;
        }
        return true;
    }
};

int main() {
    int a = 510;
    bitset<8> b(a);
    cout << b[0] << b[7] << endl;
    return 0;
}