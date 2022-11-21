class Solution(object):
    def minimumFuelCost(self, roads, seats):
        """
        :type roads: List[List[int]]
        :type seats: int
        :rtype: int
        """
# BFS, topological sort
        graph = collections.defaultdict(list)
        size = [1]*(len(roads)+1)
        indegree = [0]*(len(roads)+1)
        
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
            indegree[u] += 1
            indegree[v] += 1
        
        queue = collections.deque([x for x in range(len(indegree)) if indegree[x] == 1 and x!= 0])
        visited = set()
        res = 0
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                visited.add(curr)
                for nxt in graph[curr]:
                    if nxt in visited:
                        continue
                    indegree[nxt] -= 1
                    q, r = divmod(size[curr], seats)
                    res += q if r==0 else q+1
                    size[nxt] += size[curr]
                    if indegree[nxt] == 1 and nxt != 0:
                        queue.append(nxt)
        return res
    
# DFS
# https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/discuss/2834516/Python-DFS-Picture-explanation-O(N)
        graph = collections.defaultdict(list)
        self.res = 0   
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
        
        def dfs(curr, par):
            tot = 1
            for nxt in graph[curr]:
                if nxt == par:
                    continue
                tot += dfs(nxt, curr)
            if curr != 0:
                self.res += tot//seats if tot%seats == 0 else tot//seats+1
            return tot
        
        dfs(0, -1)
        return self.res
            
            