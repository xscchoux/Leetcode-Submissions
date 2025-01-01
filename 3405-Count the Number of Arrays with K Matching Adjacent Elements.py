# https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6199469/python-combinatorics-explained/
# create an array of n-k elements without same adjacent values, and add remaining k elements:
# H(n-k, k) 
class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        kMod = pow(10, 9) + 7

        return m*pow(m-1, n-k-1, kMod)*comb(n-1, k)%kMod