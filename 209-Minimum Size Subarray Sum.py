class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
# binary search
        preSum = [0]
        res = float('inf')
        
        def bs(num):
            left, right = 0, len(preSum) - 1
            while left + 1 < right:
                mid = left + (right-left)//2
                if preSum[-1] - preSum[mid] >= num:
                    left = mid
                else:
                    right = mid
            if preSum[-1] - preSum[right] >= num:
                return len(preSum) - right - 1
            else:
                return len(preSum) - left - 1
        
        
        for i in range(len(nums)):
            preSum.append(preSum[-1] + nums[i])
            if preSum[-1] - target >= 0:
                res = min(res, bs(target))
        
        return res if res < float('inf') else 0

# sliding window
        res = float('inf')
        left = 0
        curr = 0
        
        for i in range(len(nums)):
            curr += nums[i]
            while curr >= target:
                res = min(res, i - left + 1)
                curr -= nums[left]
                left += 1
        
        return res if res < float('inf') else 0