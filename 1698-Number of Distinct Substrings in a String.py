# First try
class TrieNode:
    def __init__(self):
        self.children = dict()

class Solution:
    def countDistinct(self, s: str) -> int:
        root = TrieNode()
        res = 0
        for i in range(len(s)):
            node = root
            for j in range(i, len(s)):
                if s[j] not in node.children:
                    node.children[s[j]] = TrieNode()
                    res += 1
                node = node.children[s[j]]
        
        return res


# Better
class Solution:
    def countDistinct(self, s: str) -> int:
        trie = dict()
        res = 0
        
        for i in range(len(s)):
            node = trie
            for j in range(i, len(s)):
                if s[j] not in node:
                    node[s[j]] = dict()
                    res += 1
                node = node[s[j]]
        
        return res