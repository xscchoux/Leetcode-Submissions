# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
# iterative
        if not root:
            return []
        
        stack = [root]
        res = []
        
        while stack:
            root = stack.pop()
            res.append(root.val)
            
            if root.right:
                stack.append(root.right)
            
            if root.left:
                stack.append(root.left)
        return res

# second visit

        res = []
        stack = []
        
        while True:
            if root:
                res.append(root.val)
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                root = root.right
            else:
                break
                
        return res