class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        # https://www.youtube.com/watch?v=Gt_DhTM5oRQ
        # dp[i][j]: value got starting from player i and was passed 2^j times
        # pos[i][j]: player index starting from player i and was passed 2^j times
        
        N = len(receiver)
        M = int(log2(k))
        dp = [[0]*(M+1) for _ in range(N)]
        pos = [[-1]*(M+1) for _ in range(N)]
        
        for i in range(N):
            dp[i][0] = receiver[i]
            pos[i][0] = receiver[i]
        
        for j in range(1, M+1):
            for i in range(N):
                dp[i][j] = dp[i][j-1] + dp[pos[i][j-1]][j-1]
                pos[i][j] = pos[pos[i][j-1]][j-1]
        
        bitArr, bit = [], 0
        while k > 0:
            if k&1:
                bitArr.append(bit)
            bit += 1
            k = k//2
        
        res = 0
        
        for i in range(N):
            currVal = i
            currPos = i
            for bit in bitArr:
                currVal += dp[currPos][bit]
                currPos = pos[currPos][bit]
            res = max(res, currVal)
            
        return res