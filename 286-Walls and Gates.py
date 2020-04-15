from collections import deque
class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
# time complexity: O(mn)
        if not rooms or not rooms[0]:
            return
        
        row = len(rooms)
        col = len(rooms[0])
        
        queue = deque([])
        
        for r in range(row):
            for c in range(col):
                if rooms[r][c] == 0:
                    queue.append((r,c,0))
                    
        while queue:
            size = len(queue)
            for _ in range(size):
                currR, currC, step = queue.popleft()
                for dr, dc in ((1,0),(0,1),(-1,0),(0,-1)):
                    newR = currR + dr
                    newC = currC + dc
                    if 0<=newR<row and 0<=newC<col and rooms[newR][newC] == 2147483647:
                        rooms[newR][newC] = step+1
                        queue.append((newR, newC, step+1))