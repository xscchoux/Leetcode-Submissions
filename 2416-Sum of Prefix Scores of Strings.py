class TrieNode:
    def __init__(self):
        self.children = dict()
        self.count = 0
        
class Solution(object):
    def sumPrefixScores(self, words):
        """
        :type words: List[str]
        :rtype: List[int]
        """
        root = TrieNode()
        for word in words:
            node = root
            for w in word:
                if w not in node.children:
                    node.children[w] = TrieNode()
                node = node.children[w]
                node.count += 1

        res = []
        
        for word in words:
            node = root
            count = 0
            for w in word:
                node = node.children[w]
                count += node.count
            res.append(count)
            
        return res