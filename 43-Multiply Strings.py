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