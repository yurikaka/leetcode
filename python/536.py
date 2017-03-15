# 536. Construct Binary Tree from String My SubmissionsBack To Contest
#
# You need to construct a binary tree from a string consisting of parenthesis and integers.
#
# The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
#
# You always start to construct the left child node of the parent first if it exists.
#
# Example:
# Input: "4(2(3)(1))(6(5))"
# Output: return the tree root node representing the following tree:
#
#        4
#      /   \
#     2     6
#    / \   /
#   3   1 5
# Note:
# There will only be '(', ')', '-' and '0' ~ '9' in the input string.
# An empty tree is represented by "" instead of "()".

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        end = False
        ls = len(s)
        for i in ls:
            if s[i] == '(':
                end = i
                break
        if not end:
            root = TreeNode(int(s[:]))
            return root
        else:
            root = TreeNode(int(s[:end]))
            start,root.left = self.ss(s,end)
            if start >= ls:
                return root
            else:
                start,root.right = self.ss(s,start)
                return root

    def ss(self, s, pos):
        pos += 1
        end = pos
        while s[end] != ')' and s[end] != '(':
            end += 1
        root = TreeNode(int(s[pos:end]))
        if s[end] == ')':
            return end+1,root
        else:
            start,root.left = self.ss(s,end)
            if s[start] == ')':
                return start+1,root
            else:
                start,root.right = self.ss(s,start)
                return start+1,root

