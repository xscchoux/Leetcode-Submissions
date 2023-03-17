class TreeNode:
    def __init__(self):
        self.children = defaultdict(TreeNode)
        self.word = ""

class Solution:
    def longestWord(self, words: List[str]) -> str:
        root = TreeNode()
        
        for word in words:
            node = root
            for c in word:
                node = node.children[c]
            node.word = word
                
        arr = []
        
        def dfs(node):
            if not node.children and node.word:
                arr.append(node.word)
            
            for nxt in node.children:
                if node.children[nxt].word:
                    dfs(node.children[nxt])
                elif node.word:
                    arr.append(node.word)
                
        dfs(root)
        if not arr:
            return ""
        return sorted(arr, key = lambda x:(-len(x), x))[0]