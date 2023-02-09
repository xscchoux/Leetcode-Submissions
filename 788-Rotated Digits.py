class Solution:
    def rotatedDigits(self, n: int) -> int:
        s1 = set([0, 1, 8])
        s2 = set([0, 1, 2, 5, 6, 8, 9])
        tot = 0
        for c in range(1, n+1):
            nums = set(int(x) for x in str(c))
            if nums.issubset(s2) and not nums.issubset(s1):
                tot += 1
        
        return tot