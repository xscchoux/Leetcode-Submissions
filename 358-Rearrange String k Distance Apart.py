# priority queue, O((N+U)logU), N is the length of the string s, and U is the number of unique characters in the string s
from heapq import *
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        # priority queue
        if k <= 1:
            return s
        count = Counter(s)
        pq = []

        # O(UlogU)
        for key, val in count.items():
            heappush(pq, (-val, key))
        
        res = []

        # O(NlogU)
        while pq:
            if len(pq) < k and -pq[0][0] > 1:
                return ""
            
            tmp = []
            for _ in range(min(k, len(pq))):
                tmp.append(heappop(pq))
            
            for cnt, key in tmp:
                res.append(key)
                if cnt + 1 != 0:
                    heappush(pq, (cnt+1, key))
                
        return "".join(res)
        
        
# O(n) solution, hard but brilliant, check the detailed solution in Leetcode
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        maxFreq = 0
        hmap = defaultdict(int)
        for c in s:
            hmap[c] += 1
            maxFreq = max(maxFreq, hmap[c])

        mostFrequent = set()
        secondFrequent = set()
        
        for key, val in hmap.items():
            if hmap[key] == maxFreq:
                mostFrequent.add(key)
            elif hmap[key] == maxFreq-1:
                secondFrequent.add(key)
        
        res = [[] for _ in range(maxFreq)]
        
        for key in mostFrequent:
            for i in range(maxFreq):
                res[i].append(key)
        
        for key in secondFrequent:
            for i in range(maxFreq-1):
                res[i].append(key)
        
        # round-robin
        idx = 0
        for key in hmap:
            if key not in mostFrequent and key not in secondFrequent:
                for _ in range(hmap[key]):
                    res[idx].append(key)
                    idx = (idx + 1)%(maxFreq-1)

        for x in res[:-1]:
            if len(x) < k:
                return ""
        
        return "".join(map(lambda x:"".join(x), res))