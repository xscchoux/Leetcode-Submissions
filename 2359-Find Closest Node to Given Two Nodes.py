class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        N = len(edges)

        dist1 = [-1]*N
        dist2 = [-1]*N
        
        queue1 = collections.deque([(node1, 0)])
        while queue1:
            curr, step = queue1.popleft()
            dist1[curr] = step
            if edges[curr] != -1 and dist1[edges[curr]] == -1:
                queue1.append((edges[curr], step+1))
                
        queue2 = collections.deque([(node2, 0)])
        while queue2:
            curr, step = queue2.popleft()
            dist2[curr] = step
            if edges[curr] != -1 and dist2[edges[curr]] == -1:
                queue2.append((edges[curr], step+1))
        
        longest = N
        res = -1
        for i in range(len(dist1)):
            if dist1[i] != -1 and dist2[i] != -1:
                curr_longest = max(dist1[i], dist2[i])
                if curr_longest < longest:
                    longest = curr_longest
                    res = i
        return res