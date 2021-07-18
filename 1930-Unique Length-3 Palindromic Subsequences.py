class Solution(object):
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
# sol1
        left, right = [0]*26, [0]*26
        left[ord(s[0])-ord('a')] = 1
        
        for i in range(2, len(s)):
            right[ord(s[i])-ord('a')] += 1
            
        res = set()
        
        for i in range(1, len(s)-1):
            for j in range(26):
                if left[j] and right[j]:
                    res.add(j*26+ord(s[i])-ord('a'))
            left[ord(s[i])-ord('a')] += 1
            right[ord(s[i+1])-ord('a')] -= 1
            
        return len(res)

#sol2
        indexMap = collections.defaultdict(list)
        for i in range(len(s)):
            indexMap[s[i]].append(i)
        res = 0
        for key in indexMap.keys():
            if len(indexMap[key]) >= 2:
                first = indexMap[key][0]
                last = indexMap[key][-1]
                res += len(set(s[first+1:last]))
        
        return res