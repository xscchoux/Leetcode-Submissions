class Solution(object):
    def subarraysWithMoreZerosThanOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# Difficult DP
# https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/discuss/1638197/python-O(n2)-greater-O(nlogn)-greater-O(n)

        nums = [1 if x == 1 else -1 for x in nums]
        preSum = [0]
        for num in nums:
            preSum.append(preSum[-1] + num)
        
        kMod = 1000000007
        pre = 0
        smallerCnt = 0   # count the number of prefix arrays that have smaller prefix sum before current index
        hmap = collections.defaultdict(int) # key:numbers in preSum, value:number of prefix arrays with "key" value before current index
        res = 0
        
        for cur in preSum:
            if cur == pre + 1:
                smallerCnt = (smallerCnt + hmap[pre])%kMod
            else:
                smallerCnt = (smallerCnt - hmap[cur])%kMod
            res = (res + smallerCnt)%kMod
            hmap[cur] += 1
            pre = cur
                
        return res