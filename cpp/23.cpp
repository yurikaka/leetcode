//23. Merge k Sorted Lists
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode *rr = new ListNode(0), *next;
        ListNode *c = rr;
        while (l && r){
            if (l->val < r->val){
                next = l->next;
                l->next = NULL;
                c->next = l;
                c = c->next;
                l = next;
            } else {
                next = r->next;
                r->next = NULL;
                c->next = r;
                c = c->next;
                r = next;
            }
        }
        if (l)
            c->next = l;
        else
            c->next = r;
        return rr->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (!k)
            return NULL;
        ListNode *r = lists[0];
        for (int i = 1; i < k; ++i)
            r = merge(r,lists[i]);
        return r;
    }
};
int main() {
    return 0;
}

