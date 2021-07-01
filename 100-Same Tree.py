# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # BFS
        
        queue = deque([(p, q)])
        while queue:
            for _ in range(len(queue)):
                currP, currQ = queue.popleft()
                if currP and currQ:
                    if currP.val == currQ.val:
                        queue.append((currP.left, currQ.left))
                        queue.append((currP.right, currQ.right))
                    else:
                        return False
                elif currP or currQ:
                    return False
        return True
    
        # DFS
        
        def dfs(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return dfs(p.left, q.left) and dfs(p.right, q.right)
        
        return dfs(p, q)