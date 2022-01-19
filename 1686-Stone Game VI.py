class Solution(object):
    def stoneGameVI(self, aliceValues, bobValues):
        """
        :type aliceValues: List[int]
        :type bobValues: List[int]
        :rtype: int
        """
        # score difference: xi*A[i] + (1-xi)*B[i] = xi*(A[i]+B[i]) - B[i],  xi = 0 or 1, i: 0 ~ N-1
        
        N = len(aliceValues)
        sumArr = [aliceValues[i]+bobValues[i] for i in range(N)]
        sumArr.sort(reverse=True)
        tot = 0
        
        for i in range(0, N, 2):
            tot += sumArr[i]
        
        tot -= sum(bobValues)
        
        if tot > 0:
            return 1
        elif tot == 0:
            return 0
        else:
            return -1