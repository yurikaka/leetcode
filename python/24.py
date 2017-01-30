# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        _head = ListNode(0)
        _head.next = head
        current = _head
        while current.next and current.next.next:
            temp = current.next
            current.next = temp.next
            temp.next = current.next.next
            current.next.next = temp
            current = temp
        return _head.next

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l1.next = l2
l2.next = l3
# l3.next = l4
s = Solution()
ss = s.swapPairs(l1)
print ss.val,ss.next.val,ss.next.next.val