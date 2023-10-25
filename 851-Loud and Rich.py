class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        # Pick people with equal or more money and with smallest quiet[i]
# First try, MLE
#         parent = defaultdict(list)
#         N = len(quiet)
        
#         for p, c in richer:
#             parent[c].append(p)
        
#         richerIdx = defaultdict(list)
        
#         @cache
#         def dfs(idx):
#             tot = []
#             tot.append(idx)
#             for c in parent[idx]:
#                 tot.extend(dfs(c))
            
#             return tot
        
#         for i in range(N):
#             richerIdx[i] = dfs(i)

#         res = []
#         for i in range(N):
#             mn = float('inf')
#             index = 0
#             for idx in richerIdx[i]:
#                 if quiet[idx] < mn:
#                     mn = quiet[idx]
#                     index = idx
#             res.append(index)
        
#         return res


        graph = defaultdict(list)
        N = len(quiet)
        indegree = [0]*N
        
        for u, v in richer:
            graph[u].append(v)
            indegree[v] += 1
        
        queue = deque([i for i, x in enumerate(indegree) if x == 0])
        res = [i for i in range(N)]
        index = [i for i in range(N)]
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                for nxt in graph[curr]:
                    if quiet[curr] < quiet[nxt]:
                        quiet[nxt] = quiet[curr]
                        index[nxt] = index[curr]
                    indegree[nxt] -= 1
                    if indegree[nxt] == 0:
                        queue.append(nxt)
                        
        return index