class Solution(object):
    def parseBoolExpr(self, expression):
        """
        :type expression: str
        :rtype: bool
        """
# Solution 1
        mapping = [['&','all'], ['|','any'], ['t','True'],['f','False'], ['(','(['], [')','])'], ['!','not any']]
        for m, v in mapping:
            expression = expression.replace(m, v)
        return eval(expression)        
                
# Solution 2 (two stacks)
        hmap = { "&" : all, "|" : any, "!" : lambda x: not x[0] }
    
        stack = []
        for c in expression:
            if c in hmap:
                stack.append(hmap[c])
            if c == "(":
                stack.append(c)
            elif c == "t":
                stack.append(True)
            elif c == "f":
                stack.append(False)
            elif c == ")":
                ss = []
                while stack[-1] != "(":
                    ss.append(stack.pop())
                stack.pop()
                stack.append(stack.pop()(ss))
        
        return stack.pop()