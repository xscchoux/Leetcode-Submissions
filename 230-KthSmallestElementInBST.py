# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# iterative O(n)
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        while True:  
            while root:
                stack.append(root)
                root = root.left
            if stack:
                root = stack.pop()
                k-=1
                if k==0:
                    return root.val
                root = root.right
            else:
                break
                
# recursive O(n)
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        self.k = k
        self.res = 0
        
        def dfs(root):
            if not root:
                return
            dfs(root.left)
            self.k -= 1
            if self.k == 0:
                self.res = root.val
                return
            dfs(root.right)
        
        dfs(root)
        return self.res