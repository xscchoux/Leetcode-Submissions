from heapq import heappush, heappop
class Solution(object):
    def kthSmallestPrimeFraction(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        pq = []
        for i in range(1, len(arr)):
            heappush(pq, (arr[0]/float(arr[i]), 0, i))
            
        for _ in range(k-1):
            _, i, j = heappop(pq)
            if i+1 < j:
                heappush(pq, (arr[i+1]/float(arr[j]), i+1, j))
        
        return [arr[pq[0][1]], arr[pq[0][2]]]