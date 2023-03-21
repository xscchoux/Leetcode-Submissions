class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.isWord = False
        
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for w in word:
            node = node.children[w]
        node.isWord = True

    def search(self, word: str) -> bool:
        
        def dfs(node, ind):
            if ind == len(word):
                if node.isWord:
                    return True
                return False
            
            if word[ind] == ".":
                for nxt in node.children:
                    if dfs(node.children[nxt], ind+1):
                        return True
            elif word[ind] in node.children:
                if dfs(node.children[word[ind]], ind+1):
                    return True
            return False
        
        return dfs(self.root, 0)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)