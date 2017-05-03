//208. Implement Trie (Prefix Tree)
//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//        You may assume that all inputs are consist of lowercase letters a-z.


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

class Trie {
public:
    trienode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trienode;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        trienode *current = root;
        for (char c : word){
            if (current->next[c-'a'] == NULL)
                current->next[c-'a'] = new trienode;
            current = current->next[c-'a'];
        }
        current->word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        trienode* current = root;
        for (char c : word){
            if (current->next[c-'a'] == NULL)
                return false;
            current = current->next[c-'a'];
        }
        return current->word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trienode* current = root;
        for (char c : prefix){
            if (current->next[c-'a'] == NULL)
                return false;
            current = current->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    Solution s;
    return 0;
}
