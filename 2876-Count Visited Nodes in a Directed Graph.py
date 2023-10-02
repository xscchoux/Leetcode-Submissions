class Solution:
    def countVisitedNodes(self, edges: List[int]) -> List[int]:
        # use topological sort to find nodes in cycle and nodes not in cycle
        # n nodes numbered from 0 to n - 1 and n directed edges -> there's at least one cycle
        
        N = len(edges)
        indegree = [0]*N
        res = [0]*N
        
        for u in edges:
            indegree[u] += 1
            
        queue = deque([i for i in range(N) if indegree[i] == 0])
        nodesOutCycle = set()
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                nodesOutCycle.add(curr)
                nxt = edges[curr]
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)

        # get answers for nodes in cycles
        visited = set()
        for node in set(range(N)) - nodesOutCycle:
            if node not in visited:
                tmp = node
                cycle = []
                while tmp not in visited:
                    visited.add(tmp)
                    cycle.append(tmp)
                    tmp = edges[tmp]
                for x in cycle:
                    res[x] = len(cycle)

        # get answers for nodes not in cycles
        @cache
        def dfs(curr):
            if res[curr] != 0:
                return res[curr]
            return 1 + dfs(edges[curr])
        
        # nodesOutCycle = [i for i in range(N) if indegree[i] == 0]
        for node in nodesOutCycle:
            res[node] = dfs(node)
            
        return res