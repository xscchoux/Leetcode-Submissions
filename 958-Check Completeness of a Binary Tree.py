# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        findNull = False
        queue = deque([root])
        
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node is None:
                    findNull = True
                    continue
                else:
                    if findNull:
                        return False
                queue.append(node.left)
                queue.append(node.right)
        return True