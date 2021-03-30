class Solution(object):
    def encode(self, num):
        """
        :type num: int
        :rtype: str
        """  
        if num == 0:
            return ""
        
        res = ""
        length = 1
        num-=1

        while num >= (1<<length):
            num -= (1<<length)
            length += 1
            
        for i in range(length):
            if num&1:
                res = "1" + res
            else:
                res = "0" + res
            num >>= 1
        
        return res