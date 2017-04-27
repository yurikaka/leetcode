//25. Reverse Nodes in k-Group
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//        Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

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
    pair<ListNode*,ListNode*> re(ListNode* head, int k){
        ListNode *last = head;
        ListNode *current = head->next, *next, *end;
        end = head;
        last->next = NULL;
        while (current){
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        return pair<ListNode*,ListNode*>(last,end);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;
        ListNode *r = new ListNode(0);
        r->next = head;
        ListNode *last = r;
        ListNode *current = head;
        while (current){
            int cnt = 1;
            ListNode *begin = current, *next;
            while (current && cnt < k){
                ++cnt;
                current = current->next;
            }
            if (current){
                next = current->next;
                current->next = NULL;
                current = next;
                pair<ListNode*,ListNode*> p = re(begin,k);
                last->next = p.first;
                last = p.second;
            } else {
                last->next = begin;
            }
        }
        return r->next;
    }
};

int main() {
    return 0;
}

