class Solution:
    def minOperations(self, nums: List[int]) -> int:
        N = len(nums)
        curr = 0

        for num in reversed(nums):
            curr *= 2
            curr += num

        mask = 7
        op = 0

        for i in range(N):
            if (curr&1) == 0:
                if i >= N-2:
                    return -1
                curr = curr^mask
                op+=1
            curr >>= 1

        return op