class Solution(object):
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        currR = currC = 0
        currDir = 0
        
        for instruction in instructions:
            if instruction == "G":
                dr, dc = directions[currDir]
                currR += dr
                currC += dc
            elif instruction == "L":
                currDir = (currDir+1)%4
            else:
                currDir = (currDir-1)%4
                
        if (currR == 0 and currC == 0) or currDir != 0:
            return True
        else:
            return False