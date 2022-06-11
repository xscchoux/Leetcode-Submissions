class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
# first try
        r, c = click
        if board[r][c] == "M":
            board[r][c] = "X"
            return board
        
        row, col = len(board), len(board[0])
        visited = set([(r, c)])
        queue = collections.deque([(r, c)])
        directions = [(0, 1), (-1, 1), (-1, 0), (1, 1), (1, 0), (-1, -1), (0, -1), (1, -1)]
        
        while queue:
            for _ in range(len(queue)):
                currR, currC = queue.popleft()
                mines = 0
                board[currR][currC] = "B"
                for dr, dc in directions:
                    nr = currR + dr
                    nc = currC + dc
                    if 0<=nr<row and 0<=nc<col and board[nr][nc] == "M":
                        mines += 1
                        
                if mines == 0:
                    for dr, dc in directions:
                        nr = currR + dr
                        nc = currC + dc
                        if 0<=nr<row and 0<=nc<col and (nr, nc) not in visited:
                            visited.add((nr, nc))
                            queue.append((nr, nc))
                else:
                    board[currR][currC] = str(mines) 
        return board
    
# another way
        r, c = click
        if board[r][c] == "M":
            board[r][c] = "X"
            return board
        
        row, col = len(board), len(board[0])
        queue = collections.deque([(r, c)])
        directions = [(0, 1), (-1, 1), (-1, 0), (1, 1), (1, 0), (-1, -1), (0, -1), (1, -1)]
        
        while queue:
            currR, currC = queue.popleft()
            mines = 0
            board[currR][currC] = "B"
            for dr, dc in directions:
                nr = currR + dr
                nc = currC + dc
                if 0<=nr<row and 0<=nc<col and board[nr][nc] == "M":
                    mines += 1

            if mines == 0:
                for dr, dc in directions:
                    nr = currR + dr
                    nc = currC + dc
                    if 0<=nr<row and 0<=nc<col and board[nr][nc] == "E":
                        board[nr][nc] = "Q"
                        queue.append((nr, nc))
            else:
                board[currR][currC] = str(mines) 
        return board