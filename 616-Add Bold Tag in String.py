class Solution(object):
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
# Time complexity: O(n*m*k)
# n: length of s
# m: m words in the dictionary
# k: max length of the words in the dictionary 
        n = len(s)
        inDict = [False]*n
        wordDict = {}
        
        for word in dict:
            wordDict[word[0]] = wordDict.get(word[0], []) + [word]
        
        for i in range(len(s)):
            if s[i] in wordDict:
                for string in wordDict[s[i]]:
                    if s[i:i+len(string)] == string:
                        inDict[i:i+len(string)] = [True]*len(string)
        
        res = []
        for i in range(n):
            if inDict[i] and (i==0 or not inDict[i-1]):
                res.append("<b>")
            elif not inDict[i] and (i>0 and inDict[i-1]):
                res.append("</b>")
            res.append(s[i])
        
        if inDict[-1]:
            res.append("</b>")
        
        return "".join(res)