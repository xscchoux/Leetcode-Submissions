# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        curr_level = max_level = 1
        max_sum = float('-inf')
        
        queue = collections.deque([root])
        
        while queue:
            curr_sum = 0
            for _ in range(len(queue)):
                curr = queue.popleft()
                curr_sum += curr.val
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            if curr_sum > max_sum:
                max_level = curr_level
                max_sum = curr_sum
            curr_level += 1
        
        return max_level