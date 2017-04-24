//148. Sort List
//Sort a linked list in O(n log n) time using constant space complexity.


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <queue>

using namespace std;


// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        int l = 0;
        ListNode *current, *result;
        current = head;
        while (current){
            ++l;
            current = current->next;
        }
        result = new ListNode(0);
        result->next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < l; step*=2){
            tail = result;
            current = tail->next;
            while (current){
                left = current;
                right = this->split(left,step);
                current = this->split(right,step);
                tail = this->merge(left,right,tail);
            }
        }
        return result->next;
    }
    ListNode* split(ListNode* head, int step){
        for (int i = 1; head && i < step; ++i){
            head = head->next;
        }
        if (!head)
            return NULL;
        ListNode* temp = head->next;
        head->next = NULL;
        return temp;
    }
    ListNode* merge(ListNode* l, ListNode* r, ListNode* t){
        while (l && r){
            if (l->val < r->val){
                t->next = l;
                t = l;
                l = l->next;
            } else {
                t->next = r;
                t = r;
                r = r->next;
            }
        }
        if (l)
            t->next = l;
        else
            t->next = r;
        while (t->next)
            t = t->next;
        return t;
    }
};

int main() {
    Solution s;

    return 0;
}

