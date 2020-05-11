# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# from collections import deque
# class Codec:

#     def serialize(self, root):
#         """Encodes a tree to a single string.
        
#         :type root: TreeNode
#         :rtype: str
#         """
#         if not root:
#             return '# '
        
#         def dfs(root):
#             if not root:
#                 return '# '
#             string = ''
#             string += str(root.val) + ' '
#             string += dfs(root.left)
#             string += dfs(root.right)
#             return string
        
#         res = dfs(root)
#         return res
        

#     def deserialize(self, data):
#         """Decodes your encoded data to tree.
        
#         :type data: str
#         :rtype: TreeNode
#         """
#         tokens = deque(data.split(" ")[:-1])
        
#         def dfs(tokens):
#             if tokens[0] == '#':
#                 tokens.popleft()
#                 return None
#             root = TreeNode(int(tokens[0]))
#             tokens.popleft()
#             root.left = dfs(tokens)
#             root.right = dfs(tokens)
#             return root
        
#         return dfs(tokens)




# use properties in BST
from collections import deque
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        val = []
        def dfs(root):
            if not root:
                return
            value = root.val
            val.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return " ".join(map(str, val))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        nodes = deque(data.split(" "))
        def dfs(_min, _max):
            if nodes and _min < int(nodes[0]) < _max:
                value = int(nodes.popleft())
                root = TreeNode(value)
                root.left = dfs(_min, int(root.val) )
                root.right = dfs(int(root.val), _max)
                return root
        
        return dfs(float('-inf'), float('inf'))

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))