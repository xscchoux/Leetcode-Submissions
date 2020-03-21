class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows<=1:
            return s
        
        res = ['']*numRows
        step = 1
        index = 0
        currRow = 0
        
        while index < len(s):
            res[currRow]+=s[index]
            index+=1
            if (currRow + step) == numRows or (currRow + step) == -1:
                step = -1*step
            currRow += step
            
        return "".join(res)