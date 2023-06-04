# stack, O(N)
class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        for c in expression[::-1]:
            if stack and stack[-1] == "?":
                stack.pop()
                onTrue = stack.pop()
                stack.pop()
                onFalse = stack.pop()
                stack.append(onTrue if c == "T" else onFalse)
            else:
                stack.append(c)
        return stack[0]


# contruct a binary tree
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def parseTernary(self, expression: str) -> str:
        self.index = 0
        
        def constructTree(expression):
            root = Node(expression[self.index])
            if self.index == len(expression) - 1:
                return root
            
            self.index += 1
            if expression[self.index] == "?":
                self.index += 1
                root.left = constructTree(expression)
                self.index += 1
                root.right = constructTree(expression)
            
            return root
        
        head = constructTree(expression)

        while head.left and head.right:
            if head.val == "T":
                head = head.left
            else:
                head = head.right
                
        return head.val

# DFS, O(N)
class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        hmap = dict()  # index of ? and index of its corresponding :
        
        for i, val in enumerate(expression):
            if val == "?":
                stack.append(i)
            elif val == ":":
                hmap[stack.pop()] = i
                
        def dfs(start, end):
            if end - start + 1 < 5:
                return expression[start]
            boolean = expression[start]
            colonIdx = hmap[start+1]
            if boolean == "T":
                return dfs(start+2, colonIdx-1)
            else:
                return dfs(colonIdx+1, end)
            
        return dfs(0, len(expression)-1)
        