from sortedcontainers import SortedList
class Solution:
    def kBigIndices(self, nums: List[int], k: int) -> int:
        if len(nums) < 2*k+1:
            return 0
        sl1, sl2 = SortedList(), SortedList()
        res = 0
        
        for i in range(k):
            sl1.add(nums[i])
            
        for j in range(k+1, len(nums)):
            sl2.add(nums[j])

        for kk in range(k, len(nums)-k):
            if sl1.bisect_left(nums[kk]) >= k and sl2.bisect_left(nums[kk]) >= k:
                res += 1
            sl1.add(nums[kk])
            sl2.remove(nums[kk+1])

        return res