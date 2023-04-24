from sortedcontainers import SortedList
class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        sl = SortedList()
        res = []
        
        for i in range(len(nums)):
            sl.add(nums[i])
            if i >= k:
                sl.remove(nums[i-k])
            if i >= k-1:
                res.append( min(sl[x-1], 0) )
                
        return res