class Solution(object):
    def removeDuplicates(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        stack = []
        for i in range(len(s)):
            if not stack or s[i] != stack[-1][0]:
                stack.append([s[i], 1])
            else:
                if stack[-1][1] + 1 == k:
                    stack.pop()
                else:
                    stack[-1][1] += 1
        
        res = ""
        for x in stack:
            res += x[1]*x[0]
        return res