from heapq import heappush, heappop
class Solution(object):
    def maxStarSum(self, vals, edges, k):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """
        hmap = collections.defaultdict(list)
        for u, v in edges:
            if vals[v] > 0:
                heappush(hmap[u], -vals[v])
            if vals[u] > 0:
                heappush(hmap[v], -vals[u])

        res = max(vals)
        for key, val in hmap.items():
            curr = vals[key]
            tmp = k
            while len(hmap[key]) > 0 and tmp > 0:
                curr -= heappop(hmap[key])
                tmp -= 1
            res = max(res, curr)
        
        return res