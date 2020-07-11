# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:     # the key is not in BST
            return None
        
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        else:
            if not (root.right and root.left):
                root = root.left or root.right
            else:
                nextLargest = root.right
                while nextLargest.left:
                    nextLargest = nextLargest.left
                root.val = nextLargest.val
                root.right = self.deleteNode(root.right, root.val)
        
        return root