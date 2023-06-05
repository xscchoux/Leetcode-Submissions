class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        c0, c1 = coordinates[0], coordinates[1]
        deltaY = c1[1]-c0[1]
        deltaX = c1[0]-c0[0]
        
        for c in coordinates[2:]:
            if deltaX*(c[1] - c0[1]) != deltaY*(c[0] - c0[0]):
                return False
            
        return True