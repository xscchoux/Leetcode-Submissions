class Solution(object):
    def buildWall(self, height, width, bricks):
        """
        :type height: int
        :type width: int
        :type bricks: List[int]
        :rtype: int
        """
# O(height* 2^9 * 2^9)
# https://www.youtube.com/watch?v=VEKCugXXRMw
        kMod = 1000000007
        states = []
        brickSet = set(bricks)
        
        for currState in range(0, 1<<(width-1) ):
            candidate = [-1]

            for i in range(width-1):
                if (currState >> i) & 1:
                    candidate.append(i)
            candidate.append(width-1)
            canAdd = True
            for i in range(1, len(candidate)):
                if candidate[i] - candidate[i-1] not in brickSet:
                    canAdd = False
                    break
            if canAdd:
                states.append(currState)
                
        # dp[i][j]: the number of brick plans for the first i rows and use jth state for the i-th row
        
        dp = [ [0]*len(states) for h in range(height)]
        
        for j in range(len(states)):
            dp[0][j] = 1
            
        for h in range(1, height):
            for j in range(len(states)):
                for k in range(len(states)):
                    if states[j] & states[k] == 0:
                        dp[h][j] = (dp[h][j] + dp[h-1][k])%kMod
        res = 0
        for j in range(len(states)):
            res = (res + dp[height-1][j])%kMod
            
        return res
            