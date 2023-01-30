from sortedcontainers import SortedList
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        
# O(N^2 logN)
        sl = SortedList()
        sl.add(nums[0])
        res = 0
        
        for j in range(1, len(nums)-2):
            lcount = 1 if nums[j] < nums[-1] else 0
            for k in range(len(nums)-2, j, -1):
                if nums[k] > nums[j]:
                    lcount += 1
                    continue
                res += sl.bisect_left(nums[k])*lcount
            sl.add(nums[j])
        return res
    
# O(N^2), got TLE sometimes
        maxValue = len(nums) + 1
        pre = [[0]*(maxValue+1) for i in range(len(nums)+1)] # less than v
        post = [[0]*(maxValue+1) for i in range(len(nums)+1)] # greater than v
        res = 0
        
        for i in range(len(nums)):
            for v in range(1, maxValue):
                if nums[i] < v:
                    pre[i+1][v] = pre[i][v] + 1
                else:
                    pre[i+1][v] = pre[i][v]
        
        for i in range(len(nums)-1, -1, -1):
            for v in range(1, maxValue):
                if nums[i] > v:
                    post[i][v] = post[i+1][v] + 1
                else:
                    post[i][v] = post[i+1][v]        
        
        for j in range(1, len(nums)-2):
            for k in range(j+1, len(nums)-1):
                if nums[j] > nums[k]:
                    res += pre[j][nums[k]]*post[k+1][nums[j]]
        
        return res