class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        hmap = dict()
        left = 0
        res = 0
        for i in range(len(s)):
            hmap[s[i]] = hmap.get(s[i], 0) + 1
            while len(hmap) > 2:
                hmap[s[left]] -= 1
                if hmap[s[left]] == 0:
                    del hmap[s[left]]
                left += 1
            res = max(res, i-left+1)
        
        return res