class Solution:
    def minimumSeconds(self, land: List[List[str]]) -> int:
        
# First try
#         row, col = len(land), len(land[0])
#         queue = deque([])
#         destination = (0, 0)
#         start = (0, 0)
#         time = [[math.inf]*col for _ in range(row)]
#         visited = [[False]*col for _ in range(row)]
        
#         for r in range(row):
#             for c in range(col):
#                 if land[r][c] == "*":
#                     queue.append((r, c))
#                     visited[r][c] = True
#                 elif land[r][c] == "D":
#                     destination = (r, c)
#                 elif land[r][c] == "S":
#                     start = (r, c)
#                 elif land[r][c] == "X":
#                     time[r][c] = 0
#         step = 0
#         while queue:
#             for _ in range(len(queue)):
#                 currR, currC = queue.popleft()
#                 if land[currR][currC] != "D":
#                     time[currR][currC] = step
#                 for dr, dc in ((0, 1), (1, 0), (-1, 0), (0, -1)):
#                     nr, nc = currR+dr, currC+dc
#                     if 0<=nr<row and 0<=nc<col and land[nr][nc] not in ("D", "X") and not visited[nr][nc]:
#                         visited[nr][nc] = True
#                         queue.append((nr, nc))
#             step += 1

#         q = deque([start])
#         time[start[0]][start[1]] = 0
#         currT = 0
#         while q:
#             for _ in range(len(q)):
#                 currR, currC = q.popleft()
#                 if (currR, currC) == destination:
#                     return currT
#                 for dr, dc in ((0, 1), (1, 0), (-1, 0), (0, -1)):
#                     nr, nc = currR+dr, currC+dc
#                     if 0<=nr<row and 0<=nc<col and land[nr][nc] != "X" and currT + 1 < time[nr][nc]:
#                         time[nr][nc] = 0
#                         q.append((nr, nc))
#             currT += 1

#         return -1


# two queues, optimal solution

        START, STONE, FLOOD, DESTI, EMPTY = "SX*D."
        row, col = len(land), len(land[0])
        floodQ, startQ = deque(), deque()
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        for r in range(row):
            for c in range(col):
                if land[r][c] == "*":
                    floodQ.append((r, c))
                elif land[r][c] == "S":
                    startQ.append((r, c))
        
        step = 0
        while startQ:
            for _ in range(len(floodQ)):
                currR, currC = floodQ.popleft()
                for dr, dc in directions:
                    nr, nc = currR + dr, currC + dc
                    if 0<=nr<row and 0<=nc<col and land[nr][nc] == EMPTY:
                        land[nr][nc] = FLOOD
                        floodQ.append((nr, nc))
            
            for _ in range(len(startQ)):
                currR, currC = startQ.popleft()
                for dr, dc in directions:
                    nr, nc = currR+dr, currC+dc
                    if 0<=nr<row and 0<=nc<col:
                        if land[nr][nc] == EMPTY:
                            land[nr][nc] = START
                            startQ.append((nr, nc))
                        elif land[nr][nc] == DESTI:
                            return step+1
            step += 1
            
        return -1