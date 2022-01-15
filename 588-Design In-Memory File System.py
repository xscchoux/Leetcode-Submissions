class TrieNode:
    def __init__(self):
        self.isFile = False
        self.children = dict()
        self.content = ""
class FileSystem(object):

    def __init__(self):
        self.root = TrieNode()

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """  
        node = self.root
        directory = path.split("/")
        for name in directory:
            if not name:
                continue
            if name not in node.children:
                node.children[name] = TrieNode()
            node = node.children[name]
        
        if node.isFile:
            return [name]
        
        res = []
        
        for k, v in node.children.items():
            res.append(k)
        
        return sorted(res)
        
    def mkdir(self, path):
        """
        :type path: str
        :rtype: None
        """
        node = self.root
        directory = path.split("/")
        for name in directory:
            if not name:
                continue
            if name not in node.children:
                node.children[name] = TrieNode()
            node = node.children[name]
        

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: None
        """
        node = self.root
        directory = filePath.split("/")
        for name in directory:
            if not name:
                continue
            if name not in node.children:
                node.children[name] = TrieNode()
            node = node.children[name]
        node.isFile = True
        node.content += content

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        node = self.root
        directory = filePath.split("/")
        for name in directory:
            if not name:
                continue
            if name not in node.children:
                node.children[name] = TrieNode()
            node = node.children[name]
        
        return node.content
        

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)