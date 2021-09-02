class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
# Divide and Conquer ,O(n^2)
        def find(start, end):
            res = 0
            bal = 0
            for i in range(start, end+1):
                if s[i] == "(":
                    bal += 1
                else:
                    bal -= 1
                
                if bal == 0:
                    if i-start == 1:
                        res += 1
                    else:
                        res += 2*find(start+1, i-1)
                    start = i+1
            return res
        
        return find(0, len(s)-1)
                    
# stack 
        stack = [0]
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(0)
            else:
                v = stack.pop()
                stack[-1] += max(2*v, 1)
        
        return stack.pop()
        
# count cores (a very special solution)
        bal = 0
        res = 0
        for i in range(len(s)):
            if s[i] == "(":
                bal += 1
            else:
                bal -= 1
                if s[i-1] == "(":
                    res += 1<<bal
        return res