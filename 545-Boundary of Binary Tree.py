# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def boundaryOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
# print left boundry, right boundry 
        res = []
        if not root:
            return []
        if root.left or root.right:  # in case there's only one node
            res.append(root.val)
        
        def leftBoundry(root):
            if root:
                if root.left:
                    res.append(root.val)
                    leftBoundry(root.left)
                elif root.right:
                    res.append(root.val)
                    leftBoundry(root.right)
   
        def rightBoundry(root):
            if root:
                if root.right:
                    rightBoundry(root.right)
                    res.append(root.val)
                elif root.left:
                    rightBoundry(root.left)
                    res.append(root.val)
        
        def leaves(root):
            if not root:
                return
            if not root.left and not root.right:
                res.append(root.val)
                return
            leaves(root.left)
            leaves(root.right)
            
        leftBoundry(root.left)
        leaves(root)
        rightBoundry(root.right)
        return res



# recursive, preorder and postorder

        if not root:
            return []
        res = [root.val]
        
        
        def leftBoundry(root, leftbd):
            if not root:
                return
            if not root.left and not root.right:
                res.append(root.val)
                return
            
            if leftbd:
                res.append(root.val)
            leftBoundry(root.left, root.left and leftbd)
            leftBoundry(root.right, not root.left and leftbd)
        
        def rightBoundry(root, rightbd):
            if not root:
                return
            if not root.left and not root.right:
                res.append(root.val)
                return
            
            rightBoundry(root.left, not root.right and rightbd)
            rightBoundry(root.right, root.right and rightbd)
            if rightbd:
                res.append(root.val)
        
        leftBoundry(root.left, True)
        rightBoundry(root.right, True)
        
        return res