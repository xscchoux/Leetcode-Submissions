class Solution(object):
    def decode(self, encoded):
        """
        :type encoded: List[int]
        :rtype: List[int]
        """
        tot = 0
        for i in range(1, len(encoded)+2):
            tot ^= i
        
        noHead = 0
        for i in range(1, len(encoded), 2):
            noHead ^= encoded[i]
        
        res = [tot^noHead]
        for i in range(len(encoded)):
            res.append(encoded[i]^res[-1])
        
        return res