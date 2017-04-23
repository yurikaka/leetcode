//92. Reverse Linked List II
//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//        Given m, n satisfy the following condition:
//1 ≤ m ≤ n ≤ length of list.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;



// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode *current,*last,*next,*end,*begin,*_head;
        current = new ListNode(0);
        current->next = head;
        _head = current;
        int i = 0;
        while (i < m-1){
            current = current->next;
            ++i;
        }
        begin = current;
        current = current->next;
        ++i;
        last = current;
        end = last;
        current = current->next;
        while (i < n){
            next = current->next;
            current->next = last;
            last = current;
            current = next;
            ++i;
        }
        begin->next = last;
        end->next = current;
        return _head->next;
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
    b = s.reverseBetween(a,1,4);
    while (b) {
        cout << b->val << endl;
        b = b->next;
    }
    return 0;
}

