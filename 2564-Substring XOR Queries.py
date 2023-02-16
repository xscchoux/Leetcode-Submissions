class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        hmap = collections.defaultdict(lambda:[-1, -1])
        for i in range(len(s)):
            if s[i] == "1":
                val = 0
                for j in range(i, min(len(s), i+30)):
                    val *= 2
                    if s[j] == "1":
                        val = val^1
                    if val not in hmap:
                        hmap[val] = [i, j]
            else:
                if 0 not in hmap:
                    hmap[0] = [i, i]

        res = []
        for u, v in queries:
            res.append(hmap[u^v])
        
        return res