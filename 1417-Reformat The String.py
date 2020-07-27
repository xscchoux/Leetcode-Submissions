class Solution(object):
    def reformat(self, s):
        """
        :type s: str
        :rtype: str
        """
        digit = []
        char = []
        for ss in s:
            if ss.isalpha():
                char.append(ss)
            else:
                digit.append(ss)
                
        if len(digit) > len(char) + 1 or len(char) > len(digit) + 1:
            return ""
        
        res = ""
        while digit and char:
            res += digit.pop() + char.pop()
        
        if char:
            res = char.pop() + res
        elif digit:
            res = res + digit.pop()
        
        return res