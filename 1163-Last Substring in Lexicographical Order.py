from collections import defaultdict
class Solution(object):
    def lastSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxChar = max(s)
        charSet = {i for i in range(len(s)) if s[i] == maxChar}
        length = 0
        
        while len(charSet) > 1:
            nextCharSet = defaultdict(set)
            for index in charSet:
                if index == len(s) - 1:
                    continue
                if index - length - 1 in charSet:
                    continue
                nextCharSet[s[index+1]].add(index+1)
            charSet = nextCharSet[max(nextCharSet.keys())]
            length+=1
        
        return s[charSet.pop() - length:]