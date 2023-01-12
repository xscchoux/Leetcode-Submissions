class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:        
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        res = [0]*n
        
        def dfs(node, parent):    
            arr = [0]*26
            for nxt in graph[node]:
                if nxt == parent:
                    continue
                vector = dfs(nxt, node)
                for i in range(len(vector)):
                    arr[i] += vector[i]
            arr[ord(labels[node])-ord('a')] += 1
            res[node] = arr[ord(labels[node])-ord('a')]
            return arr
        
        dfs(0, -1)
        return res