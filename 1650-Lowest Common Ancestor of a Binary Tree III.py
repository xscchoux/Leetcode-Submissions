"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution(object):
    def lowestCommonAncestor(self, p, q):
        """
        :type node: Node
        :rtype: Node
        """
        
# Method 1,  Time:O( Max(Height of p, Height of q) ), Space:O(Height of p)
        pParent = set()
        pParent.add(p)
        
        while p.parent:
            p = p.parent
            pParent.add(p)
        
        while q:
            if q in pParent:
                return q
            else:
                q = q.parent
                
# Method 2,  Time:O( Max(Height of p, Height of q) ), Space:O(1)
        while p.parent:
            p.parent, p = None, p.parent
            
        while q:
            if not q.parent:
                return q
            else:
                q = q.parent