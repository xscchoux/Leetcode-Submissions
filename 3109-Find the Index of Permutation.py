from sortedcontainers import SortedList
class Solution:
    def getPermutationIndex(self, perm: List[int]) -> int:
        kMod = 10**9+7
        N = len(perm)
        sl = SortedList(range(1, N+1))
        
        # https://leetcode.com/problems/find-the-index-of-permutation/solutions/5010313/python-sortedlist-easily-understood-solution/

        @cache
        def factorial(num):
            if num in (0, 1):
                return 1
            return num*factorial(num-1)%kMod
        
        res = 0
        
        for i in range(len(perm)):
            num = perm[i]
            index = sl.bisect_left(num)
            res = (res + index*factorial(N-i-1)%kMod)%kMod
            sl.discard(num)
        
        return res