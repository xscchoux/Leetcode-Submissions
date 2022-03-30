class Solution(object):
    def longestRepeatingSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        def check(L):
            used = set()
            for i in range(0, len(s)-L+1):
                if s[i:i+L] in used:
                    return True
                used.add(s[i:i+L])
            return False
            
        left, right = 1, len(s)
        while left + 1 < right:
            mid = left + (right-left)//2
            if check(mid):
                left = mid
            else:
                right = mid
                
        if check(right):
            return right
        elif check(left):
            return left
        else:
            return 0