class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        currSize = 0
        for c in s:
            if c.isalpha():
                currSize += 1
            else:
                currSize *= int(c)
        
        for c in reversed(s):
            k = k%currSize
            if k == 0 and c.isalpha():
                return c
            
            if c.isalpha():
                currSize -= 1
            else:
                currSize = currSize//int(c)