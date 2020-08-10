class Solution(object):
    def isValid(self, S):
        """
        :type S: str
        :rtype: bool
        """
        if len(S)%3 != 0:
            return False
        
        stack = []
        
        for ch in S:
            if ch == 'a':
                stack.append(ch)
            elif ch == 'b':
                if stack and stack[-1] == 'a':
                    stack.append(ch)
                else:
                    return False
            elif ch == 'c':
                if stack and stack[-2:] == ['a','b']:
                    stack.pop()
                    stack.pop()
                else:
                    return False
                
        return not stack