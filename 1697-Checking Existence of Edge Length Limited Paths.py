from collections import defaultdict
class Solution(object):
    def distanceLimitedPathsExist(self, n, edgeList, queries):
        """
        :type n: int
        :type edgeList: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
# DFS, TLE
#         graph = defaultdict(lambda:defaultdict(list))
#         for start, end, weight in edgeList:
#             graph[start][end].append(weight)
#             graph[end][start].append(weight)
        
#         def dfs(start, end, limit):
#             for nxt in graph[start]:
#                 if nxt not in visited:
#                     if nxt == end:
#                         for length in graph[start][nxt]:
#                             if length < limit:
#                                 return True
#                     else:
#                         boolean = False
#                         for length in graph[start][nxt]:
#                             if length < limit:
#                                 visited.add(nxt)
#                                 if dfs(nxt, end, limit):
#                                     return True
#                                 visited.remove(nxt)
#                                 break
#             return False
                        
#         res = []
        
#         for start, end, limit in queries:
#             visited = set()
#             visited.add(start)
#             if dfs(start, end, limit):
#                 res.append(True)
#             else:
#                 res.append(False)
        
#         return res
    
# Union-Find
        self.parents = {i:i for i in range(n)}
        def find(x):
            path = []
            while x != self.parents[x]:
                path.append(x)
                x = self.parents[x]
            # path compression
            for xx in path:
                self.parents[xx] = x
            return x
        
        def union(x, y):
            px, py = find(x), find(y)
            self.parents[py] = px

        edgeList.sort(key = lambda x:x[2])
        queries = [(start, end, limit, ind) for ind, [start, end, limit] in enumerate(queries)]
        queries.sort(key = lambda x: x[2])
        
        res = [False]*len(queries)
        edgeIndex = 0
        for start, end, limit, queryIndex in queries:
            while edgeIndex < len(edgeList) and edgeList[edgeIndex][2] < limit:
                union(edgeList[edgeIndex][0], edgeList[edgeIndex][1])
                edgeIndex += 1
            if find(start) == find(end):
                res[queryIndex] = True
        return res