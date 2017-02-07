# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k == 0:
            return head
        current = head
        length = 1
        while current.next:
            current = current.next
            length += 1
        if length == k:
            return head
        k %= length
        current = head
        for i in range(length-k-1):
            current = current.next
        end = current
        current = current.next
        end.next = None
        newhead = current
        if not current:
            return head
        while current.next:
            current = current.next
        current.next = head
        return newhead