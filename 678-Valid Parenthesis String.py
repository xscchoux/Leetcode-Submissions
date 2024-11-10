class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
# https://www.youtube.com/watch?v=h9Y3i7hhCpo
# O(n)
        min_op, max_op = 0, 0
        for c in s:
            if c == '(':
                min_op += 1
            else:
                min_op -= 1
            
            if c != ')':
                max_op += 1
            else:
                max_op -= 1
            
            if max_op < 0:
                return False
            if min_op < 0:
                min_op = 0
        
        return min_op == 0


# Use two stacks
class Solution:
    def checkValidString(self, s: str) -> bool:
        left = []
        star = []
        for i, c in enumerate(s):
            if c == "(":
                left.append(i)
            elif c == "*":
                star.append(i)
            else:
                if left:
                    left.pop()
                elif star:
                    star.pop()
                else:
                    return False
        
        while left:
            if star and left.pop() < star.pop():
                continue
            return False
        
        return True


# costant space
class Solution:
    def checkValidString(self, s: str) -> bool:
        openParen = closeParen = 0 # maximum number of left parantheses and right parantheses 
        N = len(s)
        for i in range(N):
            if s[i] in ("(", "*"):
                openParen += 1
            else:
                openParen -= 1
            
            if s[N-i-1] in (")", "*"):
                closeParen += 1
            else:
                closeParen -= 1
            
            if openParen < 0 or closeParen < 0:
                return False
        
        return True