class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
# https://www.cnblogs.com/grandyang/p/11300071.html
        row = len(board)
        col = len(board[0])
        while True:
            deleted = set()
            for r in range(row):
                for c in range(col):
                    if board[r][c] == 0:
                        continue
                    if r > 1 and board[r][c] == board[r-1][c] == board[r-2][c]:
                        deleted.add((r,c))
                        deleted.add((r-1,c))
                        deleted.add((r-2,c))
                    if c > 1 and board[r][c] == board[r][c-1] == board[r][c-2]:
                        deleted.add((r,c))
                        deleted.add((r,c-1))
                        deleted.add((r,c-2))
                        
            if not deleted:
                break
            for r, c in deleted:
                board[r][c] = 0
    # swap
            for c in range(col):
                tmp = row-1
                for r in range(row-1, -1,-1):
                    if board[r][c]:
                        board[r][c], board[tmp][c] = board[tmp][c], board[r][c]
                        tmp-=1
            
        return board