//468. Validate IP Address
//Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
//
//IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
//
//Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
//
//IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
//
//However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
//
//Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
//
//Note: You may assume there is no extra space or special characters in the input string.
//
//Example 1:
//Input: "172.16.254.1"
//
//Output: "IPv4"
//
//Explanation: This is a valid IPv4 address, return "IPv4".
//Example 2:
//Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
//
//Output: "IPv6"
//
//Explanation: This is a valid IPv6 address, return "IPv6".
//Example 3:
//Input: "256.256.256.256"
//
//Output: "Neither"
//
//Explanation: This is neither a IPv4 address nor a IPv6 address.


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
#include <exception>

using namespace std;

class Solution {
public:
    string four(string IP){
        int pos[3];
        string s[4];
        int last = -1;
        for (int i = 0; i < 3; ++i){
            last = IP.find('.',last + 1);
            if (last == string::npos)
                return "Neither";
            pos[i] = last;
        }
        if (IP.find('.',last+1)!=string::npos)
            return "Neither";
        s[0] = IP.substr(0,pos[0]);
        s[1] = IP.substr(pos[0]+1,pos[1]-pos[0]-1);
        s[2] = IP.substr(pos[1]+1,pos[2]-pos[1]-1);
        s[3] = IP.substr(pos[2]+1);
        for (int i = 0; i < 4; ++i) {
            try{
                last = stoi(s[i]);
            } catch (exception &e) {
                return "Neither";
            }
            if (last < 0 || last > 255)
                return "Neither";
            for (char c : s[i])
                if (!isdigit(c))
                    return "Neither";
            if (s[i].size() > 1 && s[i][0] == '0')
                return "Neither";
        }
        return "IPv4";
    }
    string six(string IP){
        int pos[7];
        string s[8];
        int last = -1;
        for (int i = 0; i < 7; ++i){
            last = IP.find(':',last + 1);
            if (last == string::npos)
                return "Neither";
            pos[i] = last;
        }
        if (IP.find(':',last+1)!=string::npos)
            return "Neither";
        s[0] = IP.substr(0,pos[0]);
        s[1] = IP.substr(pos[0]+1,pos[1]-pos[0]-1);
        s[2] = IP.substr(pos[1]+1,pos[2]-pos[1]-1);
        s[3] = IP.substr(pos[2]+1,pos[3]-pos[2]-1);
        s[4] = IP.substr(pos[3]+1,pos[4]-pos[3]-1);
        s[5] = IP.substr(pos[4]+1,pos[5]-pos[4]-1);
        s[6] = IP.substr(pos[5]+1,pos[6]-pos[5]-1);
        s[7] = IP.substr(pos[6]+1);
        for (int i = 0; i < 8; ++i) {
            if (s[i].size() < 1 || s[i].size() > 4)
                return "Neither";
            for (char c : s[i]){
                if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
                    return "Neither";
            }
        }
        return "IPv6";
    }
    string validIPAddress(string IP) {
        if (IP.find('.') != string::npos)
            return four(IP);
        else
            return six(IP);
    }
};

int main() {
    Solution s;
    return 0;
}
