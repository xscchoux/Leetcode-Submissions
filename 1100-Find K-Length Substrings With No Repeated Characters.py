class Solution(object):
    def numKLenSubstrNoRepeats(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
# brute force
#         if k > len(s):
#             return 0
#         res = 0
#         counter = [0]*26
#         for i in range(k):
#             counter[ord(s[i])-ord('a')] += 1
#         if all(counter[i] <= 1 for i in range(26)):
#             res += 1
        
#         for i in range(k, len(s)):
#             counter[ord(s[i]) - ord('a')] += 1
#             counter[ord(s[i-k]) - ord('a')] -= 1
#             if all(counter[i] <= 1 for i in range(26)):
#                 res += 1
                
#         return res
    
# sliding window
                
        i = j = 0
        res = 0
        counter = [0]*26
        
        while j < len(s):
            currIdx = ord(s[j]) - ord('a')
            counter[currIdx] += 1
            
            while counter[currIdx] > 1:
                counter[ord(s[i]) - ord('a')] -= 1
                i += 1
            
            if j - i + 1 == k:
                res += 1
                counter[ord(s[i]) - ord('a')] -= 1
                i += 1
                
            j += 1
        return res