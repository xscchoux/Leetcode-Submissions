# Time complexity: O(mnt)
# Space complexity: O(t)

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isword = None
        

class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        root = TrieNode()
        def addWord(word, root):
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.isword = word
        
        for word in words:
            addWord(word, root)
        
        row = len(board)
        col = len(board[0])
        self.res = []
        
        def dfs(node, r, c):
            curr = board[r][c]
            if curr in node.children:
                node = node.children[curr]
            else:
                return
            
            if node.isword:
                self.res.append(node.isword)
                node.isword = None
                
            for dr, dc in ((1,0), (-1,0), (0,1), (0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<row and 0<=newC<col:
                    tmp = board[r][c]
                    board[r][c] = '#'
                    dfs(node, newR, newC)
                    board[r][c] = tmp
                    
        for r in range(row):
            for c in range(col):
                dfs(root, r, c)
                
        return self.res