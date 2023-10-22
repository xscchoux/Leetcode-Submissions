# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def correctBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """      
        queue = collections.deque([root])
        visited = set([root.val])
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                if curr.right:
                    grandRightNode = curr.right.right
                    if grandRightNode and grandRightNode.val in visited:
                        curr.right = None
                        return root
                    visited.add(curr.right.val)
                    queue.append(curr.right)
                if curr.left:
                    grandLeftNode = curr.left.right
                    if grandLeftNode and grandLeftNode.val in visited:
                        curr.left = None
                        return root
                    visited.add(curr.left.val)
                    queue.append(curr.left)

# DFS solution

# Note that setting node = None in a function doesn't work
# In Python, when you pass an object to a function, you are passing a reference to the object. 
# However, when you assign a new value to the variable (like node = None), 
# you are only changing the local variable within the function scope, not the actual object outside the function.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        
        visited = set()
        
        def dfs(node):
            if not node:
                return
            
            visited.add(node)
            leftNode = rightNode = None
            
            if node.right:
                if node.right not in visited:
                    rightNode = dfs(node.right)
                else:
                    return None
            if node.left:
                if node.left not in visited:
                    leftNode = dfs(node.left)

            node.left = leftNode
            node.right = rightNode
            return node
        
        newRoot = dfs(root)
        return newRoot