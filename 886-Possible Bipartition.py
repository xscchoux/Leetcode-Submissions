from collections import deque, defaultdict
class Solution(object):
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        
        graph = defaultdict(list)
        
        for d in dislikes:
            graph[d[0]-1].append(d[1]-1)
            graph[d[1]-1].append(d[0]-1)
        
        colors = [0]*N
        queue = deque([])
        
        for i in range(N):
            if colors[i] != 0:
                continue
            colors[i] = 1
            queue.append(i)
            
            while queue:
                cur = queue.popleft()
                for nxt in graph[cur]:
                    if colors[nxt] == colors[cur]:
                        return False
                    if colors[nxt]!=0:
                        continue
                    colors[nxt] = -colors[cur]
                    queue.append(nxt)
        
        return True