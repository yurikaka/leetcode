# 203. Remove Linked List Elements
#
# Remove all elements from a linked list of integers that have value val.
#
# Example
# Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
# Return: 1 --> 2 --> 3 --> 4 --> 5

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return None
        _head = ListNode(0)
        _head.next = head
        current = head
        last = _head
        while current:
            if current.val == val:
                current = current.next
                last.next = current
                continue
            last = current
            current = current.next
        return _head.next