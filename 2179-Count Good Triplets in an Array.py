from sortedcontainers import SortedList
class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        N = len(nums1)
        left = [0]*N
        right = [0]*N
        
        leftSL = SortedList()
        rightSL = SortedList()
        
        valueToIdx = defaultdict(int)
        for i in range(N):
            valueToIdx[nums2[i]] = i
        
        leftSL.add(valueToIdx[nums1[0]])
        for i in range(1, N-1):
            count = leftSL.bisect_left(valueToIdx[nums1[i]])  # how many visited items in nums2 has indexes smaller than valueToIdx[nums1[i]]
            left[i] = count
            leftSL.add(valueToIdx[nums1[i]])
        
        rightSL.add(valueToIdx[nums1[N-1]])
        for i in range(N-2, 0, -1):
            count = len(rightSL) - rightSL.bisect_right(valueToIdx[nums1[i]]) # how many visited items in nums2 has indexes greater than valueToIdx[nums1[i]]
            right[i] = count
            rightSL.add(valueToIdx[nums1[i]])
    
        res = 0
        for i in range(N):
            res += left[i]*right[i]
        
        return res