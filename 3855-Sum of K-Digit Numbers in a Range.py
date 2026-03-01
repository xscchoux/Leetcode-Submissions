kMod = 1000000007
class Solution:
    def sumOfNumbers(self, l: int, r: int, k: int) -> int:
        d = r-l+1
        res = 0
        C = (l+r)*(r-l+1)//2

        # A_k = 10^(k-1) * C    ----  sum the kth digit. For l = 1, r = 2, k = 2, A_2 = 30
        # A_k-1 = A_k * d + d * 10^(k-2) * C
        # A_k-2 = A_k-1 * d + d^2 * 10^(k-3) * C

        # A_1 = 10^(k-1) * d^(k-1) * C +  10^(k-2) * d^(k-1) * C +  10^(k-3) * d^(k-1) * C + ... + 1 * d^(k-1) * C 

        res = ((pow(10, k, kMod) - 1)*pow(9, -1, kMod)*pow(d, k-1, kMod)*C)%kMod

        return res