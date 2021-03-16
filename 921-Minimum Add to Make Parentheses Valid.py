class Solution(object):
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        redundant = 0
        stack = 0
        for s in S:
            if s == "(":
                stack += 1
            else:
                if stack:
                    stack-= 1
                else:
                    redundant += 1
        
        return stack + redundant