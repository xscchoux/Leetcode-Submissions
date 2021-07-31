class TreeNode(object):
    def __init__(self):
        self.children = dict()
        self.val = 0

class MapSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TreeNode()
        self.hmap = dict()

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: None
        """
        diff = 0
        if key in self.hmap:
            diff = val - self.hmap[key]
        else:
            diff = val
        self.hmap[key] = val
        
        node = self.root
        for word in key:
            if word not in node.children:
                node.children[word] = TreeNode()
            node = node.children[word]
            node.val += diff

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        node = self.root
        for word in prefix:
            if word not in node.children:
                return 0
            node = node.children[word]

        return node.val


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)