class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        queue = deque([])
        res = "1"*len(s)
        minLength = float('inf')
        
        for i, c in enumerate(s):
            if c == "1":
                queue.append(i)
            if len(queue) == k:
                length = queue[-1] - queue[0]+1
                if length < minLength:
                    res = s[queue[0]:queue[0]+length]
                    minLength = length
                elif length == minLength:
                    if res > s[queue[0]:queue[0]+length]:
                        res = s[queue[0]:queue[0]+length]
                    
                queue.popleft()
        
        return res if minLength < float('inf') else ""