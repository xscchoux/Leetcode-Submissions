class Solution(object):
    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
# Brute force, TLE
#         graph = defaultdict(list)
#         for edge in edges:
#             graph[edge[0]] += [edge[1]]
#             graph[edge[1]] += [edge[0]]
        
#         def dfs(i, prev):
#             visited.add(i)
#             dist = 0
#             for nxt in graph[i]:
#                 if nxt not in visited:
#                     dist += prev+1
#                     dist += dfs(nxt, prev+1)
#             return dist
        
#         visited = set()
#         res = [0]*N
        
#         for i in range(N):
#             res[i] = dfs(i, 0)
#             visited = set()
            
#         return res

# O(n)
        count = [0]*N
        subRes = [0]*N
        graph = collections.defaultdict(list)
        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)
            
        def dfs(curr, prev):
            for nxt in graph[curr]:
                if nxt == prev:
                    continue
                dfs(nxt, curr)
                subRes[curr] += (count[nxt] + subRes[nxt])
                count[curr] += count[nxt]
            count[curr] += 1
            
        def dfs2(curr, prev):
            for nxt in graph[curr]:
                if nxt == prev:
                    continue
                subRes[nxt] += (N - count[nxt]) + (subRes[curr]-subRes[nxt]-count[nxt])
                dfs2(nxt, curr)
                
        dfs(0, None)
        dfs2(0, None)
        
        return subRes