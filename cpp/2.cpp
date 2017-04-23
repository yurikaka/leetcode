//2. Add Two Numbers
//        You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0,s = 0;
        struct ListNode head(0);
        struct ListNode *current = &head;
        while (l1 || l2 || c){
            s = c;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            c = s / 10;
            s %= 10;
            current->next = new struct ListNode(s);
            current = current->next;
        }
        return head.next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

