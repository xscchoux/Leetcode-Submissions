class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [0]
        
        for x in arr:
            prefix.append(x^prefix[-1])
        
        res = []
        for start, end in queries:
            res.append(prefix[start]^prefix[end+1])
            
        return res