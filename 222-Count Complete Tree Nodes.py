# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
# binary search
        if not root:
            return 0
        
        def hasK(num):
            path = []
            while num > 0:
                path.append(num)
                num //= 2
            
            node = root
            for i in range(len(path)-2, -1, -1):
                if path[i] == path[i+1]*2:
                    node = node.left
                else:
                    node = node.right
                if not node:
                    return False
            return True
        
        left, right = 1, 50000
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if hasK(mid):
                left = mid
            else:
                right = mid
        
        if hasK(left):
            return left
        return right
              
# check the height of left and right subtree
        
        def checkLeftDepth(node):
            if not node:
                return 0
            return 1 + checkLeftDepth(node.left)
        
        def checkRightDepth(node):
            if not node:
                return 0
            return 1 + checkRightDepth(node.right)
    
        def dfs(node):
            if not node:
                return 0
        
            h1 = checkLeftDepth(node.left)
            h2 = checkRightDepth(node.left)
            h3 = checkLeftDepth(node.right)
            h4 = checkRightDepth(node.right)

            res = 1

            if h1 == h2:
                if h3 == h4:
                    res += 2**h1 + 2**h3 - 2
                else:
                    res += 2**h1 - 1 + dfs(node.right)
            else:
                res += 2**h3 - 1 + dfs(node.left)
            return res
        return dfs(root)
    
# check the height of left subtree

        def checkLeftDepth(node):
            if not node:
                return 0
            return 1 + checkLeftDepth(node.left)
    
        def dfs(node):
            if not node:
                return 0
        
            h1 = checkLeftDepth(node.left)
            h2 = checkLeftDepth(node.right)

            res = 1

            if h1 == h2:
                res += 2**h1 - 1 + dfs(node.right)
            else:
                res += 2**h2 - 1 + dfs(node.left)
            return res

        return dfs(root)