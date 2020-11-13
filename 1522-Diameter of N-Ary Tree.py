"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution(object):
    def diameter(self, root):
        """
        :type root: 'Node'
        :rtype: int
        """
        self.res = 0
        
        def dfs(root):
            if not root.children:
                return 0
            
            firstmax, secondmax = 0, 0
            for nxt in root.children:
                val = dfs(nxt)
                if val + 1 > firstmax:
                    secondmax = firstmax
                    firstmax = val + 1
                elif val + 1 > secondmax:
                    secondmax = val + 1
            self.res = max(self.res, firstmax + secondmax)
            return firstmax
        dfs(root)
        return self.res