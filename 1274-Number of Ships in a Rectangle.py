# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Sea(object):
#    def hasShips(self, topRight, bottomLeft):
#        """
#        :type topRight: Point
#		 :type bottomLeft: Point
#        :rtype bool
#        """
#
#class Point(object):
#	def __init__(self, x, y):
#		self.x = x
#		self.y = y

class Solution(object):
    def countShips(self, sea, topRight, bottomLeft):
        """
        :type sea: Sea
        :type topRight: Point
        :type bottomLeft: Point
        :rtype: integer
        """
        x2, y2 = topRight.x, topRight.y
        x1, y1 = bottomLeft.x, bottomLeft.y
        
        if x1==x2 and y1==y2:
            return sea.hasShips(topRight, bottomLeft)
        
        x3 = x1 + (x2-x1)//2
        y3 = y1 + (y2-y1)//2
        
        # If topRight and bottomLeft give a line, it cannot be divided into 4 parts
        # Therefore, we need inequalities like x3>=x1 to see if there's a need to divide&conquer
        
        a = b = c = d = 0
        if x3>=x1 and y3>=y1 and sea.hasShips(Point(x3, y3), bottomLeft):
            a = self.countShips(sea, Point(x3, y3), bottomLeft)
        if x2 >= x3+1 and y2 >= y3+1 and sea.hasShips(topRight, Point(x3+1, y3+1)):
            b = self.countShips(sea, topRight, Point(x3+1, y3+1))
        if x2 >= x3+1 and y3 >= y1 and sea.hasShips(Point(x2, y3), Point(x3+1, y1)):
            c = self.countShips(sea, Point(x2, y3), Point(x3+1, y1))
        if x3 >= x1 and y2 >= y3+1 and sea.hasShips(Point(x3, y2), Point(x1, y3+1)):
            d = self.countShips(sea, Point(x3, y2), Point(x1, y3+1))

        return a+b+c+d