# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        if not s:
            return None
        
        s = deque(list(s))
        
        def dfs():
            if s and (s[0].isdigit() or s[0] == '-'):
                num = s.popleft()
                while s and s[0].isdigit():
                    num += s.popleft()
                node = TreeNode(int(num))
            if s and s[0] == '(':
                s.popleft()
                node.left = dfs()
            if s and s[0] == '(':
                s.popleft()
                node.right = dfs()
            if s and s[0] == ')':
                s.popleft()
            return node
        
        return dfs()