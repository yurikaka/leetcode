# 530. Minimum Absolute Difference in BST
#
# Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
#
# Example:
#
# Input:
#
#    1
#     \
#      3
#     /
#    2
#
# Output:
# 1
#
# Explanation:
# The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
# Note: There are at least two nodes in this BST.
#
# Subscribe to see which companies asked this question.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        diff = 999999
        if root.left:
            t1, t2, t3 = self.gm(root.left)
            diff = min(diff, t1, root.val - t3)
        if root.right:
            t1, t2, t3 = self.gm(root.right)
            diff = min(diff, t1, t2 - root.val)
        return diff

    def gm(self, root):
        diff = 999999
        minium = root.val
        maxium = root.val
        if root.left:
            t1,t2,t3 = self.gm(root.left)
            minium = t2
            diff = min(diff,t1,root.val-t3)
        if root.right:
            t1, t2, t3 = self.gm(root.right)
            maxium = t3
            diff = min(diff, t1, t2-root.val)
        return diff,minium,maxium