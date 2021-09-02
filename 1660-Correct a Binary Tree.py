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