//551. Student Attendance Record I
//You are given a string representing an attendance record for a student. The record only contains the following three characters:
//
//'A' : Absent.
//'L' : Late.
//'P' : Present.
//A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
//You need to return whether the student could be rewarded according to his attendance record.
//
//Example 1:
//Input: "PPALLP"
//Output: True
//Example 2:
//Input: "PPALLL"
//Output: False


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
    bool checkRecord(string s) {
        bool a = false;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == 'A'){
                if (a)
                    return false;
                else
                    a = true;
            }
            if (s[i] == 'L' && i < s.size()-2 && s[i+1] == 'L' && s[i+2] == 'L')
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

