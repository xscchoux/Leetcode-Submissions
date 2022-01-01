class Solution(object):
    def maxVacationDays(self, flights, days):
        """
        :type flights: List[List[int]]
        :type days: List[List[int]]
        :rtype: int
        """
#O(n^2 * k)
        totWeek = len(days[0])
        n = len(flights)
        self.res = 0
        memo = [[float('-inf')]*n for _ in range(totWeek)]
        
        def cal(week, currIdx):
            if week == totWeek:
                return 0

            if memo[week][currIdx] != float('-inf'):
                return memo[week][currIdx]
            
            res = 0
            
            for i in range(n):
                if i == currIdx or flights[currIdx][i] == 1:
                    vac = days[i][week] + cal(week+1, i)
                    res = max(res, vac)
            memo[week][currIdx] = res
            return res
            
            
        return cal(0, 0)