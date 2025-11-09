from sortedcontainers import *
class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        arr = []
        for i in range(len(nums)):
            if nums[i] == target:
                arr.append(1)
            else:
                arr.append(-1)

        preSum = []
        preSum.append(arr[0])
        for i in range(1, len(arr)):
            preSum.append(preSum[-1] + arr[i])
        
        res = 0
        sl = SortedList()
        sl.add(0)  # note that we need to add zero here

        for i in range(len(preSum)):
            curr = preSum[i]
            idx = sl.bisect_left(curr)
            res += idx
            sl.add(preSum[i])
        
        return res