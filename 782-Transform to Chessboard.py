class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board)
        
        # to check if there are only "two" kinds of rows and "two" kinds of columns in this board
        for r in range(n):
            for c in range(n):
                if board[0][0]^board[r][0]^board[0][c]^board[r][c] != 0:
                    return -1
        
        rowOnes = colOnes = 0
        rowSwap = colSwap = 0
        
        for i in range(n):
            rowOnes += board[0][i]
            colOnes += board[i][0]
            rowSwap += board[0][i] == i%2
            colSwap += board[i][0] == i%2
            
        if rowOnes < n//2 or rowOnes > (n+1)//2:
            return -1
        
        if colOnes < n//2 or colOnes > (n+1)//2:
            return -1
        
        if n%2:
            if rowSwap%2: rowSwap = n - rowSwap
            if colSwap%2: colSwap = n - colSwap
        else:
            rowSwap = min(rowSwap, n-rowSwap)
            colSwap = min(colSwap, n-colSwap)
            
        return (rowSwap+colSwap)//2