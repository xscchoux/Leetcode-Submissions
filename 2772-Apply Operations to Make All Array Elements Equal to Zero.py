class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        N = len(nums)
        addBack = [0]*(N+1) # fix the operation
        operation = 0 # zero or a negative number, the operation we're going to apply on nums[i]
        
        for i in range(len(nums)):
            operation += addBack[i]
            if nums[i] + operation < 0:
                return False
            diff = nums[i] + operation
            if diff > 0:
                if i + k > N:
                    return False
                addBack[i+k] += diff
            operation -= diff

        return True