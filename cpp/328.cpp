//328. Odd Even Linked List
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//        Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//        The relative order inside both the even and odd groups should remain as it was in the input.
//The first node is considered odd, the second node even and so on ...

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *he = head->next;
        head->next = NULL;
        ListNode *current = he->next, *co = head, *ce = he, *next;
        he->next = NULL;
        bool o = true;
        while (current){
            next = current->next;
            current->next = NULL;
            if (o){
                co->next = current;
                co = co->next;
                o = false;
            } else {
                ce->next = current;
                ce = ce->next;
                o = true;
            }
            current = next;
        }
        co->next = he;
        return head;
    }
};

int main() {
    return 0;
}

