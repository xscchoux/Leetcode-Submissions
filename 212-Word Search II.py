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

# better solution (delete used paths in the trie)
class TrieNode:
    def __init__(self):
        self.children = dict()
        self.count = 0
        self.parent = None
        self.isWord = ""

class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        row, col = len(board), len(board[0])
        root = TrieNode()
        self.res = set()
        
        for word in words:
            node = root
            for w in word:
                if w not in node.children:
                    node.children[w] = TrieNode()
                node.children[w].parent = node
                node = node.children[w]
                node.count += 1
            node.isWord = word

        def dfs(r, c, currNode):
            if not currNode.count:
                return
            
            if currNode.isWord:
                self.res.add(currNode.isWord)
                currNode.isWord = ""
                tmpNode = currNode
                while tmpNode:
                    tmpNode.count -= 1
                    tmpNode = tmpNode.parent
                
            tmp = board[r][c]
            board[r][c] = "#"
            for dr, dc in ((1,0), (0,1), (-1,0), (0,-1)):
                nr = r+dr
                nc = c+dc
                if 0<=nr<row and 0<=nc<col and board[nr][nc] in currNode.children:
                    dfs(nr, nc, currNode.children[board[nr][nc]])
            board[r][c] = tmp
                    
        for r in range(row):
            for c in range(col):
                if board[r][c] in root.children:
                    root.count += 1
                    dfs(r, c, root.children[board[r][c]])
        
        return list(self.res)