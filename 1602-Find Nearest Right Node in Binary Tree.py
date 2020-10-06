# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def findNearestRightNode(self, root, u):
        """
        :type root: TreeNode
        :type u: TreeNode
        :rtype: TreeNode
        """
        queue = deque([root])
        while queue:
            isFound = False
            for _ in range(len(queue)):
                node = queue.popleft()
                if isFound:
                    return node
                if node == u:
                    isFound = True
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if isFound:
                return None
        return None