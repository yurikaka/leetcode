//206. Reverse Linked List
//Reverse a singly linked list.

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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = NULL, *temp;
        while (head){
            temp = new ListNode(head->val);
            temp->next = current;
            current = temp;
            head = head->next;
        }
        return current;
    }
};

int main() {
    Solution s;
    return 0;
}

