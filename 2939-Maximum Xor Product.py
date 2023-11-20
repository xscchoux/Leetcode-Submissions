class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        kMod = 10**9+7
        for i in range(n-1, -1, -1):
            bit = 1 << i
            if a & bit == 0 and b & bit == 0:
                a^=bit
                b^=bit
            elif a & bit == 0 or b & bit == 0:
                a &= ~bit    # clear the ith bit of a
                b &= ~bit    # clear the ith bit of b
                if a >= b:   # choose to put the ith bit in a or in b. If a is larger, put in b
                    b |= bit
                else:
                    a |= bit
        
        return (a%kMod)*(b%kMod)%kMod