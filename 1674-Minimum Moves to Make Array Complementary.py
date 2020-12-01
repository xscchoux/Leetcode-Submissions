from collections import defaultdict
class Solution(object):
    def minMoves(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
# sweep line algorithm
        n = len(nums)
        diff = defaultdict(int)
        ssum = defaultdict(int)
        
        for i in range(0, n//2):
            a = nums[i]
            b = nums[n-1-i]
            maxNum = max(a,b)
            minNum = min(a,b)
            diff[minNum+1] -= 1
            diff[maxNum + limit + 1] += 1    
            ssum[a+b] -= 1
        
        cur = n
        res = n
        
        for pairSum in range(2, max(ssum)+1):
            cur += diff[pairSum]
            res = min(res, cur + ssum[pairSum])
        
        return res