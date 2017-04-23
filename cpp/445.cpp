//445. Add Two Numbers II
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up:
//What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//Example:
//
//        Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current;
        int x1 = 0, x2 = 0;
        current = l1;
        while (current){
            ++x1;
            current= current->next;
        }
        current = l2;
        while (current){
            ++x2;
            current = current->next;
        }
        current = NULL;
        while (x1 && x2){
            int sum = 0;
            if (x1 >= x2){
                sum += l1->val;
                l1 = l1->next;
                --x1;
            }
            if (x1 < x2){
                sum += l2->val;
                l2 = l2->next;
                --x2;
            }
            ListNode *temp = new ListNode(sum);
            temp->next = current;
            current = temp;
        }
        int c = 0;
        ListNode *result = NULL, *del;
        while (current){
            current->val += c;
            c = current->val / 10;
            ListNode *temp = new ListNode(current->val % 10);
            temp->next = result;
            result = temp;
            del = current;
            current = current->next;
            delete del;
        }
        if (c){
            ListNode *temp = new ListNode(1);
            temp->next = result;
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

