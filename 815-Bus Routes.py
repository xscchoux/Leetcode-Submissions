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