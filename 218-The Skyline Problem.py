from sortedcontainers import SortedList
class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
# https://www.youtube.com/watch?v=W2afZs9DYYA
# sol1
        arr = []
        res = []
        for l, r, h in buildings:
            arr.append((l, h, 0))
            arr.append((r, h, 1))
        
        arr.sort()
        
        heights = SortedList([0])
        i = 0
        N = len(arr)
        
        while i < N:
            currX = arr[i][0]

            while i < N and currX == arr[i][0]:
                start, height, label = arr[i]
                if label == 0:
                    heights.add(height)
                else:
                    heights.remove(height)
                i += 1
                
            if not res or heights[-1] != res[-1][1]:
                res.append([start, heights[-1]])
                
        return res
        
# sol2
        arr = []
        res = []
        for l, r, h in buildings:
            arr.append((l, -h, 0))
            arr.append((r, h, 1))
        
        arr.sort()
        
        heights = SortedList([0])
        
        for start, height, label in arr:
            if label == 0:
                heights.add(height)
            else:
                heights.remove(-height)
                
            if not res or heights[-1] != res[-1][1]:
                res.append([start, heights[-1]])
                
        return res