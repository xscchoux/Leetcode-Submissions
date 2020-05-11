# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
# first visit (recursive)
        arr = []
        def dfs(root):
            if not root:
                return
            dfs(root.left)
            arr.append(root)
            dfs(root.right)
        dfs(root)
        for ind, value in enumerate(arr):
            if value == p:
                if ind == len(arr) - 1:
                    return None
                else:
                    return arr[ind+1]
    
# second visit (stack)
# # case1: if there's a right subtree... the successor must be on the right

        if p.right:
            p = p.right
            while p.left:
                p = p.left
            return p
        
# # case2: if there's no right subtree... the sucessor is somewhere upper in the tree
# # inorder traversal
        stack = []
        prev = None
        
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                if prev == p:
                    return root
                prev = root
                root = root.right
            else:
                break
        
        return None