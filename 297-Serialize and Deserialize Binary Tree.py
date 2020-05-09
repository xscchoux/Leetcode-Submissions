# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
# time complexity: O(n)
# space complexity: O(n)
        def dfs(root):
            if not root:
                return "#,"
            string = ''
            string += str(root.val) + ','
            string += dfs(root.left)
            string += dfs(root.right)
            return string
        res = dfs(root)
        return res
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
# time complexity: O(n)
# space complexity: O(n)
        def dfs(nodeLinst):
            if nodeList[0] == '#':
                nodeList.pop(0)
                return None
            root = TreeNode(nodeList[0])
            nodeList.pop(0)
            root.left = dfs(nodeList)
            root.right = dfs(nodeList)
            return root
        
        nodeList = data.split(',')[:-1]
        return dfs(nodeList)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))