# 404. Sum of Left Leaves
#
# Find the sum of all left leaves in a given binary tree.
#
# Example:
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
# There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return self.sl(root.left) + self.sumOfLeftLeaves(root.right)

    def sl(self, root):
        if not root:
            return 0
        if not root.left and not root.right:
            return root.val
        return self.sl(root.left) + self.sumOfLeftLeaves(root.right)