from collections import deque
class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        visited = set()
        
        queue = deque([(0,0,0)])
        visited.add((0,0))
        
        x, y = abs(x), abs(y)
        
        while queue:
            for _ in range(len(queue)):
                currX, currY, step = queue.popleft()
                if currX == x and currY == y:
                    return step
                for dx, dy in ((1,2),(2,1),(2,-1),(1,-2),(-1,2),(-2,1),(-2,-1),(-1,-2)):
                    newX = currX + dx
                    newY = currY + dy
                    if -2 <= newX <= x+2 and -2 <= newY <= y+2 and (newX, newY) not in visited:
                        visited.add((newX, newY))
                        queue.append((newX, newY, step+1))