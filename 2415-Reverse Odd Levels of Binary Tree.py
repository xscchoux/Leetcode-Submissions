# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def reverseOddLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        queue = collections.deque([root])
        isOdd = False
        
        while queue:
            if isOdd:
                for i in range(len(queue)//2):
                    queue[i].val, queue[~i].val = queue[~i].val, queue[i].val
            for _ in range(len(queue)):
                curr = queue.popleft()
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                    
            isOdd = not isOdd
        
        return root