from sortedcontainers import SortedList
class Solution:
    def minThreshold(self, nums: List[int], k: int) -> int:

        def isOK(threshold):
            sl = SortedList()
            cnt = 0
            for i in range(len(nums)-1, -1, -1):
                cnt += sl.bisect_right(nums[i]-1) - sl.bisect_left(nums[i]-threshold)
                if cnt >= k:
                    return True
                sl.add(nums[i])

            return False


        left, right = 1, max(nums) - min(nums)
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid
        
        if (isOK(left)):
            return left
        elif isOK(right):
            return right
        else:
            return -1
