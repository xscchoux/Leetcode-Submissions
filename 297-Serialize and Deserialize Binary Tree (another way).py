# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return '#'
        
        data = []
        
        def dfs(root):
            if not root:
                data.append('#')
                return
            data.append(str(root.val))
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return " ".join(data)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data[0] == '#':
            return None
        
        data  = deque(data.split(" "))
        def dfs():
            root = TreeNode(data.popleft())
            if data[0] != '#':
                root.left = dfs()
            else:
                data.popleft()
            if data[0]!='#':
                root.right = dfs()
            else:
                data.popleft()
            return root
            
        return dfs()
        
        
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))