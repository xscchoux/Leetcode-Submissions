# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
#class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#        
#
#    def move(self, direction: str) -> int:
#        
#
#    def isTarget(self) -> None:
#        
#
from heapq import *
class Solution(object):
    def findShortestPath(self, master: 'GridMaster') -> int:
        visited = set()
        pq = []
        heappush(pq, (0, 0, 0, master))
        visited.add((0, 0))
        
        while pq:
            val, r, c, m = heappop(pq)
            if m.isTarget():
                return val
                
            if m.canMove('U') and (r-1, c) not in visited:
                visited.add((r-1, c))
                cost = m.move('U')
                heappush(pq, (val+cost, r-1, c, copy.copy(m)))
                m.move('D')
            if m.canMove('D') and (r+1, c) not in visited:
                visited.add((r+1, c))
                cost = m.move('D')
                heappush(pq, (val+cost, r+1, c, copy.copy(m)))
                m.move('U')
            if m.canMove('L') and (r, c-1) not in visited:
                visited.add((r, c-1))
                cost = m.move('L')
                heappush(pq, (val+cost, r, c-1, copy.copy(m)))
                m.move('R')
            if m.canMove('R') and (r, c+1) not in visited:
                visited.add((r, c+1))
                cost = m.move('R')
                heappush(pq, (val+cost, r, c+1, copy.copy(m)))
                m.move('L')
        
        return -1