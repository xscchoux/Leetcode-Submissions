from sortedcontainers import SortedList
class Solution:
    def minInversionCount(self, nums: List[int], k: int) -> int:
        N = len(nums)
        smallerCnt = [0]*N
        res = float('inf')
        sl = SortedList()

        for i in range(N-1, -1, -1):
            sl.add(nums[i])
            if i + k - 1 <= N-1:
                idx = sl.bisect_left(nums[i])
                smallerCnt[i] = idx
                sl.discard(nums[i+k-1])

        cnt = 0
        sl.clear()
        for i in range(N):
            greaterIdx = sl.bisect_right(nums[i])
            cnt += len(sl) - greaterIdx
            sl.add(nums[i])
            if i >= k-1:
                res = min(res, cnt)
            
            # remove leftmost element in the k-size window
            if i-k+1>=0:
                cnt -= smallerCnt[i-k+1]
                sl.discard(nums[i-k+1])
        
        return res



