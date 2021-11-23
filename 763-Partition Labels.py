class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        last = dict()
        
        for ind, val in enumerate(s):
            last[val] = ind
        
        anchor = 0
        j = 0
        res = []
        for i, val in enumerate(s):
            j = max(j, last[val])
            if i == j:
                res.append(i-anchor+1)
                anchor = i+1
                    
        return res