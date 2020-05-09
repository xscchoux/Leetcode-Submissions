# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue = deque( [(root, 0)] )
        res = 1
        
        while queue:
            size = len(queue)
            res = max(res, queue[-1][1] - queue[0][1] + 1)
            for _ in range(size):
                node, level = queue.popleft()
                if node.left:
                    queue.append((node.left, 2*level))
                if node.right:
                    queue.append((node.right, 2*level+1))
        return res