from collections import deque
class Solution(object):
    def findMaxValueOfEquation(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: int
        """
        
# yi + yj + |xi - xj| = xj + yj + (yi - xi)

        queue = deque([])  # [y-x, x], monotonic decreasing queue
        res = float('-inf')
    
        for x, y in points:
            while queue and x - queue[0][1] > k:
                queue.popleft()
            if queue:
                res = max(res, x + y + queue[0][0])
            while queue and y-x > queue[-1][0]:
                queue.pop()
            queue.append([y-x, x])
        return res