# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        i = 0
        a = 0
        while l1 != None :
            i = i + l1.val * 10 ** a
            l1 = l1.next
            a += 1
        j = 0
        a = 0
        while l2 != None :
            j = j + l2.val * 10 ** a
            l2 = l2.next
            a += 1
        i += j
        print i
        head = ListNode(i % 10)
        now = head
        i /= 10
        while i != 0 :
            now.next = ListNode(i % 10)
            now = now.next
            i /= 10
        return head


a1 = ListNode(1)
a2 = ListNode(2)
a3 = ListNode(3)
a1.next = a2
a2.next = a3
b1 = ListNode(1)
b2 = ListNode(1)
b3 = ListNode(1)
b1.next = b2
b2.next = b3
s = Solution()
s.addTwoNumbers(a1,b1)