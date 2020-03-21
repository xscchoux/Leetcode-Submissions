class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
       
        def dfs(word,r,c, visited):
            if not word:
                return True
            res = False
            for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                newr = r+dr
                newc = c+dc
                if 0<=newr<row and 0<=newc<col and word[0] == board[newr][newc] and (newr, newc) not in visited:
                    visited.add((newr,newc))
                    res = res or dfs(word[1:], newr, newc, visited)
                    visited.remove((newr,newc))
            return res   

        row = len(board)
        col = len(board[0])
        visited = set()
        for r in range(row):
            for c in range(col):
                if board[r][c] == word[0]:
                    visited.add((r,c))
                    if dfs(word[1:],r,c, visited):
                        return True
                    visited.remove((r,c))
        return False