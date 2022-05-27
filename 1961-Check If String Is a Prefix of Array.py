class Solution(object):
    def isPrefixString(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: bool
        """
        ind = 0
        
        for word in words:
            if s[ind: ind+len(word)] != word:
                return False
            else:
                ind += len(word)
                if ind == len(s):
                    return True