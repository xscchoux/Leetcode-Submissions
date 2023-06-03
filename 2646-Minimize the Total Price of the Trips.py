class Solution:
    def minimumTotalPrice(self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]) -> int:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        count = {i:0 for i in range(n)}
            
        for s, e in trips:
            count[s] += 1
            def dfs(curr, parent):
                if curr == e:
                    return True
                for nxt in graph[curr]:
                    if nxt != parent:
                        count[nxt] += 1
                        if dfs(nxt, curr):
                            return True
                        count[nxt] -= 1
            dfs(s, -1)

        @cache
        def cal(curr, parent):
            notHalf = canHalf = 0
            for nxt in graph[curr]:
                if nxt == parent:
                    continue
                whole, half = cal(nxt, curr)
                notHalf += whole
                canHalf += min(whole, half)
            return count[curr]*price[curr] + canHalf, count[curr]*price[curr]//2 + notHalf 

        return min(cal(0, -1))