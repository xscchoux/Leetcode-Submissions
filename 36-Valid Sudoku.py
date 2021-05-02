class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = []
        cols = []
        boxes = []
        
        for _ in range(9):
            rows.append(set())
            cols.append(set())
            boxes.append(set())
            
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                    
                num = board[r][c]
                
                if num not in rows[r] and num not in cols[c] and num not in boxes[(r//3)*3 + (c//3)]:
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[(r//3)*3 + (c//3)].add(num)
                else:
                    return False
        return True