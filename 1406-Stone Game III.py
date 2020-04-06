class Solution(object):
    def stoneGameIII(self, stoneValue):
        """
        :type stoneValue: List[int]
        :rtype: str
        """
        aliceScore = 0
        memo = dict()
        n = len(stoneValue)
        
        def score(start):
            if start >= n:
                return 0
            
            if start in memo:
                return memo[start]
            
            best = float('-inf')
            
            for i in range(start+1, min(start+4,n+1)):
                best = max(best, sum(stoneValue[start:i]) - score(i))
            memo[start] = best
            
            return best

        res = score(0)
        if res < 0:
            return "Bob"
        elif res == 0:
            return "Tie"
        else:
            return "Alice"