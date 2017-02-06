# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root:
            return []
        sum -= root.val
        if not root.left and not root.right:
            if sum == 0:
                return [[root.val]]
            return []
        result = []
        if root.left:
            _result = self.pathSum(root.left, sum)
            for i in _result:
                result.append([root.val]+i)
        if root.right:
            _result = self.pathSum(root.right, sum)
            for i in _result:
                result.append([root.val]+i)
        return result