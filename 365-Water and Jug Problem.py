class Solution(object):
    def canMeasureWater(self, jug1Capacity, jug2Capacity, targetCapacity):
        """
        :type jug1Capacity: int
        :type jug2Capacity: int
        :type targetCapacity: int
        :rtype: bool
        """
# Bézout’s identity
        x, y, z = jug1Capacity, jug2Capacity, targetCapacity
        
        if x + y < z:
            return False
        
        def gcd(a,b):
            if a == 0:
                return b
            a, b = b%a, a
            return gcd(a, b)
        
        return z%gcd(x,y) == 0