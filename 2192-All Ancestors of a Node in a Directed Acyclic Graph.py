from collections import deque
class Solution(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        res = [set() for _ in range(n)]
        indegree = [0]*n
        hmap = collections.defaultdict(list)
        
        for u, v in edges:
            hmap[u].append(v)
            indegree[v] += 1
        
        queue = deque([])
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)
                
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                for nxt in hmap[curr]:
                    res[nxt].add(curr)
                    res[nxt] = res[nxt] | res[curr]
                    indegree[nxt] -= 1
                    if indegree[nxt] == 0:
                        queue.append(nxt)
                        
        return list(map(lambda x: sorted(list(x)), res))