class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        
# Time:O(n), Space:O(n)

        group = [1]
        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                group.append(1)
            else:
                group[-1] += 1
        
        res = 0
        
        for j in range(1, len(group)):
            res += min(group[j-1], group[j])
        
        return res
    
# Time:O(n), Space:O(1)

        prev, curr = 0, 1
        res = 0
        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                res += min(prev, curr)
                prev, curr = curr, 1
            else:
                curr += 1
        
        return res + min(prev, curr)