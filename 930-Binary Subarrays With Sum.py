class Solution(object):
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        prevSum = dict()
        prevSum[0] = 1
        res = 0
        total = 0
        
        for i in range(len(A)):
            total += A[i]
            if total-S in prevSum:
                res += prevSum[total-S]
            prevSum[total] = prevSum.get(total, 0) + 1
            
        return res