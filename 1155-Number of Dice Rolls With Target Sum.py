class Solution(object):
    def numRollsToTarget(self, d, f, target):
        """
        :type d: int
        :type f: int
        :type target: int
        :rtype: int
        """
# Top down DP
        if d*f < target or d > target:
            return 0
        
        kMod = 1000000007
        memo = dict()
        
        def cal(dice, targetRemain):
            if dice == 0:
                if targetRemain == 0:
                    return 1
                else:
                    return 0  
            if targetRemain < dice or dice*f < targetRemain:
                return 0
            
            if (dice, targetRemain) in memo:
                return memo[(dice, targetRemain)]
            
            res = 0
            for nxt in range(1, f+1):
                if targetRemain < nxt:
                    break
                res = (res + cal(dice-1, targetRemain-nxt))%kMod
                
            memo[(dice, targetRemain)] = res
            return res
        
        ans = cal(d, target)
        
        return ans
    
# bottom up DP
        if d*f < target or d > target:
            return 0
        
        kMod = 1000000007
        dp = [[0]*(target+1) for i in range(d+1)]
        dp[0][0] = 1
        
        for dice in range(1, d+1):
            for diceNum in range(1, f+1):
                for k in range(max(diceNum, dice), target+1):
                    dp[dice][k] = ( dp[dice][k] + dp[dice-1][k-diceNum] )%kMod
                    
        return dp[d][target]