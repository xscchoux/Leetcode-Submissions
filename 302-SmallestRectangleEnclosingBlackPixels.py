from collections import deque
class Solution(object):
    def minArea(self, image, x, y):
        """
        :type image: List[List[str]]
        :type x: int
        :type y: int
        :rtype: int
        """
# BFS

        row = len(image)
        col = len(image[0])
        queue = deque([])
        queue.append((x,y))
        visited = set()
        visited.add((x,y))

        left, right = y,y
        up, down = x,x
        
        while queue:
            currX, currY = queue.popleft()
            right = max(right, currY)
            left = min(left, currY)
            up = min(up, currX)
            down = max(down, currX)
            for dx, dy in ((1,0),(0,1),(-1,0),(0,-1)):
                newX = currX + dx
                newY = currY + dy
                if 0<=newX<row and 0<=newY<col and (newX, newY) not in visited and image[newX][newY] == "1":
                    queue.append((newX, newY))
                    visited.add((newX, newY))

        return (right-left+1)*(down-up+1)