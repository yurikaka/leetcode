//147. Insertion Sort List
//Sort a linked list using insertion sort.


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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *next, *current, *last, *big, *result;
        bool found;
        if (!head)
            return head;
        current = head->next;
        result = new ListNode(0);
        result->next = head;
        head->next = NULL;
        while (current){
            last = result;
            big = result->next;
            found = false;
            while (big){
                if (current->val < big->val) {
                    last->next = current;
                    next = current->next;
                    current->next = big;
                    current = next;
                    found = true;
                    break;
                }
                last = big;
                big = big->next;
            }
            if (!found){
                last->next = current;
                next = current->next;
                current->next = NULL;
                current = next;
            }
        }
        return result->next;
    }
};

int main() {
    Solution s;

    return 0;
}

