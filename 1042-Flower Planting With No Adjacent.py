from collections import defaultdict
class Solution(object):
    def gardenNoAdj(self, n, paths):
        """
        :type n: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        graph = defaultdict(list)
        
        for path in paths:
            graph[path[0]].append(path[1])
            graph[path[1]].append(path[0])
        
        plantColor = {i:0 for i in range(1,n+1)}
        
        for plant in graph:
            colors = set(range(1,5))
            for neighbor in graph[plant]:
                if plantColor[neighbor] != 0 and plantColor[neighbor] in colors:
                    colors.remove(plantColor[neighbor])
            plantColor[plant] = colors.pop()
        
        return [plantColor[x] if plantColor[x] != 0 else 1 for x in range(1, n+1)]