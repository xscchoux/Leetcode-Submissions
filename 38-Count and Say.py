class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return "1"
        
        def say(num):
            string = str(num)
            count = 1
            res = ""
            for i in range(len(string)-1):
                if string[i] == string[i+1]:
                    count += 1
                else:
                    res += str(count) + string[i]
                    count = 1
            return res + str(count) + string[-1]        
        
        prev = "1"
        while n-1>0:
            res = say(prev)
            n-=1
            prev = res
        return res