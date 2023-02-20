class Solution:
    def minOperations(self, n: int) -> int:
# https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/discuss/3203775/Python-Beats-100-Bit-Explanation-%2B-Runtime!
        res = 0
        one = 0
        bits = bin(n)[2:]
        for i in range(len(bits)-1, -1, -1):
            if bits[i] == "1":
                one += 1
            else:
                if one == 1:
                    res += 1
                    one = 0
                elif one > 1:
                    res += 1
                    one = 1
        
        if one == 1:
            res += 1
        elif one > 1:
            res += 2
        
        return res