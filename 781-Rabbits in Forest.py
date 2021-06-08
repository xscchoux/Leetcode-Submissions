class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        count = collections.Counter(answers)
        res = 0
        
        for k, v in count.items():
            if not v%(k+1):
                res += v
            else:
                res += (v//(k+1)+1)*(k+1)
        
        return res