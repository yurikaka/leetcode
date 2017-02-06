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
        same = False
        _head = ListNode(0)
        _head.next = head
        now = head
        _now = _head
        while now.next:
            if now.val == now.next.val:
                now.next = now.next.next
                same = True
            else:
                if same:
                    _now.next = _now.next.next
                else:
                    _now = _now.next
                same=False
                now = now.next
        if same:
            _now.next = _now.next.next
        return _head.next

s = Solution()
l1 = ListNode(1)
l2 = ListNode(1)
l1.next = l2
print s.deleteDuplicates(l1)