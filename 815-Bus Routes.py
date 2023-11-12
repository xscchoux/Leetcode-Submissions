from collections import defaultdict, deque
class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        """
        :type routes: List[List[int]]
        :type source: int
        :type target: int
        :rtype: int
        """
        stopToRoute = defaultdict(list)
        for routeIdx, route in enumerate(routes):
            for stop in route:
                stopToRoute[stop] += [routeIdx]
        
        bus = 0
        queue = deque([(source, 0)])
        visitedRoute = set()
        
        while queue:
            currStop, count = queue.popleft()
            if currStop == target:
                return count
            for routeIdx in stopToRoute[currStop]:
                if routeIdx not in visitedRoute:
                    visitedRoute.add(routeIdx)
                    for nxtStop in routes[routeIdx]:
                        queue.append((nxtStop, count+1))
        
        return -1

# Use set
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        graph = defaultdict(set)
        
        for idx, route in enumerate(routes):
            for stop in route:
                graph[stop].add(idx)
            
        
        S = set([source])
        T = set([target])
        change = 0
        visited = set() # store the index in route
        
        while S and T:
            if S&T:
                return change
            if len(T) < len(S):
                S, T = T, S
            new_S = set()
            for s in S:
                for nxt_idx in graph[s]:
                    if nxt_idx not in visited:
                        visited.add(nxt_idx)
                        for nxt in routes[nxt_idx]:
                            new_S.add(nxt)
            S = new_S - S
            change += 1
        
        return -1