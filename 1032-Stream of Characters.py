# O(N*M), N:number of queries, M:length of the longest word (depth of the trie)
class TrieNode: 
    def __init__(self):
        self.children = dict()
        self.isWord = False

class StreamChecker(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.root = TrieNode()
        self.queue = collections.deque([])
        
        self.currNode = self.root
        for word in words:
            node = self.root
            for i in range(len(word)-1, -1, -1):
                if word[i] not in node.children:
                    node.children[word[i]] = TrieNode()
                node = node.children[word[i]]
            node.isWord = True

    def query(self, letter):
        """
        :type letter: str
        :rtype: bool
        """
        node = self.root
        self.queue.appendleft(letter)
        
        for c in self.queue:
            if c in node.children:
                node = node.children[c]
            else:
                return False
            
            if node.isWord:
                return True
        
        return False


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)