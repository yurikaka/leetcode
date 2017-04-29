//68. Text Justification
//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//For example,
//        words: ["This", "is", "an", "example", "of", "text", "justification."]
//L: 16.
//
//Return the formatted lines as:
//[
//"This    is    an",
//"example  of text",
//"justification.  "
//]
//Note: Each word is guaranteed not to exceed L in length.


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
    void ll(vector<string>& words, vector<string>& result, int maxWidth) {
        string r;
        for (int i = 0; i < words.size()-1; ++i){
            r += words[i];
            r.push_back(' ');
        }
        r += words[words.size()-1];
        int j = maxWidth - r.size();
        for (int i = 0; i < j; ++i){
            r.push_back(' ');
        }
        result.push_back(r);
        return;
    }
    void ff(vector<string>& words, vector<string>& result, int maxWidth) {
        string r;
        int cnt = words.size()-1;
        if (!cnt){
            r = words[0];
            int j = maxWidth - r.size();
            for (int i = 0; i < j; ++i){
                r.push_back(' ');
            }
            result.push_back(r);
            return;
        }
        int all = 0;
        for (auto i : words)
            all += i.size();
        int space = (maxWidth-all)/cnt;
        int que = 0;
        if ((maxWidth-all)%cnt){
            space += 1;
            que = cnt - (maxWidth-all)%cnt;
        }
        r = words[0];
        for (int i = 0; i < cnt; ++i){
            if (cnt - i <= que)
                for (int j = 0; j < space-1; ++j)
                    r.push_back(' ');
            else
                for (int j = 0; j < space; ++j)
                    r.push_back(' ');
            r += words[i+1];
        }
        result.push_back(r);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left;
        vector<string> line, result;
        int i,b = 0;
        while (b < words.size()){
            left = maxWidth;
            line.clear();
            for (i = b; i < words.size(); ++i){
                if (int(words[i].size()) <= left){
                    line.push_back(words[i]);
                    left -= words[i].size() + 1;
                }
                else
                    break;
            }
            if (i >= words.size()){
                ll(line,result,maxWidth);
            } else
                ff(line,result,maxWidth);
            b = i;
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

