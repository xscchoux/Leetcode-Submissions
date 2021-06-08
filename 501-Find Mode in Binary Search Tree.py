# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        count = 0
        maxCount = 0
        preVal = float('-inf')
        res = set()
        
        while True:
            if root:
                stack.append(root)
                root = root.left
            elif stack:
                root = stack.pop()
                
                if root.val != preVal:
                    count = 1
                else:
                    count += 1
                    
                if count == maxCount:
                    res.add(root.val)
                elif count > maxCount:
                    maxCount = count
                    res = set()
                    res.add(root.val)
                    
                preVal = root.val  
                root = root.right
            else:
                break
        
        return res
        