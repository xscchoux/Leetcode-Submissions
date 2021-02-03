class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        wordDict = dict()
        res = []
        
        def isPalindrome(word):
            left, right = 0, len(word)-1
            while left < right:
                if word[left] != word[right]:
                    return False
                left+=1
                right-=1
            return True
        
        
        for ind, word in enumerate(words):
            wordDict[word] = ind
            
        for index, word in enumerate(words):
            for split in range(len(word)+1):
                left, right = word[:split], word[split:]
                
                if isPalindrome(left):
                    revRight = right[::-1]
                    if revRight in wordDict and wordDict[revRight] != index:
                        res.append([wordDict[revRight],wordDict[word]])
                
                if len(right) > 0 and isPalindrome(right):
                    revLeft = left[::-1]
                    if revLeft in wordDict:
                        res.append([wordDict[word], wordDict[revLeft]])
        
        return res