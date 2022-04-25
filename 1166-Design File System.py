class TrieNode:
    def __init__(self):
        self.children = dict()
        self.val = -1

class FileSystem(object):

    def __init__(self):
        self.root = TrieNode()

    def createPath(self, path, value):
        """
        :type path: str
        :type value: int
        :rtype: bool
        """
        arr = path.split("/")[1:]
        node = self.root
        for i in range(len(arr)):
            if arr[i] not in node.children:
                if i != len(arr)-1:
                    return False
                else:
                    node.children[arr[i]] = TrieNode()
                    node.children[arr[i]].val = value
                    return True
            node = node.children[arr[i]]

    def get(self, path):
        """
        :type path: str
        :rtype: int
        """
        node = self.root
        arr = path.split("/")[1:]
        for x in arr:
            if x in node.children:
                node = node.children[x]
            else:
                return -1
        return node.val
