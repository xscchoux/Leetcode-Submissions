class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        box = [set() for _ in range(9)]
        
        for r in range(9):
            for c in range(9):
                if board[r][c] != ".":
                    row[r].add(int(board[r][c]))
                    col[c].add(int(board[r][c]))
                    box[(r//3)*3 + (c//3)].add(int(board[r][c]))
        
        self.solved = False
        
        def backtrack(r, c):
            if r == 9:
                self.solved = True
                return
            if board[r][c] == '.':
                for num in range(1, 10):
                    if num not in row[r] and num not in col[c] and num not in box[(r//3)*3 + (c//3)]:
                        curr = str(num)
                        row[r].add(num)
                        col[c].add(num)
                        box[(r//3)*3 + (c//3)].add(num)
                        board[r][c] = curr
                        
                        if c+1 == 9:   
                            backtrack(r+1, 0)
                        else:
                            backtrack(r,c+1)
                        
                        if self.solved:
                            break
                        board[r][c] = "."
                        box[(r//3)*3 + (c//3)].remove(num)
                        col[c].remove(num)  
                        row[r].remove(num)
            else:
                if c+1 == 9:   
                    backtrack(r+1, 0)
                else:
                    backtrack(r,c+1)
                    
        backtrack(0,0)