class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
# binary search , time complexity:O(n*n*logn), space complexity:O(1)
        n = len(nums)
        res = 0
        nums.sort()
        
        for i in range(n-2):
            for j in range(i+1, n-1):
                left, right = j+1, n-1
                tot = nums[i] + nums[j]
                while left + 1 < right:
                    mid = left + (right-left)//2
                    if nums[mid] >= tot:
                        right = mid
                    else:
                        left = mid
                if nums[right] < tot:
                    res += right - j
                elif nums[left] < tot:
                    res += left-j
        return res
    
# O(n^2)
        nums.sort()
        n = len(nums)
        res = 0
        
        for k in range(n-1, 1, -1):
            i, j = 0, k-1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    res += j-i
                    j-=1
                else:
                    i+=1
        return res