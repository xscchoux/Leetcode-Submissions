class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        indexA, indexB = len(a)-1, len(b)-1

        carry = 0
        res = ""
        
        while indexA >= 0 or indexB >= 0:
            if indexA >= 0:
                if a[indexA] == "1":
                    carry += 1
                indexA -= 1
            
            if indexB >= 0:
                if b[indexB] == "1":
                    carry += 1
                indexB -= 1
                
            res = str(carry%2) + res
            carry //= 2
        
        if carry:
            res = "1" + res
        
        return res