class Solution(object):
    def reverseWords(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        N = len(s)
        s[:] = s[::-1]
        start = 0
        
        for end in range(N):
            if s[end] == " ":
                s[start:end] = s[start:end][::-1]
                start = end + 1
        
        s[start:N] = s[start:N][::-1]