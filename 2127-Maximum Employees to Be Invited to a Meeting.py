class Solution(object):
    def maximumInvitations(self, favorite):
        """
        :type favorite: List[int]
        :rtype: int
        """
        N = len(favorite)
        favMap = collections.defaultdict(set) # {favoritePerson: {employee1, employee2,...}}
        
        for ind, val in enumerate(favorite):
            favMap[val].add(ind)
        
        cycles = []
        length = [1]*N 
        
# use DFS to find all cycles (start, length)
        for i in range(N):
            if favorite[i] != -1:
                visited = set([i])
                while favorite[i] != -1:
                    nxt = favorite[i]
                    favorite[i] = -1
                    if nxt in visited:
                        cycles.append((nxt, length[i]-length[nxt]+1))
                        break
                    else:
                        visited.add(nxt)
                        length[nxt] = length[i] + 1
                        i = nxt
# BFS
        def addExtension(start, visited):
            queue = deque([(start, 0)]) # start, length
            ans = 0
            while queue:
                for _ in range(len(queue)):
                    curr, length = queue.popleft()
                    for nxt in favMap[curr]:
                        if nxt not in visited:
                            queue.append((nxt, length+1))
                            ans = max(ans, length+1)
            return ans
        
        maxCycle = cycle2 = 0
        
        for start, totLen in cycles:
            if totLen > 2:
                maxCycle = max(maxCycle, totLen)
            else:
                u, v = start, [nxt for nxt in favMap[start] if start in favMap[nxt] ][0]
                cycle2 += 2 + addExtension(u, set([u, v])) + addExtension(v, set([v, u]))
        
        return max(maxCycle, cycle2)
