class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        charArr = [0, 0, 0]
        left = 0
        res = 0
        for i in range(N):
            charArr[ord(s[i])-ord('a')] += 1
            while all(charArr):
                res += N-i
                charArr[ord(s[left])-ord('a')] -= 1
                left += 1
        return res