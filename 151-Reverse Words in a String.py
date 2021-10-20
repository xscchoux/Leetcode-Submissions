class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
# use filter
        return " ".join(filter(lambda x: len(x.lstrip().rstrip()) > 0, s.split(" ") )[::-1] )
        
# another solution
        return " ".join(s.split()[::-1])