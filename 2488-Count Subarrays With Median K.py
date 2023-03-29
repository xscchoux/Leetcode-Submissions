class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        
        for i in range(len(nums)):
            if nums[i] < k:
                nums[i] = -1
            elif nums[i] == k:
                nums[i] = 0
            else:
                nums[i] = 1
                
        found = False
        preSum = defaultdict(int)
        preSum[0] = 1
        tot = res = 0
        
        for i in range(len(nums)):
            if nums[i] == 0:
                found = True
            tot += nums[i]
            if found:
                res += preSum[tot] + preSum[tot-1]
            else:
                preSum[tot] += 1

        return res