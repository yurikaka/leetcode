# 110. Balanced Binary Tree

# Given a binary tree, determine if it is height-balanced.

# For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
        	return True
        l = self.bal(root.left)
        r = self.bal(root.right)
        if l == -1 or r == -1:
    		return False
    	if abs(l-r) > 1:
    		return False
    	return True

    def bal(self,root):
    	if not root:
    		return 0
    	l = self.bal(root.left)
    	r = self.bal(root.right)
    	if l == -1 or r == -1:
    		return -1
    	if abs(l-r) > 1:
    		return -1
    	return max(l,r) + 1