class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
# Stack, Time:O(n), Space:O(n)
        stack = [-1]
        res = 0
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    res = max(res, i-stack[-1])
        
        return res
        
# Time:O(n), Space:O(1)
        left, right = 0, 0
        res = 0
        for i in range(len(s)):
            if s[i] == "(":
                left += 1
            else:
                right += 1
            
            if left == right:
                res = max(res, left*2)
            elif right > left:
                left = 0
                right = 0
                
        left, right = 0, 0
        for i in range(len(s)-1, -1, -1):
            if s[i] == ")":
                right += 1
            else:
                left += 1
            
            if left == right:
                res = max(res, left*2)
            elif left > right:
                left = 0
                right = 0
        
        return res