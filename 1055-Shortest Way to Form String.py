from bisect import bisect_left
class Solution(object):
    def shortestWay(self, source, target):
        """
        :type source: str
        :type target: str
        :rtype: int
        """
        hmap = collections.defaultdict(list)
        
        for i, c in enumerate(source):
            hmap[c].append(i)
        
        j = 0 # index in source
        res = 0
        
        for char in target:
            if char not in hmap:
                return -1
            idx = bisect_left(hmap[char], j)
            if idx == len(hmap[char]):
                res += 1
                idx = 0
            j = hmap[char][idx] + 1
            
        return res+1