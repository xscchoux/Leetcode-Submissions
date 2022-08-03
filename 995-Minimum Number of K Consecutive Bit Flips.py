class Solution(object):
    def minKBitFlips(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
# https://www.youtube.com/watch?v=c5o-x_kD8d8&ab_channel=HuifengGuan
        N = len(nums)
        currFlips = 0
        endFlip = [0]*(N+1)
        count = 0
        
        for i in range(N):
            currFlips += endFlip[i]
            if (nums[i] + currFlips%2) == 1:
                continue
            
            if i+k-1 >= N:
                return -1
            
            endFlip[i+k] -= 1
            currFlips += 1
            count += 1
        return count