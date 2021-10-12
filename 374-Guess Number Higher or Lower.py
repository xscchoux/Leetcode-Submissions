# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n+1
 
        while True:
            guessed = left + (right-left)//2
            res = guess(guessed)
            if res == -1:
                right = guessed
            elif res == 1:
                left = guessed
            else:
                return guessed