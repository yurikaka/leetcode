# 234. Palindrome Linked List
#
# Given a singly linked list, determine if it is a palindrome.
#
# Follow up:
# Could you do it in O(n) time and O(1) space?

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return True
        current = head
        cnt = 0
        while current:
            cnt += 1
            current = current.next
        cnt /= 2
        current = head
        for i in xrange(cnt):
            current = current.next
        _head = None
        while current:
            temp = current.next
            current.next = _head
            _head = current
            current = temp
        current = head
        _current = _head
        for i in xrange(cnt):
            if current.val != _current.val:
                return False
            current = current.next
            _current = _current.next
        return True