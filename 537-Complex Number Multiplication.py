class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        a, b = num1[:-1].split("+")
        c, d = num2[:-1].split("+")
        
        reala = int(a)
        realc = int(c)
        realb = int(b)
        reald = int(d)
        
        return str(reala*realc-realb*reald) + "+" + str(reala*reald + realc*realb) + "i"
    