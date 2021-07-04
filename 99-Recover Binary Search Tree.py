# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        stack = []
        first = second = None
        prev = None
        
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                if prev and root.val < prev.val:
                    if not first:
                        first, second = prev, root
                    else:
                        second = root
                prev = root
                root = root.right
            else:
                break
        first.val, second.val = second.val, first.val