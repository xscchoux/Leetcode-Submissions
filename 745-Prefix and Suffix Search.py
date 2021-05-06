# use Trie
# Time: O(n*L^2), Space: O(n*L^2)

class Node:
    def __init__(self):
        self.children = {}
        self.maxIndex = 0

class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.root = Node()
        for ind, word in enumerate(words):
            nWord = word + '#' + word
            for i in range(len(word)):
                curr = self.root
                for j in range(i, len(nWord)):
                    c = nWord[j]
                    if c not in curr.children:
                        curr.children[c] = Node()
                    curr = curr.children[c]
                    curr.maxIndex = ind

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        curr = self.root
        letter = suffix + '#' + prefix
        for char in letter:
            if char not in curr.children:
                return -1
            curr = curr.children[char]
            
        return curr.maxIndex


# simple hashmap solution
# Time: O(n*L^3), Space: O(n*L^2)
class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.hmap = dict()
        for ind, word in enumerate(words):
            length = len(word)
            for p in range(1, length+1):
                for s in range(1, length+1):
                    self.hmap[(word[:p], word[-s:])] = ind

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        if (prefix, suffix) in self.hmap:
            return self.hmap[(prefix, suffix)]
        else:
            return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)