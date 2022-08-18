class Solution:
    def maxScore(self, edges: List[List[int]]) -> int:
        hmap = collections.defaultdict(list)
        
        for i, (start, w) in enumerate(edges):
            if start >= 0:
                hmap[start].append((i, w))
                
        @cache
        def dfs(node):
            if not hmap[node]:
                return 0, 0
            
            node_unused = 0
            
            for end, weight in hmap[node]:
                node_unused += max(dfs(end))
            
            node_used = 0
            for end, weight in hmap[node]:
                node_used = max(node_used, node_unused + max(edges[end][1],0) - max(dfs(end)) + dfs(end)[1])
            
            return node_used, node_unused

        return max(dfs(0))