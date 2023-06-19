class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        
        prev = chr(ord('a') - 1)
        length = 0
        count = 0
        res = 0
        
        for i in range(len(word)):
            if word[i] >= prev:
                count += (word[i] != prev)
                length += 1
            else:
                count = 1
                length = 1
            
            if count == 5:
                res = max(res, length)
            
            prev = word[i]
            
        return res