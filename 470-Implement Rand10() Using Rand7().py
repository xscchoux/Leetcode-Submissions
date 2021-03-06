# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution(object):
    def rand10(self):
        """
        :rtype: int
        """
# solution 1, rejection sampling
        while True:
            res = (rand7()-1)*7 + rand7()
            if res <= 40:
                return res%10+1
        
# solution 2, optimized rejection sampling
        while True:
            rand49 = (rand7()-1)*7 + rand7()
            if rand49 <= 40:
                return rand49%10+1
            rand9 = rand49 - 40
            rand63 = (rand9-1)*7 + rand7()
            if rand63 <= 60:
                return rand63%10+1
            rand3 = rand63-60
            rand21 = (rand3-1)*7 + rand7()
            if rand21 <= 20:
                return rand21%10+1