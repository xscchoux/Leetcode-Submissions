from heapq import heappush, heappop
class Solution(object):
    def findShortestWay(self, maze, ball, hole):
        """
        :type maze: List[List[int]]
        :type ball: List[int]
        :type hole: List[int]
        :rtype: str
        """
        
        row, col = len(maze), len(maze[0])
        dist = [[float('inf')]*col for _ in range(row)]
        pq = [(0, "", ball[0], ball[1])]
        res = ""
        
        rMap = {"d":1, "l":0, "r":0, "u":-1}
        cMap = {"d":0, "l":-1, "r":1, "u":0}
        
        def nextNode(direction, r, c):
            ans = 0
            while True:
                dr, dc = rMap[direction], cMap[direction]
                if r+dr>=0 and r+dr<row and c+dc>=0 and c+dc<col and maze[r+dr][c+dc] == 0:
                    r = r + dr
                    c = c + dc
                    ans += 1
                    if r==hole[0] and c==hole[1]:
                        return ans, r, c
                else:
                    break
            return ans, r, c
        
        while pq:
            d, string, r, c = heappop(pq)
            if d > dist[r][c]:
                continue
            else:
                dist[r][c] = d
            
            if r == hole[0] and c == hole[1]:
                res = string
                break
            
            for direction in "dlru":
                toMove, nr, nc = nextNode(direction, r, c)
                if d + toMove >= dist[nr][nc]:
                    continue
                heappush(pq, (d+toMove, string+direction, nr, nc))
        
        if not res:
            return "impossible"
        
        return res