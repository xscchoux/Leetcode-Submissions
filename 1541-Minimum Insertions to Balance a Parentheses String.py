class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        right = 0
        res = 0
        
        
        for i in range(len(s)):
            if s[i] == "(":
                if right == 1:
                    if left == 0:
                        res += 2
                    else:
                        left -= 1
                        res += 1
                    right = 0
                left += 1
            else:
                right += 1
                if right == 2:
                    if left == 0:
                        res += 1
                    else:
                        left -= 1 # add one left parentheses
                    right = 0
                    
        if right == 1:
            if left:
                res += 1
                left -= 1
            else:
                res += 2
                
        res += left*2
                        
        return res