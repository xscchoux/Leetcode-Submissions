# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        queue = collections.deque([(root,1)])
        
        while queue:
            for _ in range(len(queue)):
                curr, level = queue.popleft()
                if not curr.left and not curr.right:
                    return level
                if curr.left:
                    queue.append((curr.left, level+1))
                if curr.right:
                    queue.append((curr.right, level+1))