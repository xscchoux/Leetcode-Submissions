class Solution(object):
    def maxSubarraySumCircular(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def kadane(A):
            localmax = float('-inf')
            globalmax = float('-inf')
            _sum = 0
            for i in range(len(A)):
                _sum += A[i]
                if localmax < _sum:
                    localmax = _sum
                    if localmax > globalmax:
                        globalmax = localmax
                if _sum < 0:
                    _sum = 0
            return globalmax
            
        kadaneMax = kadane(A)
        
        kadaneMin = (-1)*kadane(  list(map(lambda x: (-1)*x, A)) )
        
        total = sum(A)
        
        if total == kadaneMin:  # edge case: when all elements are negative, total == kadaneMin => total-kadaneMin == 0
            return kadaneMax
        
        return max(kadaneMax, total-kadaneMin)