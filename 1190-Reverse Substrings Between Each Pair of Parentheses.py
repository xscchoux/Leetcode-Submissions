class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
# My solution
        def dfs(ind):
            string = ""
            while ind < len(s):
                if s[ind] == "(":
                    ind, nxt = dfs(ind+1)
                    string  += nxt[::-1]
                elif s[ind] == ")":
                    return ind+1, string
                else:
                    string += s[ind]
                    ind += 1
            return ind+1, string        
        return dfs(0)[1]

# stack, kind of tricky
        stack = ['']
    
        for c in s:
            if c == "(":
                stack.append('')
            elif c == ")":
                stack[len(stack)-2] += stack.pop()[::-1]
            else:
                stack[-1] += c
        
        return "".join(stack)