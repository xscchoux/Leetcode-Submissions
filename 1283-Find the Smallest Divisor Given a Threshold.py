class Solution(object):
    def smallestDivisor(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        right = max(nums)
        left = 1
        
        def getPieces(mid):
            count = 0
            for i in range(len(nums)):
                count += -(-nums[i]//mid)  # how did someone come up with this??
            return count
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if getPieces(mid) > threshold:
                left = mid
            else:
                right = mid
 
        if getPieces(left) <= threshold:
            return left
        else:
            return right