class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        if N <=1:
            return 0
        
        mx = mn = nums[0]
        for i in range(1, len(nums)):
            mx = max(mx, nums[i])
            mn = min(mn, nums[i])
        
        bucketSize = max(1, (mx-mn)//(N-1))
        nb_buckets = (mx-mn)//bucketSize + 1
        bucket = [None]*nb_buckets
        
        for num in nums:
            idx = (num-mn)//bucketSize
            if bucket[idx] == None:
                bucket[idx] = [num, num]   #[max value in this bucket, min value in this bucket]
            else:
                bucket[idx][0] = max(bucket[idx][0], num)
                bucket[idx][1] = min(bucket[idx][1], num)
        
        res = 0
        prev = bucket[0][0]
        
        for i in range(1, nb_buckets):
            if bucket[i] == None:
                continue
            res = max(res, bucket[i][1]- prev)
            prev = bucket[i][0]
                
        return res