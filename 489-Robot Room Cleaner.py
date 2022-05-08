# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot(object):
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution(object):
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        direction = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        visited = set()
        
        def dfs(currR, currC, k):
            robot.clean()
            visited.add((currR, currC))
            for _ in range(4):
                nxtR, nxtC = currR + direction[k][0], currC + direction[k][1]
                if (nxtR, nxtC) not in visited and robot.move():
                    dfs(nxtR, nxtC, k)
                    robot.turnRight()
                    robot.turnRight()
                    robot.move()
                    robot.turnRight()
                    robot.turnRight()
                    
                k = (k+1)%4
                robot.turnRight()
                
        dfs(0, 0, 0)