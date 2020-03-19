class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = ['.'*n for _ in range(n)]
        rows = [False]*n
        cols = [False]*n
        diag1 = [False]*(2*n-1)
        diag2 = [False]*(2*n-1)
        res = []
        
        def isOccupied(r,c):
            if rows[r] or cols[c] or diag1[r+c] or diag2[r-c+n-1]:
                return True
            return False
        
        def updateBoard(r,c, put = True):
            if put:
                board[r] = board[r][:c] + 'Q' + board[r][c+1:]
            else:
                board[r] = board[r][:c] + '.' + board[r][c+1:]
            rows[r] = put
            cols[c] = put
            diag1[r+c] = put
            diag2[r-c+n-1] = put
            
        
        def dfs(r):
            if r == n:
                res.append(board[:])
                return
            
            for c in range(n):
                if isOccupied(r,c):
                    continue
                updateBoard(r,c)
                dfs(r+1)
                updateBoard(r,c, False)
                
        dfs(0)
        return res