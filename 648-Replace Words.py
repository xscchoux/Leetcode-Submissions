class TrieNode:
    def __init__(self):
        self.children = dict()
        self.isWord = False

class Solution(object):
    def replaceWords(self, dictionary, sentence):
        """
        :type dictionary: List[str]
        :type sentence: str
        :rtype: str
        """
        root = TrieNode()
        
        for word in dictionary:
            node = root
            for c in word:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
            node.isWord = True
            
        def search(word, node):
            tmp = ""
            for char in word:
                if char in node.children and node.children[char].isWord:
                    tmp += char
                    return tmp
                elif char in node.children:
                    tmp += char
                    node = node.children[char]
                else:
                    return None
            return None
        
        res = sentence.split(" ")
        
        for i in range(len(res)):
            replace = search(res[i], root)
            if replace:
                res[i] = replace
        return " ".join(res)