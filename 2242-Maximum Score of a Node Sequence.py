class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            
        for k in graph.keys():
            graph[k] = sorted(graph[k], key = lambda x: -scores[x])[:3]
        
        res = -1
        for a, b in edges:
            score = scores[a] + scores[b]
            for na in graph[a]:
                for nb in graph[b]:
                    if na != b and nb != a and na != nb:
                        if scores[na] + scores[nb] + score > res:
                            res = scores[na] + scores[nb] + score
                        else:
                            break
        return res