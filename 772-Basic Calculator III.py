class Solution:
    def calculate(self, s: str) -> int:
        N = len(s)       
        
        def cal(arr):
            op = "+"
            stack = []
            for i in range(len(arr)):
                if arr[i] in ("+", "-", "*", "/"):
                    op = arr[i]
                else:
                    if op == "+":
                        stack.append(arr[i])
                    elif op == "-":
                        stack.append(-arr[i])
                    elif op == "*":
                        stack.append(stack.pop()*arr[i])
                    else:
                        stack.append(int(stack.pop()/arr[i]))
            return sum(stack)

        
# This is what I wrote in cal() in first try
# If you don't know how to handle *, +, / and - together, you can just run two loops

#             i = 0
#             new = [] # handle 
#             while i < len(arr):
#                 if arr[i] == "*":
#                     prev = new.pop()
#                     i += 1
#                     new.append(prev*arr[i])
#                     i += 1
#                 elif arr[i] == "/":
#                     prev = new.pop()
#                     i += 1
#                     new.append(int(prev/arr[i]))
#                     i += 1
#                 else:
#                     new.append(arr[i])
#                     i += 1

#             res = 0
#             op = "+"
#             for i in range(len(new)):
#                 if new[i] in ("+", "-"):
#                     op = new[i]
#                 else:
#                     if op == "+":
#                         res = res + new[i]
#                     else:
#                         res = res - new[i]
#             return res
            
            
            
        def dfs(i):
            stack = []
            while i < N:
                if s[i].isdigit():
                    num = 0
                    while i < N and s[i].isdigit():
                        num = num*10 + int(s[i])
                        i+=1
                    stack.append(num)
                elif s[i] == "(":
                    idx, val = dfs(i+1)
                    i = idx
                    stack.append(val)
                elif s[i] == ")":
                    val = cal(stack)
                    return i+1, val
                else:
                    stack.append(s[i])
                    i += 1    
            return cal(stack)
        
        res = dfs(0)
        
        return res