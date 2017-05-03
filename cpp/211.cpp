//211. Add and Search Word - Data structure design
//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//        You may assume that all words are consist of lowercase letters a-z.


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

struct trienode{
    trienode* next[26] = {NULL};
    bool word = false;
};

class WordDictionary {
public:
    trienode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new trienode;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        trienode* current = root;
        for (auto c : word){
            if (current->next[c-'a'] == NULL)
                current->next[c-'a'] = new trienode;
            current = current->next[c-'a'];
        }
        current->word = true;
    }

    bool ss(string s, trienode* r){
        trienode* current = r;
        for (int j = 0; j < s.size(); ++j){
            char c = s[j];
            if (c == '.'){
                for (int i = 0; i < 26; ++i){
                    if (current->next[i] && ss(s.substr(j+1),current->next[i]))
                        return true;
                }
                return false;
            }
            if (current->next[c-'a'] == NULL)
                return false;
            current = current->next[c-'a'];
        }
        return current->word;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return ss(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() {
    Solution s;
    return 0;
}
