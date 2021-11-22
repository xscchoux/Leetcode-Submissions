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
# change the value of the "deleted node"
        def traverse(node, key):
            if not node:
                return None
            if node.val < key:
                node.right = traverse(node.right, key)
            elif node.val > key:
                node.left = traverse(node.left, key)
            else:
                if not node.left or not node.right:
                    node = node.left or node.right
                else:
                    _min = node.right
                    while _min.left:
                        _min = _min.left
                    node.val = _min.val
                    node.right = traverse(node.right, _min.val)
            return node
        
        return traverse(root, key)
    
# solution 2
        def traverse(node, key):
            if not node:
                return None
            if node.val < key:
                node.right = traverse(node.right, key)
            elif node.val > key:
                node.left = traverse(node.left, key)
            else:
                if not node.left or not node.right:
                    node = node.left or node.right
                else:
                    _min = node.right
                    while _min.left:
                        _min = _min.left
                    _min.left = node.left
                    node = node.right
            return node
        
        return traverse(root, key)