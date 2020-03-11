# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
# recursive
        def dfs(root, res):
            if not root:
                return
            dfs(root.left, res)
            res.append(root.val)
            dfs(root.right, res)
            
        res1, res2 = [], []
        
        dfs(root1,res1)
        dfs(root2, res2)
        i, j = 0, 0
        ans = []
        while i<=len(res1)-1 and j <= len(res2)-1:
            if res1[i]<=res2[j]:
                ans.append(res1[i])
                i+=1
            else:
                ans.append(res2[j])
                j+=1
                
        return ans+res1[i:]+res2[j:]

# iterative

        stack1, stack2 = [], []
        res = []
        
        while True:
            if root1 or root2:
                while root1:
                    stack1.append(root1)
                    root1 = root1.left
                while root2:
                    stack2.append(root2)
                    root2 = root2.left
                
            elif stack1 and stack2:
                if stack1[-1] > stack2[-1]:
                    root2 = stack2.pop()
                    res.append(root2.val)
                    root2 = root2.right
                else:
                    root1 = stack1.pop()
                    res.append(root1.val)
                    root1 = root1.right
            else:
                break
            return res + stack1 + stack2