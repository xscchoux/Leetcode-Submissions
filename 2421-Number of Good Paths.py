class Solution(object):
    def numberOfGoodPaths(self, vals, edges):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        res = 0
        parent = list(range(len(vals)))
        hmap = collections.defaultdict(set)
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            parent[pa] = pb
        
        val2index = collections.defaultdict(set)
        for ind, val in enumerate(vals):
            val2index[val].add(ind)
        
        nodes = list(val2index.items())
        nodes.sort()
        
        for s, e in edges:
            hmap[s].add(e)
            hmap[e].add(s)

        used = set()
        for value, ind in nodes:
            tmp = dict()
            for index in ind:
                for nxt in hmap[index]:
                    if nxt in used:
                        union(index, nxt)
                used.add(index)
            
            for index in ind:
                parentIdx = find(index)
                tmp[parentIdx] = tmp.get(parentIdx, 0) + 1
                
            for k, val in tmp.items():
                res += val*(val-1)//2
        
        return res + len(vals)