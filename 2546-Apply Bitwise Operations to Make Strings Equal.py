class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
# (0, 0) -> (0, 0)
# (1, 0) -> (1, 1)
# (0, 1) -> (1, 1)
# (1, 1) -> (1, 0)
        t_one = target.count("1")
        s_one = s.count("1")
        if t_one == 0 and s_one == 0:
            return True
        elif t_one == 0 or s_one == 0:
            return False
        else:
            return True
        
# another
         return ('1' in s) == ('1' in t)