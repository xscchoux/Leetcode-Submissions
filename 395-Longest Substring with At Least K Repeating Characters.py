from collections import Counter
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
# Divide and Conquer
# Time: O(26) = O(n)
        count = Counter(s)
        for c in set(s):
            if count[c] < k:
                return max(self.longestSubstring(sub,k) for sub in s.split(c))
        return len(s)
        
        
# Sliding Window
# Time: O(26n) = O(n)

        if not s:
            return 0
        res = 0
        
        for l in range(1, min(len(s)+1,27)):
            hmap = dict()
            left = 0
            for i in range(len(s)):
                hmap[s[i]] = hmap.get(s[i], 0) + 1
                while len(hmap) > l:
                    hmap[s[left]] -= 1
                    if hmap[s[left]] == 0:
                        del hmap[s[left]]
                    left += 1
                    
                if len(hmap) == l:
                    isSub = True
                    for key in hmap.keys():
                        if hmap[key] < k:
                            isSub = False
                            break
                    if isSub:
                        res = max(res, i-left+1)
        
        return res