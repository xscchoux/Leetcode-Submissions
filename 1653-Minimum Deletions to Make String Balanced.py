class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        cur = res = s.count('a')
        for char in s:
            if char == 'a':
                cur -= 1
            else:
                cur += 1
            res = min(cur, res)
            
        return res