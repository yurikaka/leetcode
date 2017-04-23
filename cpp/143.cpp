//143. Reorder List
//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//        Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        int l = 0, i = 0;
        ListNode *current = head,*c2,*last,*next;
        while (current){
            ++l;
            current = current->next;
        }
        if (l <= 1)
            return;
        current = head;
        for (i = 0; i < l/2+l%2-1; ++i)
            current = current->next;
        c2 = current->next;
        current->next = NULL;
        if (l/2 == 1){
            current = head->next;
            head->next = c2;
            c2->next = current;
            return;
        }
        last = c2;
        current = c2->next;
        last->next = NULL;
        while (current){
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        c2 = last;
        current = head;
        while (c2){
            next = current->next;
            last = c2->next;
            current->next = c2;
            c2->next = next;
            current = next;
            c2 = last;
        }
    }
};

int main() {
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = a;
    b->next = new ListNode(2);
    b = b->next;
    b->next = new ListNode(3);
    b= b->next;
    b->next = new ListNode(4);
    b = b->next;
    b->next = new ListNode(5);
    while (b) {
        cout << b->val << endl;
        b = b->next;
    }
    return 0;
}

