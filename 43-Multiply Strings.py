class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        number1, number2 = 0, 0 
        
        for num in num1:
            number1 = number1*10 + ord(num) - ord('0')
        for num in num2:
            number2 = number2*10 + ord(num) - ord('0')
            
        return str(number1*number2)



class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        N1, N2 = len(num1), len(num2)
        res = [0]*(N1+N2)

        for i in range(0, N1):
            int1 = int(num1[N1-i-1])
            for j in range(0, N2):
                val = int1*int(num2[N2-j-1])
                tot = res[i+j] + val
                q, r = divmod(tot, 10)
                res[i+j] = r
                res[i+j+1] += q
        
        while len(res) > 1 and res[-1] == 0:
            res.pop()

        return "".join(map(str, res[::-1]))