class Solution(object):
    def minimumTime(self, n, relations, time):
        """
        :type n: int
        :type relations: List[List[int]]
        :type time: List[int]
        :rtype: int
        """
# Topological sort
        graph = defaultdict(list)
        indegree = [0]*n
        timeCost = [0]*n

        for start, end in relations:
            graph[start].append(end)
            indegree[end-1] += 1
        
        queue = deque([])
        for i in range(n):
            if indegree[i] == 0:
                queue.append((time[i], i+1))
                timeCost[i] = time[i]
        
        while queue:
            elapsed, curr = queue.popleft()
            for nxt in graph[curr]:
                if elapsed + time[nxt-1] > timeCost[nxt-1]:
                    timeCost[nxt-1] = elapsed+time[nxt-1]
                indegree[nxt-1] -= 1
                if indegree[nxt-1] == 0:
                    queue.append((timeCost[nxt-1], nxt))
        
        return max(timeCost)