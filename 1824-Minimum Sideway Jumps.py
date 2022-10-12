class Solution(object):
    def minSideJumps(self, obstacles):
        """
        :type obstacles: List[int]
        :rtype: int
        """
        curr = [1, 0, 1]
        
        for i in range(len(obstacles)):
            if obstacles[i]:
                curr[obstacles[i]-1] = float('inf')
            for j in range(3):
                if obstacles[i] - 1 != j:
                    curr[j] = min(curr[j], curr[(j+1)%3] + 1, curr[(j+2)%3] + 1)
                    
        return min(curr)