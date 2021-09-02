class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
# Top-down DP + binary search
        N = len(startTime)
        jobs = []
        
        for i in range(len(startTime)):
            jobs.append([startTime[i], endTime[i], profit[i]])
        jobs.sort(key = lambda x: x[0])
        nextIdx = [N]*N
        
        for i in range(N-1):
            left, right = i+1, N-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if jobs[mid][0] >= jobs[i][1]:
                    right = mid
                else:
                    left = mid
                    
            if jobs[left][0]>=jobs[i][1]:
                nextIdx[i] = left
            elif jobs[right][0] >= jobs[i][1]:
                nextIdx[i] = right
            else:
                nextIdx[i] = N
        
        memo = dict()
        def dfs(index):
            if index == N:
                return 0
            if index in memo:
                return memo[index]
            res = max( jobs[index][2] + dfs(nextIdx[index]), dfs(index+1))
            memo[index] = res
            return res
        
        return dfs(0)