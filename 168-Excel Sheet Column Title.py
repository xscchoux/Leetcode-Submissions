class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        num = columnNumber
        res = []
        
        while num > 0:
            num -= 1
            res.append(chr(num%26 + ord('A')))
            num = num//26
        
        return "".join(res[::-1])