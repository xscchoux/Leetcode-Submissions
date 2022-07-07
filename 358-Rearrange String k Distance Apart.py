from heapq import heappush, heappop
class Solution(object):
    def rearrangeString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # very annoying edge case
        if k == 0:
            return s
        
        hmap = collections.Counter(s)
        pq = []
        
        for key, val in hmap.items():
            heappush(pq, (-val, key))
        
        s_remain = len(s)
        res = []
        
        while pq:
            tmp = []
            # should not have duplicate characters in the last chunk
            if len(pq) < k and pq[0][0] < -1:
                return ""
            
            n = min(k, s_remain)
            for i in range(n):
                num, char = heappop(pq)
                res.append(char)
                if num < -1:
                    tmp.append((num+1, char))

            s_remain -= n
            for x in tmp:
                heappush(pq, x)

        return "".join(res)