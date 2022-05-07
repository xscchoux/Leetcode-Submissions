class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        isNeg = False
        if x < 0:
            isNeg = True
            x = abs(x)
        new = 0
        while x > 0:
            new = new*10 + x%10
            x = x//10

        if isNeg and new <= pow(2, 31):
            return -1*new
        elif not isNeg and new <= pow(2, 31) - 1:
            return new
        else:
            return 0