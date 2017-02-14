# 142. Linked List Cycle II

# Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

# Note: Do not modify the linked list.

# Follow up:
# Can you solve it without using extra space?

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
        	return None

        fast = head
        slow = head
        first = False
        while fast.next:
        	if not fast.next.next:
        		break
        	fast = fast.next.next
        	slow = slow.next
        	if fast == slow:
        		first = True
        		break
        if not first:
        	return None
        slow = head
        while True:
        	if fast == slow:
        		return fast
        	fast = fast.next
        	slow = slow.next
        	