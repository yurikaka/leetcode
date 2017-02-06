# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if not head:
            return None
        lh = ListNode(-1)
        rh = ListNode(-1)
        left = lh
        right = rh
        while head:
            if head.val < x:
                left.next = head
                left = head
            else:
                right.next = head
                right = head
            head = head.next
        right.next = None
        left.next = rh.next
        return lh.next

s = Solution()
l1 = ListNode(2)
l2 = ListNode(1)
l1.next = l2
print s.partition(l1,2)