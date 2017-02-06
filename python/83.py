# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        now = head
        while now.next:
            if now.next.val == now.val:
                now.next = now.next.next
            else:
                now = now.next
        return head


l1 = ListNode(1)
l2 = ListNode(2)
l1.next = l2
s = Solution()
s.deleteDuplicates(l1)