from bisect import bisect_right
from sortedcontainers import SortedList
class Solution(object):
    def countRectangles(self, rectangles, points):
        """
        :type rectangles: List[List[int]]
        :type points: List[List[int]]
        :rtype: List[int]
        """
        hmap = collections.defaultdict(list)
        res = []
        
        for w, h in rectangles:
            hmap[h].append(w)
        for k in hmap.keys():
            hmap[k].sort()
        
        keys = sorted(hmap.keys())
        
        for w, h in points:
            index = bisect_left(keys, h)
            if index == len(keys):
                res.append(0)
                continue
            tot = 0
            for i in range(index, len(keys)):
                subList = hmap[keys[i]]
                if subList[-1] < w:
                    continue
                tot += len(subList) - bisect_right(subList, w-1)
            res.append(tot)
            
        return res