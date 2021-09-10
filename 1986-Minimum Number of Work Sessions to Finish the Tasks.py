class Solution(object):
    def minSessions(self, tasks, sessionTime):
        """
        :type tasks: List[int]
        :type sessionTime: int
        :rtype: int
        """
# DP, calculate all states, TLE
# dp[state]: time slots needed for a certain state
        
#         n = len(tasks)
#         dp = [float('inf')]*(1<<n)
        
#         # give edge cases
#         for state in range(1, 1<<n):
#             tot = 0
#             for i in range(n):
#                 if (state>>i)&1:
#                     tot += tasks[i]
#             if tot <= sessionTime:
#                 dp[state] = 1
        
#         for state in range(1, 1<<n):
#             for subset in range(state, 0, -1):
#                 dp[state] = min(dp[state], dp[subset&state] + dp[state-(subset&state)])
                
#         return dp[(1<<n)-1]


# Top-down DP , O(n*m*2^n), n:length of tasks, m: sessionTime
# very slow
#         N = len(tasks)
#         memo = dict()
        
#         def dfs(state, remain):
#             if not state:
#                 return 0
            
#             if (state, remain) in memo:
#                 return memo[(state, remain)]
            
#             tot = N
            
#             for i in range(len(tasks)):
#                 if (state >> i)&1:
#                     if remain - tasks[i] >= 0:
#                         tot = min(tot, dfs(state^(1<<i), remain-tasks[i]))
#                     else:
#                         tot = min(tot, 1 + dfs(state^(1<<i), sessionTime-tasks[i]))
            
#             memo[(state, remain)] = tot
#             return tot
                        
#         N = len(tasks)
#         initState = (1<<N)-1
        
#         return dfs(initState, sessionTime) + 1



# Top-down DP , O(n*m*2^n), n:length of tasks, m: sessionTime
# very slow
#         N = len(tasks)
#         memo = dict()
        
#         def dfs(state, remain):
#             if not state:
#                 return 0
            
#             if (state, remain) in memo:
#                 return memo[(state, remain)]
            
#             tot = N
            
#             for i in range(len(tasks)):
#                 if (state >> i)&1:
#                     if remain - tasks[i] >= 0:
#                         tot = min(tot, dfs(state^(1<<i), remain-tasks[i]))
#                     else:
#                         tot = min(tot, 1 + dfs(state^(1<<i), sessionTime-tasks[i]))
            
#             memo[(state, remain)] = tot
#             return tot
                        
#         N = len(tasks)
#         initState = (1<<N)-1
        
#         return dfs(initState, sessionTime) + 1

# Top-down DP , O(n*2^n), n:length of tasks, m: sessionTime
        N = len(tasks)
        memo = dict()
        
        def dp(state):
            if state == 0:
                return [0, 0]
            
            if state in memo:
                return memo[state]
            
            remainCurr = 0
            sessionCurr = float('inf')
            
            # sessions required, remain
            for i in range(N):
                if (state>>i)&1 == 1:
                    sessionNum, remain = dp(state^(1<<i))
                    
                    if tasks[i]<=remain:
                        remain -= tasks[i]
                    else:
                        sessionNum += 1
                        remain = sessionTime-tasks[i]
                        
                    if sessionNum < sessionCurr or (sessionNum == sessionCurr and remain > remainCurr):
                        remainCurr = remain
                        sessionCurr = sessionNum
            memo[state] = [sessionCurr, remainCurr]
            return memo[state]
        
        initState = (1<<N)-1
        
        return dp(initState)[0]
                    