from collections import defaultdict
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        if not M or not M[0]:
            return 0
# create a connected graph
        graph = defaultdict(list)
        row = len(M)
        col = len(M[0])
        for r in range(row):
            for c in range(col):
                if M[r][c] == 1:
                    graph[r].append(c)
        
        visited = set()
        
        def dfs(start):
            for friend in graph[start]:
                if friend not in visited:
                    visited.add(friend)
                    dfs(friend)
        
        count = 0
        for i in range(row):
            if i not in visited:
                visited.add(i)
                dfs(i)
                count+= 1
        
        return count