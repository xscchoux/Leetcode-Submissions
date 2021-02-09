class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        parents = {i:i for i in range(1, len(edges)+1)}
        
        def find(node):
            path = []
            while node != parents[node]:
                path.append(node)
                node = parents[node]

            for n in path:
                parents[n] = node
            return node
        
        def union(node1, node2):
            parents[node1] = node2
        
        for edge in edges:
            parent1, parent2 = find(edge[0]), find(edge[1])
            if parent1 == parent2:
                return edge
            union(parent1, parent2)