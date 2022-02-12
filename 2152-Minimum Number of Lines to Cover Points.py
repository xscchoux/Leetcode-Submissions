class Solution(object):
    def minimumLines(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        N = len(points)
        if N <= 2:
            return 1
        dp = [float('inf')]*(1<<N)
        
        def sameLine(state):
            temp = []
            for i in range(N):
                if (state >> i) & 1:
                    temp.append(i)
            if len(temp) <= 2:
                return True
            X1, Y1 = points[temp[0]]
            X2, Y2 = points[temp[1]]
            for i in range(2, len(temp)):
                currX, currY = points[temp[i]]
                if (currX-X1)*(currY-Y2) != (currX-X2)*(currY-Y1):
                    return False
            return True
        
        for state in range(1, 1<<N):
            if sameLine(state):
                dp[state] = 1

        for state in range(7, 1<<N):
            if dp[state] == 1:
                continue
            substate = state
            while substate > 0:
                dp[state] = min(dp[state], dp[substate] + dp[state-substate])
                substate = state&(substate-1)
        
        return dp[(1<<N)-1]