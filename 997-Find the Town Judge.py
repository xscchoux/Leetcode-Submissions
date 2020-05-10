class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        indegree = [0]*N
        outdegree = [0]*N
        
        for a, b in trust:
            outdegree[a-1] += 1
            indegree[b-1] += 1
            
        for i in range(N):
            if indegree[i] == N-1 and outdegree[i] == 0:
                return i+1
        
        return -1