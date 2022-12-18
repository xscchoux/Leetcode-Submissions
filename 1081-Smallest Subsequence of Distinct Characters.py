class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = dict()
        
        for i, c in enumerate(s):
            last[c] = i
            
        stack = []
        used = set()
        
        for i, c in enumerate(s):
            if c in used:
                continue
            while stack and c < stack[-1] and i-1 < last[stack[-1]]:
                used.remove(stack.pop())
            stack.append(c)
            used.add(c)
        
        return "".join(stack)