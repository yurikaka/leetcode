# 102. Binary Tree Level Order Traversal

# Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

# For example:
# Given binary tree [3,9,20,null,null,15,7],
#     3
#    / \
#   9  20
#     /  \
#    15   7
# return its level order traversal as:
# [
#   [3],
#   [9,20],
#   [15,7]
# ]

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
        	return []
        result = [[root.val]]
        self.out(root.left,1,result)
        self.out(root.right,1,result)
        return result

    def out(self,root,level,result):
    	if not root:
    		return
    	if len(result) < level + 1:
    		result.append([root.val])
    	else:
    		result[level].append(root.val)
    	self.out(root.left,level+1,result)
        self.out(root.right,level+1,result)
        return

