import heapq
class Solution(object):
    def furthestBuilding(self, heights, bricks, ladders):
        """
        :type heights: List[int]
        :type bricks: int
        :type ladders: int
        :rtype: int
        """
        minheap = []
        ladderUsed = 0
        for i in range(1, len(heights)):
            diff = heights[i] - heights[i-1]
            if diff <= 0:
                continue
            if ladderUsed < ladders:
                heapq.heappush(minheap, diff)
                ladderUsed += 1
            else:
                heapq.heappush(minheap, diff)
                curr = heapq.heappop(minheap)
                if bricks >= curr:
                    bricks -= curr
                else:
                    return i - 1
        
        return len(heights) - 1