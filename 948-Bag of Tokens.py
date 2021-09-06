class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        """
        :type tokens: List[int]
        :type power: int
        :rtype: int
        """
        if not tokens:
            return 0
        
        left, right = 0, len(tokens)-1
        res = 0
        tokens.sort()
        
        while left <= right and power >= tokens[left]:
            power -= tokens[left]
            res += 1
            left += 1
        
        while res > 0 and left < right:
            power += tokens[right]
            res -= 1
            right -= 1
            while left <= right and power >= tokens[left]:
                power-=tokens[left]
                res += 1
                left += 1
        
        return res