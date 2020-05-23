class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        
        row = len(board)
        col = len(board[0])
        
        def dfs(r, c):
            board[r][c] = 'D'
            for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<row and 0<=newC<col and board[newR][newC] == 'O':
                    dfs(newR, newC)
        
        for r in range(row):
            for c in range(col):
                if ( r in (0, row-1) or c in (0, col-1)) and board[r][c] == 'O':
                    dfs(r,c)
                    
        for r in range(row):
            for c in range(col):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                if board[r][c] == 'D':
                    board[r][c] = 'O'