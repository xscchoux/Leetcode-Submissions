class Solution(object):
    def removeOccurrences(self, s, part):
        """
        :type s: str
        :type part: str
        :rtype: str
        """
# replace, O(len(s)*len(pattern))
        
        while part in s:
            s = s.replace(part, "", 1)
            
        return s
        
        
        
# stack, O(len(s)*len(pattern))
        N = len(part)
        
        stack = []
        for letter in s:
            stack.append(letter)
            Nstack = len(stack)

            if Nstack >= N and part == "".join(stack[-N:]):
                for _ in range(N):
                    stack.pop()
        
        return "".join(stack)