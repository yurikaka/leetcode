# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False
        sum -= root.val
        if not root.left and not root.right:
            return sum == 0
        if root.left:
            result = self.hasPathSum(root.left, sum)
            if result:
                return True
        if root.right:
            result = self.hasPathSum(root.right, sum)
        return result
