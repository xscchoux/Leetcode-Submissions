import heapq
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        
# use heap
# Time complexity: O(nlogn)
        used = set()
        heap = []
        heapq.heappush(heap, 1)
        res = []
        for i in range(n):
            curr = heapq.heappop(heap)
            res.append(curr)
            for i in (2,3,5):
                if curr*i not in used:
                    heapq.heappush(heap, curr*i)
                    used.add(curr*i)
        
        return res[-1]
        
# dp
# Time complexity: O(n)
# https://www.geeksforgeeks.org/ugly-numbers/
        res = [1]
        i2, i3, i5 = 0, 0, 0
        while len(res) <n:
            _next = min(res[i2]*2, res[i3]*3, res[i5]*5)
            if _next == res[i2]*2:
                i2 += 1
            if _next == res[i3]*3:
                i3 += 1
            if _next == res[i5]*5:
                i5 += 1
            res.append(_next)
            
        return res[-1]