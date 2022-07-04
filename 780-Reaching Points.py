class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        while tx >= sx and ty >= sy:
            if tx == sx and ty == sy:
                return True
            
            if sx == tx:
                return (ty - sy)%tx == 0
            if sy == ty:
                return (tx - sx)%ty == 0
            
            if ty > tx:
                ty = ty%tx  # tx > sx, need a smaller ty to remedy this
            elif tx > ty:
                tx = tx%ty
            else:
                return tx == sx and ty == sy
                
        return False