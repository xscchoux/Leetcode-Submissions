class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        tmp = nums[:]
        N = len(nums)
        tmp.sort()
        j, k = -(-N//2)-1, N-1

        for i in range(len(nums)):
            if i%2 == 0:
                nums[i] = tmp[j]
                j-=1
            else:
                nums[i] = tmp[k]
                k-=1