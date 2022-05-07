from heapq import heappush, heappop
class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """
        projects = sorted(zip(capital, profits))
        available = []
        ind = 0
        while k > 0:
            while ind < len(projects) and w >= projects[ind][0]:
                heappush(available, -1*projects[ind][1])
                ind += 1
            if not available:
                return w
            w -= heappop(available)
            k -= 1
            
        return w