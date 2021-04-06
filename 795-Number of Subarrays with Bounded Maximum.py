class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
# Time complexity:O(n), Space complexity:O(1)        
# findSub(B) is the number of subarrays that have all elements less than or equal to B

        def findSub(bound):
            res = curr = 0
            for val in A:
                if val <= bound:
                    curr += 1
                else:
                    curr = 0
                res += curr
            return res
        
        return findSub(R) - findSub(L-1)