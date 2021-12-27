class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        remain = num
        bit = 1
        while remain:
            num ^= bit
            bit <<= 1
            remain >>= 1
            
        return num