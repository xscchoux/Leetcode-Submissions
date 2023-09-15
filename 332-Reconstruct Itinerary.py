class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        
# backtracking, very hard to estimate its time complexity
        usedPath = set()
        tickets.sort()
        graph = defaultdict(list)
        res = []
        
        for i, (u, v) in enumerate(tickets):
            graph[u].append((v, i))

        self.res = []

        def dfs(curr, path):
            if len(usedPath) == len(tickets):
                self.res = path
                return True
            for nxt, idx in graph[curr]:
                if (curr, nxt, idx) in usedPath:
                    continue
                usedPath.add((curr, nxt, idx))
                if dfs(nxt, path + [nxt]):
                    return True
                usedPath.remove((curr, nxt, idx))
                
            return False
            
        dfs("JFK", ["JFK"])

        return self.res


# Eulerian path
# Hierholzer's Algorithm

        graph = defaultdict(list)
        for u, v in tickets:
            graph[u].append(v)
        
        for u, v in graph.items():
            graph[u] = sorted(v, reverse=True)
            
        self.res = []
        
        def dfs(curr):
            arr = graph[curr]
            while arr:
                nxt = arr.pop()
                dfs(nxt)
            self.res.append(curr)
        
        dfs("JFK")
        
        return self.res[::-1]