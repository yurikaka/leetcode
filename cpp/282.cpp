//282. Expression Add Operators
//Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
//Examples:
//"123", 6 -> ["1+2+3", "1*2*3"]
//"232", 8 -> ["2*3+2", "2+3*2"]
//"105", 5 -> ["1*0+5","10-5"]
//"00", 0 -> ["0+0", "0-0", "0*0"]
//"3456237490", 9191 -> []

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

using namespace std;

class Solution {
public:
    void add(vector<string>& result, string past, string num, int target, int pos, long value, long prev){
        if (pos == num.size()){
            if (value == target)
                result.push_back(past);
            return;
        }
        for (int i = pos; i < num.size(); ++i){
            if (num[pos] == '0' && i > pos)
                break;
            string sub = num.substr(pos, i-pos+1);
            long val = stol(sub);
            if (pos == 0)
                add(result,sub,num,target,i+1,val,val);
            else {
                add(result,past+"+"+sub,num,target,i+1,value+val,val);
                add(result,past+"-"+sub,num,target,i+1,value-val,-val);
                add(result,past+"*"+sub,num,target,i+1,value-prev+prev*val,prev*val);
            }
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (!num.size())
            return result;
        add(result,"",num,target,0,0,0);
        return result;
    }
};

int main() {
    return 0;
}

