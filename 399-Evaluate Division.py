
# solution 1 : DFS, O(E + Q*E)

from collections import defaultdict
class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        
        graph = defaultdict(list)
        weight = dict()
        
        for equation, value in zip(equations, values):
            graph[equation[0]].append(equation[1])
            graph[equation[1]].append(equation[0])
            weight[(equation[0], equation[1])] = value
            weight[(equation[1], equation[0])] = 1 / value
        
        
        def dfs(start, end, val, visited):
            if start not in graph.keys() or end not in graph.keys():
                return -1.0
            if start == end:
                return val
            visited.add(start)
            
            for child in graph[start]:
                if child not in visited:
                    res = dfs(child, end, val*weight[(start, child)], visited)
                    if res != -1:
                        return res
            return -1.0
            
        res = []        
        for query in queries:
            res.append(dfs(query[0], query[1], 1.0, set()))
            
        return res


# Solution2 Union-Find, O(E+Q)

class Solution(object):
    def find(self, point):
# withou path compression
        # value = self.value[point]
        # while self.parent[point] != point:
        #     point = self.parent[point]
        #     value *= self.value[point]
        # return point, value
# with path compression
        if self.parent[point] != point:
            self.parent[point], val = self.find(self.parent[point])
            self.value[point] *= val
        return self.parent[point], self.value[point]
    
    
    def union(self, pointA, pointB, val):
        parentA, valueA = self.find(pointA)
        parentB, valueB = self.find(pointB)
        if parentA == parentB:
            return
        self.parent[parentA] = self.parent[parentB]
        self.value[parentA] = valueB*val/valueA
        
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        alphabet = set(sum(equations, []))
        self.parent = {char:char for char in alphabet}
        self.value = {char:1.0 for char in alphabet}
        
# union all equations and values
        for (child, parent), value in zip(equations, values):
            self.union(child, parent, value)
        
        res = []
        for y, x in queries:
            if y not in alphabet or x not in alphabet:
                res.append(-1.0)
                continue
            parentY, valueY = self.find(y)
            parentX, valueX = self.find(x)
            if parentY != parentX:
                res.append(-1.0)
            else:
                res.append(valueY/valueX)
                
        return res
