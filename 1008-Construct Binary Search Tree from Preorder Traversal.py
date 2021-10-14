# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: TreeNode
        """
# naive approach

        def dfs(preorder):
            if not preorder:
                return None
            root = TreeNode(preorder[0])
            r = len(preorder)
            for i in range(len(preorder)):
                if preorder[i] > preorder[0]:
                    r = i
                    break
            root.left = dfs(preorder[1:r])
            root.right = dfs(preorder[r:])
            return root
        
        return dfs(preorder)
        
# brilliant stack approach
        
        root = TreeNode(preorder[0])
        stack = [root]
        for i in range(1, len(preorder)):
            node = stack[-1]
            currNode = TreeNode(preorder[i])
            while stack and preorder[i] > stack[-1].val:
                node = stack.pop()
                
            if node.val > preorder[i]:
                node.left = currNode
            else:
                node.right = currNode
            
            stack.append(currNode)
            
        return root