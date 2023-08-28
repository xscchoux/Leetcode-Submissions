class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        banned = set()
        curr = 1
        tot = 0
        
        for _ in range(n):
            while target - curr in banned:
                curr += 1
            tot += curr
            banned.add(curr)
            curr += 1
            
        return tot