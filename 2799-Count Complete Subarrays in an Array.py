class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
    # O(N^2)
        N = len(nums)
        num = len(set(nums))
        res = 0

        for i in range(N):
            distinct = defaultdict(int) 
            for j in range(i, N):
                distinct[nums[j]] += 1
                if len(distinct) == num:
                    res += N - j
                    break

        return res
    
    # O(N)
        N = len(nums)
        num = len(set(nums))
        distinct = defaultdict(int)
        res = 0
        left = 0
        
        for i in range(N):
            distinct[nums[i]] += 1 
            while len(distinct) == num:
                distinct[nums[left]] -= 1
                if not distinct[nums[left]]:
                    del distinct[nums[left]]
                left += 1
            res += left # means the subarray starting at 0,1,..,left-1 and end at i have k distinct elements.
        return res