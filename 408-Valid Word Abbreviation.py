class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        i1 = i2 = 0
        wordLen = len(word)
        abbrLen = len(abbr)
        
        while i1 < wordLen and i2 < abbrLen:
            if abbr[i2].isdigit():
                if int(abbr[i2]) == 0:
                    return False
                num = 0
                while i2 < abbrLen and abbr[i2].isdigit():
                    num = 10*num + int(abbr[i2])
                    i2+=1
                i1+=num
                
            else:
                if abbr[i2] != word[i1]:
                    return False
                i1+=1
                i2+=1
                
        return i1 == wordLen and i2 == abbrLen