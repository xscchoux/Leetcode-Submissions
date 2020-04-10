class TicTacToe(object):

    def __init__(self, n):
        """
        Initialize your data structure here.
        :type n: int
        """
        self.row = [0]*n
        self.col = [0]*n
        self.diag1 = 0
        self.diag2 = 0
        self.n = n

    def move(self, row, col, player):
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        n = self.n
        if player == 1:
            add = 1
        else:
            add = -1
            
        self.row[row] += add
        self.col[col] += add
        if row == col:
            self.diag1 += add
        if row+col == n-1:
            self.diag2 += add

        if self.row[row] == n or self.row[row] == -n or self.col[col] == n or self.col[col] == -n or \
            self.diag1 == n  or self.diag1 == -n  or self.diag2 == n or self.diag2 == -n:
            return player
        else:
            return 0
        
        
# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)