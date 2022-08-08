from heapq import heappush, heappop
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
# Sol 1
        pq, res = [], []
        
        for i in range(min(k, len(nums1))):
            heappush(pq, (nums1[i] + nums2[0], i, 0))
        
        while pq and k > 0:
            curr, i, j = heappop(pq)
            res.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heappush(pq, (nums1[i]+nums2[j+1], i, j+1))
            k -= 1
        return res
    
# Sol2, better

        pq, res = [], []
        
        heappush(pq, (nums1[0] + nums2[0], 0, 0))
        
        while pq and k > 0:
            curr, i, j = heappop(pq)
            res.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heappush(pq, (nums1[i]+nums2[j+1], i, j+1))
            if j == 0 and i + 1 < len(nums1):
                heappush(pq, (nums1[i+1]+nums2[j], i+1, j))
            k -= 1
        return res