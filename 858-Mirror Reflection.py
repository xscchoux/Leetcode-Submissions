class Solution(object):
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        currX, currY = p, q
        yDir = 1
        
        while True:
            if currX == p and currY == 0:
                return 0
            elif currX == p and currY == p:
                return 1
            elif currX == 0 and currY == p:
                return 2
            else:
                currX = 0 if currX == p else p
                currY += yDir*q
                if currY > p:
                    diff = currY-p
                    currY = p-diff
                    yDir *= -1
                elif currY < p:
                    diff = 0-currY
                    currY = diff
                    yDir *= -1