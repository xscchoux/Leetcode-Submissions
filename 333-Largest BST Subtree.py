# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# https://www.youtube.com/watch?v=4fiDs7CCxkc
class Solution(object):
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        def dfs(root):
            if not root:
                return True, 0, float('inf'), float('-inf')
            
            leftBoolean, leftNum, leftMin, leftMax = dfs(root.left)
            rightBoolean, rightNum, rightMin, rightMax = dfs(root.right)
            
            if leftBoolean and rightBoolean and leftMax < root.val < rightMin:
                return True, 1 + leftNum + rightNum, min(root.val, leftMin), max(root.val, rightMax)
            else:
                return False, max(leftNum, rightNum), 0, 0
            
        res = dfs(root)
        return res[1]