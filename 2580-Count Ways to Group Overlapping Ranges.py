class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort(key = lambda x:x[1])
        stack = []
        group = 0
        
        for start, end in ranges:
            while stack and start <= stack[-1]:
                stack.pop()
                group -= 1
                
            group += 1
            stack.append(end)
            
        return pow(2, group, 1000000007)