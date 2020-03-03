class Solution(object):
    
# O(n), but not necessarily faster....
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left = 0
        right = len(nums)-1
        return self.partition(nums, left, right, len(nums)-k)
        
        
    def partition(self, nums, left, right, k):
        
        if left == right:
            return nums[left]
        
        l, r, pivot = left, right, nums[left+(right-left)//2]
        
        while l<=r:
            while l<=r and nums[l] < pivot:
                l+=1
            while l<=r and nums[r] > pivot:
                r-=1
            if l<=r:
                nums[r], nums[l] = nums[l], nums[r]
                l+=1
                r-=1
        
        if k>=l:
            return self.partition(nums, l, right, k)
        elif k<=r:
            return self.partition(nums, left, r, k)
        else:
            return nums[k]