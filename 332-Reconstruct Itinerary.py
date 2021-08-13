from collections import defaultdict
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        graph = defaultdict(list)
        tickets.sort()
        self.visited = defaultdict(list)
        self.flights = len(tickets)
        
        for start, end in tickets:
            graph[start].append(end)
            self.visited[start].append(False)
        res = []
        
        def backtracking(start, path):
            if len(path) == self.flights + 1:
                res[:] = path
                return True
            for ind, nxt in enumerate(graph[start]):
                if not self.visited[start][ind]:
                    self.visited[start][ind] = True
                    if backtracking(nxt, path+[nxt]):
                        return True
                    self.visited[start][ind] = False

            return False
        
        backtracking("JFK", ["JFK"])
        
        return res