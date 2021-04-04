class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
# two edge cases
        if desiredTotal <= 0:
            return True
        if maxChoosableInteger*(maxChoosableInteger+1)//2 < desiredTotal:
            return False
        
        bitmask = 0
        memo = dict()
        
        def dfs(remain, bitmask):
            if remain <= 0:
                return False
            if bitmask in memo:
                return memo[bitmask]
            for i in range(maxChoosableInteger):
                if (bitmask & (1<<i)):
                    continue
                if not dfs(remain-i-1, bitmask|(1<<i)):
                    memo[bitmask] = True
                    return True
            memo[bitmask] = False
            return False
        
        res = dfs(desiredTotal, bitmask)
        return res