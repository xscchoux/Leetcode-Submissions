class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        
# time complexity: O(len(s)*len(d))
        def isSub(A, B):
            j = 0
            for a in A:
                if a == B[j]:
                    j += 1
                    if j == len(B):
                        break
            return j == len(B)
        
        res = ''
        for string in d:
            if isSub(s, string):
                if len(string) > len(res) or (len(string) == len(res) and string < res):
                    res = string

        return res