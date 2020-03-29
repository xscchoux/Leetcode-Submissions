from collections import Counter
class Solution(object):
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        counter = Counter(s)
        odd = ''
        even = ''
        for key in counter:
            if counter[key]%2 == 1:
                odd+=key
            for _ in range(counter[key]//2):
                even+=key
        
        if len(odd)>1:
            return []
        
        n = len(even)
        visited = [False]*n
        res = []
        
        def permute(val):
            if len(val) == n:
                res.append(val + odd + val[::-1])
                return
            
            for i in range(n):
                if i>0 and even[i] == even[i-1] and visited[i-1] == False:
                    continue
                if visited[i] is False:
                    visited[i] = True
                    permute(val+even[i])
                    visited[i] = False
        permute("")
            
        return res