class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
        
# https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/discuss/3992969/JavaC%2B%2BPython-Math
# note the element with smallest frequency in k-subsequence

        count = Counter(s)
        kMod = 10**9 + 7
        
        if len(count) < k:
            return 0
        
        sortedArr = sorted(count.values(), reverse=True)
        final = sortedArr[k-1]
        p = 0
        res = 1
        
        for i in range(len(sortedArr)):
            if sortedArr[i] > final:
                res = res*sortedArr[i]%kMod
                k -= 1
            if sortedArr[i] == final:
                p += 1
            
        return comb(p, k)*res*pow(final, k, kMod)%kMod