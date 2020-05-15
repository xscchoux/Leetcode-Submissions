from collections import defaultdict, deque
class Solution(object):
    def minJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """   
# BFS, O(n)
        hmap = defaultdict(set)
        for ind, val in enumerate(arr):
            hmap[val].add(ind)

        N = len(arr)
        queue = deque([(0,0)])
        seen = {-1,0,N}
        
        while queue:
            for _ in range(len(queue)):
                curr_idx, step = queue.popleft()
                if curr_idx == N-1:
                    return step

                if curr_idx-1 not in seen:
                    seen.add(curr_idx-1)
                    queue.append((curr_idx-1, step+1))
                    
                if curr_idx+1 not in seen:
                    seen.add(curr_idx+1)
                    queue.append((curr_idx+1, step+1))
                    
                for _next in hmap[arr[curr_idx]]:
                    if _next not in seen:
                        seen.add(_next)
                        queue.append((_next, step+1))
                # No need to examine nodes of the same value. Must add this line
                hmap[arr[curr_idx]] = set()
        return -1