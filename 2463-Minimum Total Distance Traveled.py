class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        factory.sort()
        robot.sort()
        rLen, fLen = len(robot), len(factory)
        
        @cache
        def dp(r, f, remain):
            if r == rLen:
                return 0
            
            if remain == 0:
                if f+1 < fLen:
                    return dp(r, f+1, factory[f+1][1])
                else:
                    return math.inf
            else:
                ans = dp(r+1, f, remain-1) + abs(robot[r] - factory[f][0])
                if f+1 < fLen:
                    ans = min(ans, dp(r, f+1, factory[f+1][1]))
        
            return ans
        
        res = dp(0, 0, factory[0][1])
        
        return res