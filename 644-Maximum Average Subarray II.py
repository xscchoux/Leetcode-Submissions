class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:

# O( N*log((max-min)/(10^-5)) )
        mx, mn = float('-inf'), float('inf')
        for num in nums:
            mn = min(mn, num)
            mx = max(mx, num)

        def isValidAvg(avg):  # return True if we have averge values in the subarrays greater or equal to avg 
            tot = prev = 0
            mnPrev = 0
            
            for i in range(k):
                tot += nums[i] - avg
            if tot >= 0:
                return True
            for i in range(k, len(nums)):
                tot += nums[i] - avg
                prev += nums[i-k] - avg
                mnPrev = min(mnPrev, prev)
                if tot - mnPrev >= 0:
                    return True
            return False
        
        left, right = mn, mx  # min of avg, max of avg
        
        while left + 0.00001 < right:
            mid = left + (right-left)/2
            if isValidAvg(mid):
                left = mid
            else:
                right = mid

        return left