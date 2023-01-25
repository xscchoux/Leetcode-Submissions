class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        
        N = len(board)
        queue = collections.deque([(1, 0)])
        visited = set([1])
        
        while queue:
            for _ in range(len(queue)):
                pos, step = queue.popleft()
                for forward in range(1, min(N*N-pos+1, 7)):
                    nxt = pos + forward
                    row = N-1-(nxt-1)//N
                    col = (nxt-1)%N if (N-1-row)%2 == 0 else (N - nxt%N)%N
                    if board[row][col] != -1:
                        nxt = board[row][col]
                    if nxt == N*N:
                        return step+1
                    if nxt not in visited:
                        visited.add(nxt)
                        queue.append((nxt, step+1))

        return -1