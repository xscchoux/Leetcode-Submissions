# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        
# first try
        arr1 = []
        def dfs(node, arr):
            if not node:
                return
            
            dfs(node.left, arr)
            arr.append(node.val)
            dfs(node.right, arr)
        
        dfs(root1, arr1)
        
        def dfs2(node):
            if not node:
                return False
            
            if dfs2(node.left):
                return True
            idx = bisect_left(arr1, target - node.val)
            if idx < len(arr1) and target - arr1[idx] == node.val:
                return True
            if dfs2(node.right):
                return True
            return False
        
        return dfs2(root2)
            
# very brilliant solution, use in-order and reverse in-order iterator for BST
        stack1, stack2 = [], []
    
        while True:
            while root1:
                stack1.append(root1)
                root1 = root1.left
            while root2:
                stack2.append(root2)
                root2 = root2.right
            if not stack1 or not stack2:
                return False
            
            currVal = stack1[-1].val + stack2[-1].val
            
            if currVal == target:
                return True
            elif currVal < target:
                root1 = stack1.pop().right
            else:
                root2 = stack2.pop().left