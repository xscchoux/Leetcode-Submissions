class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
# My DFS Solution:
        if not board or not board[0]:
            return 0
        
        row = len(board)
        col = len(board[0])
        res = 0
        
        directions = [(1,0), (0,1), (-1,0), (0,-1)]
        
        def dfs(r, c, direction = None):
            board[r][c] = '.'
            if not direction:
                for i in range(len(directions)):
                    newR = r + directions[i][0]
                    newC = c + directions[i][1]
                    if 0 <= newR < row and 0 <= newC < col and board[newR][newC] == 'X':
                        dfs(newR, newC, directions[i])
            else:
                newR = r + direction[0]
                newC = c + direction[1]
                if 0 <= newR < row and 0 <= newC < col and board[newR][newC] == 'X':
                    dfs(newR, newC, direction)
            return True
        
        for r in range(row):
            for c in range(col):
                if board[r][c] == 'X':
                    dfs(r, c)
                    res += 1
        
        return res

# Simplest solution

        row = len(board)
        col = len(board[0])
        res = 0
        
        for r in range(row):
            for c in range(col):
                if board[r][c] == 'X': 
                    # is endpoint?
                    if (r == row-1 or (r < row-1 and board[r+1][c] == '.')) and \
                        (c == col-1 or (c < col-1 and board[r][c+1] == '.') ):
                        res += 1
                        
        return res