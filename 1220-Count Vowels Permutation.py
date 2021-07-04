class Solution(object):
    def countVowelPermutation(self, n):
        """
        :type n: int
        :rtype: int
        """
        aCount = eCount = iCount = oCount = uCount = 1
        kMod = 10**9 + 7
        
        for i in range(1, n):
            aCountNew = (iCount + eCount + uCount)%kMod
            eCountNew = (aCount + iCount)%kMod
            iCountNew = (eCount + oCount)%kMod
            oCountNew = iCount
            uCountNew = (iCount + oCount)%kMod
            
            aCount, eCount, iCount, oCount, uCount = aCountNew, eCountNew, iCountNew, oCountNew, uCountNew
            
        return (aCount+eCount+iCount+oCount+uCount)%kMod

# Recursive 
        hmap = {"a":["e"], "e":["a","i"], "i":["a","e","o","u"], "o":["i","u"], "u":["a"]}
        memo = dict()
        kMod = 10**9 + 7
        
        def dfs(currChar, remainNum):
            if remainNum == 0:
                return 1
            
            if (currChar, remainNum) in memo:
                return memo[(currChar, remainNum)]
            
            res = 0
            
            for char in hmap[currChar]:
                memo[(char, remainNum-1)] = dfs(char, remainNum-1)%kMod
                res += memo[(char, remainNum-1)]
            
            return res%kMod
        
        return (dfs("a",n-1) + dfs("e",n-1) + dfs("i",n-1) + dfs("o",n-1) + dfs("u",n-1))%kMod