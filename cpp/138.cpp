//138. Copy List with Random Pointer
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.




#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

using namespace std;

//* Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        RandomListNode *current, *temp, *result;
        current = head;
        while (current){
            temp = current->next;
            current->next = new RandomListNode(current->label);
            current->next->next = temp;
            current = temp;
        }
        current = head;
        while (current){
            if (current->random)
                current->next->random = current->random->next;
            current = current->next->next;
        }
        current = head;
        result = new RandomListNode(0);
        temp = result;
        while (current){
            temp->next = current->next;
            temp = temp->next;
            current->next = current->next->next;
            current = current->next;
        }
        return result->next;
    }
};

int main() {
    Solution s;

    return 0;
}

