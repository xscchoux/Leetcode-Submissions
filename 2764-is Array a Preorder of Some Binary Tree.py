class Solution:
    def isPreorder(self, nodes: List[List[int]]) -> bool:
        # We simulate preorder stack, and return False if we cannot find a parent that should be there
        stack = []
        
        for i in range(len(nodes)):
            while stack and stack[-1][0] != nodes[i][1]:
                stack.pop()
            if nodes[i][1] != -1 and not stack:
                return False
            stack.append(nodes[i])
        
        return True