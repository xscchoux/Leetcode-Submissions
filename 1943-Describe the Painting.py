class Solution(object):
    def splitPainting(self, segments):
        """
        :type segments: List[List[int]]
        :rtype: List[List[int]]
        """
        hmap = collections.defaultdict(int)
        
        for start, end, val in segments:
            hmap[start] += val
            hmap[end] -= val
        
        keys = sorted(hmap.keys())
        currVal = 0
        res = []
        for i in range(1, len(keys)):
            currVal+=hmap[keys[i-1]]
            if currVal != 0:
                res.append([keys[i-1], keys[i], currVal])
            
        return res