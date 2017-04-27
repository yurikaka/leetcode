//109. Convert Sorted List to Binary Search Tree
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

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

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* so(ListNode* head, int l){
        if (!l)
            return NULL;
        ListNode *current = head, *r = new ListNode(0);
        r->next = head;
        ListNode *last = r;
        int left = (l-1)/2;
        int cnt = 0;
        while (cnt < left){
            last = last->next;
            current = current->next;
            cnt++;
        }
        last->next = NULL;
        delete r;
        TreeNode *root = new TreeNode(current->val);
        root->left = so(head,left);
        root->right = so(current->next,l-left-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode * current = head;
        while (current){
            cnt++;
            current = current->next;
        }
        if (!cnt)
            return NULL;
        return so(head,cnt);
    }
};

int main() {
    return 0;
}

