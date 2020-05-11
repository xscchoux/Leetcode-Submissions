"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
from collections import deque
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        if not root:
            return '# '
        
        def dfs(root):
            string = ''
            string += str(root.val) + ' '
            for child in root.children:
                string += dfs(child)
            string += '# '
            return string
        
        return dfs(root)
        
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        nodes = deque(data.split(" ")[:-1])
        if nodes[0] == '#':
            return None
        root = Node(nodes[0], [])
        nodes.popleft()
        
        def dfs(root):
            while nodes[0] != '#':
                newNode = Node(nodes[0],[])
                nodes.popleft()
                root.children.append(newNode)
                dfs(newNode)
            nodes.popleft()
        dfs(root)
        return root
            
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))