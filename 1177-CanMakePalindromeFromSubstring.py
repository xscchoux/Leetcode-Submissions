from collections import Counter
class Solution(object):
    def canMakePaliQueries(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
# straightforward method, TLE
#         res = []
        
#         for start, end, replace in queries:
#             substring = s[start:end+1]
#             count = self.makePalindrome(substring)
#             count = count//2
#             if count<=replace:
#                 res.append(True)
#             else:
#                 res.append(False)
#         return res
                
#     def makePalindrome(self, substring):
#         hmap = Counter(substring)
#         count = 0
#         for key in hmap:
#             if hmap[key]%2 == 1:
#                 count+=1
#         return count

        res = []
        pre = [[True]*26]
        for idx, val in enumerate(s):
            tmp = pre[-1][:]
            tmp[ord(val)-ord('a')]^=True
            pre.append(tmp)
        for l, r, replace in queries:
            res.append( replace>=sum((pre[r+1][i]-pre[l][i])%2 == 1 for i in range(26))//2 )
        return res