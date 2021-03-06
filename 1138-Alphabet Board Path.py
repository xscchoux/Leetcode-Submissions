class Solution(object):
    def alphabetBoardPath(self, target):
        """
        :type target: str
        :rtype: str
        """
        
        prevR, prevC = 0, 0
        res = []
        
        for char in target:
            currR, currC = divmod(ord(char)-ord('a'), 5)
            diffR, diffC = currR - prevR, currC - prevC
            # move left and up before right and down
            if diffC < 0:
                res += ["L"]*abs(diffC)
            if diffR < 0:
                res += ["U"]*abs(diffR)
            if diffC > 0:
                res += ["R"]*diffC
            if diffR > 0:
                res += ["D"]*diffR
                
            res += ["!"]
            prevR = currR
            prevC = currC
            
        return "".join(res)