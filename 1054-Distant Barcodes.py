class Solution(object):
    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """

# O(nlogn)
        N = len(barcodes)
        res = [0]*N
        ind = 0
        
        count = collections.Counter(barcodes)
        for code in sorted(count.keys(), key = lambda x: -count[x]):
            for _ in range(count[code]):
                res[ind] = code
                ind += 2
                if ind >= N:
                    ind = 1
                    
        return res