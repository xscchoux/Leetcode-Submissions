from collections import defaultdict
class TrieNode():
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.count = 0
        self.prefix = 0

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        curr = self.root
        for w in word:
            curr = curr.children[w]
            curr.prefix += 1
        curr.count += 1

    def countWordsEqualTo(self, word):
        """
        :type word: str
        :rtype: int
        """
        curr = self.root
        for w in word:
            curr = curr.children[w]
        return curr.count

    def countWordsStartingWith(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        curr = self.root
        for w in prefix:
            if w not in curr.children:
                return 0
            curr = curr.children[w]
        return curr.prefix

    def erase(self, word):
        """
        :type word: str
        :rtype: None
        """
        curr = self.root
        for w in word:
            curr.children[w].prefix -= 1           
            if curr.children[w].prefix == 0:
                del curr.children[w]
                return
            curr = curr.children[w]
        curr.count -= 1

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)