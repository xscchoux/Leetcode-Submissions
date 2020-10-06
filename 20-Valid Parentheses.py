class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        hmap = {"(":")", "[":"]", "{":"}"}
        
        stack = []
        for char in s:
            if char in hmap:
                stack.append(char)
            elif stack and char == hmap[stack[-1]]:
                stack.pop()
            else:
                return False
        
        return not stack