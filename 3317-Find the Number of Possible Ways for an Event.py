# https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/solutions/5906374/simple-combinatorics-deduction/
# count(ballCount, binCount) = (binCount)^(ballCount) - sigma(i=1~(binCount-1))*comb(binCount, i)*count(ballCount, i)
kMod = 10**9+7
@cache
def fac(x):
    if x<=1:
        return 1
    else:
        return x*fac(x-1)%kMod

@cache
def combMod(a, b):
    return fac(a)*pow(fac(b), -1, kMod)*pow(fac(a-b), -1, kMod)%kMod

@cache
def count(ballCount, binCount):  # when there are `ballCount` balls and `binCount` available bins
    if binCount == 1:
        return 1
    res = pow(binCount, ballCount, kMod)
    for i in range(binCount-1, 0, -1):
        res -= combMod(binCount, i)*count(ballCount, i)%kMod
    return res%kMod  # this works even when res is negative in python

class Solution:
    def numberOfWays(self, n: int, x: int, y: int) -> int:
        kMod = 10**9+7
        res = 0
        for bins in range(1, x+1):
            res += combMod(x, bins)*count(n, bins)*pow(y, bins, kMod)
        return res%kMod