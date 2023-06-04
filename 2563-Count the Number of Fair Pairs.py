class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        
        def count(mx):
            i, j = 0, len(nums)-1
            res = 0
            while i < j:
                if nums[i] + nums[j] > mx:
                    j -= 1
                else:
                    res += j - i
                    i += 1    
            return res
        
        return count(upper) - count(lower-1)