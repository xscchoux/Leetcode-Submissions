class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        GCD = math.gcd(targetX, targetY)
        
        if GCD == 1:
            return True
        
        if (GCD-1)&GCD == 0:
            return True
        
        return False