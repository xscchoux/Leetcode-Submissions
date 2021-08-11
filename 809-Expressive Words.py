class Solution(object):
    def expressiveWords(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: int
        """
        
        def isStrechy(s, word):
            sIdx = wIdx = 0
            
            while sIdx < len(s) and wIdx < len(word):
                
                sCount = wCount = 0
                
                sWord, wWord = s[sIdx], word[wIdx]
                if sWord != wWord:
                    return False
                
                while sIdx < len(s) and s[sIdx] == sWord:
                    sCount += 1
                    sIdx += 1
                
                while wIdx < len(word) and word[wIdx] == wWord:
                    wCount += 1
                    if wCount > sCount:
                        return False
                    wIdx += 1
                    
                if sCount < 3 and sCount > wCount:
                    return False
                
            if sIdx < len(s) or wIdx < len(word):
                return False
            
            return True
        
        res = 0
        for word in words:
            if isStrechy(s, word):
                res += 1
        
        return res