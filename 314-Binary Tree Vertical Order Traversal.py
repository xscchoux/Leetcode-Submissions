#O(N)

from collections import deque, defaultdict
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        hmap = dict()
        queue = deque([(root, 0)])
        maxCol, minCol = 0, 0
        
        while queue:
            node, col = queue.popleft()
            hmap[col] = hmap.get(col, []) + [node.val]
            if node.left:
                queue.append((node.left, col-1))
                minCol = min(minCol, col-1)
            if node.right:
                queue.append((node.right, col+1))
                maxCol = max(maxCol, col+1)
        
        return [hmap[key] for key in range(minCol, maxCol+1) if key in hmap]